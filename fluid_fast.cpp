#include "Headers.h"
#include "data_fast.cpp"
#include <functional>
#include <unordered_map>
#include <string>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <thread>
#include <atomic>


// char field[N][M + 1] = {
//     "#####",
//     "#.  #",
//     "#.# #",
//     "#.# #",
//     "#.# #",
//     "#.# #",
//     "#.# #",
//     "#.# #",
//     "#...#",
//     "#####",
//     "#   #",
//     "#   #",
//     "#   #",
//     "#####",
// };

constexpr size_t N = 36, M = 84;
// constexpr size_t N = 14, M = 5;
class FluidBase {
	public:
	virtual void fluid(size_t num_threads) = 0;
};

template<int N, int M, typename T1, typename T2, typename T3>
class Fluid: public FluidBase {
public:
    void fluid(size_t num_threads) override{
        Data<N, M, T1, T2, T3> tmp;
        auto start = std::chrono::high_resolution_clock::now();

        // void fluid(){
        //     Data<N, M, float, float, Fixed<32, 16>> tmp;

        constexpr size_t T = 1'000'000;
        using namespace std;

        tmp.rho[' '] = 0.01;
        tmp.rho['.'] = 1000;

        for (size_t x = 0; x < N; ++x) {
            for (size_t y = 0; y < M; ++y) {
                if (tmp.field[x][y] == '#')
                    continue;
                for (auto [dx, dy] : deltas) {
                    tmp.dirs[x][y] += (tmp.field[x + dx][y + dy] != '#');
                }
            }
        }

        for (size_t i = 0; i < T; ++i) {

            Fixed<64, 32, 1> total_delta_p = 0;

            std::vector<std::thread> threads;
            for (size_t t = 0; t < num_threads; ++t) {
                threads.emplace_back([&, t](){
                    for (size_t x = t; x < N; x+=num_threads) {
                        for (size_t y = t; y < M; y+=num_threads) {
                            if (tmp.field[x][y] == '#') {
                                continue;
                            }
                            else {
                                tmp.velocity.add(x, y, 1, 0, tmp.g);
                            }
                        }
                    }
                });
            }

            for (auto& t : threads) {
                t.join();
            }
            threads.clear();

            // Apply forces from p

            memcpy(tmp.old_p, tmp.p, sizeof(tmp.p));
            for (size_t t = 0; t < num_threads; ++t) {
                threads.emplace_back([&, t]() {
                    for (size_t x = t; x < N; x += num_threads) {
                        for (size_t y = 0; y < M; ++y) {
                            if (tmp.field[x][y] == '#')
                                continue;
                            for (auto [dx, dy] : deltas) {
                                int nx = x + dx, ny = y + dy;
                                if (tmp.field[nx][ny] != '#' && tmp.old_p[nx][ny] < tmp.old_p[x][y]) {
                                    auto delta_p = tmp.old_p[x][y] - tmp.old_p[nx][ny];
                                    auto force = delta_p;
                                    auto &contr = tmp.velocity.get(nx, ny, -dx, -dy);
                                    if (contr * tmp.rho[(int)tmp.field[nx][ny]] >= force) {
                                        contr -= force / tmp.rho[(int)tmp.field[nx][ny]];
                                        continue;
                                    }
                                    force -= contr * tmp.rho[(int)tmp.field[nx][ny]];
                                    contr = 0;
                                    tmp.velocity.add(x, y, dx, dy, force / tmp.rho[(int)tmp.field[x][y]]);
                                    tmp.p[x][y] -= force / tmp.dirs[x][y];
                                    total_delta_p -= force / tmp.dirs[x][y];
                                }
                            }
                        }
                    }
                });
            }

            for (auto &th : threads) {
                th.join();
            }
            threads.clear();

            // Make flow from velocities
            tmp.velocity_flow = {};
            atomic<bool> prop = false;
            do {
                tmp.UT += 2;
                prop = 0;
                for (size_t t = 0; t < num_threads; ++t) {
                    threads.emplace_back([&, t](){
                    for (size_t x = t; x < N; x+=num_threads) {
                        for (size_t y = 0; y < M; ++y) {
                            if (tmp.field[x][y] != '#' && tmp.last_use[x][y] != tmp.UT) {
                                auto [t, local_prop, _] = tmp.propagate_flow(x, y, 1);
                                if (t > 0) {
                                    prop = true;
                                }
                            }
                        }
                    }
                    });
                    for (auto &th : threads) {
                        th.join();
                    }
                    threads.clear();
                }
            } while (prop);



            // Recalculate p with kinetic energy
            for (size_t t = 0; t < num_threads; ++t) {
                threads.emplace_back([&, t](){
                for (size_t x = t; x < N; x+=num_threads) {
                    for (size_t y = 0; y < M; ++y) {
                        if (tmp.field[x][y] == '#')
                            continue;
                        for (auto [dx, dy] : deltas) {
                            auto old_v = tmp.velocity.get(x, y, dx, dy);
                            auto new_v = tmp.velocity_flow.get(x, y, dx, dy);
                            if (old_v > 0) {
                                assert(new_v <= old_v);
                                tmp.velocity.get(x, y, dx, dy) = new_v;
                                auto force = (old_v - new_v) * tmp.rho[(int) tmp.field[x][y]];
                                if (tmp.field[x][y] == '.')
                                    force *= 0.8;
                                if (tmp.field[x + dx][y + dy] == '#') {
                                    tmp.p[x][y] += force / tmp.dirs[x][y];
                                    total_delta_p += force / tmp.dirs[x][y];
                                } else {
                                    tmp.p[x + dx][y + dy] += force / tmp.dirs[x + dx][y + dy];
                                    total_delta_p += force / tmp.dirs[x + dx][y + dy];
                                }
                            }
                        }
                    }
                }
                });
            }

            for (auto &th : threads) {
                th.join();
            }
            threads.clear();

            tmp.UT += 2;
            prop = false;
            for (size_t x = 0; x < N; ++x) {
                for (size_t y = 0; y < M; ++y) {
                    if (tmp.field[x][y] != '#' && tmp.last_use[x][y] != tmp.UT) {
                        if (random01(tmp.p[0][0]) < tmp.move_prob(x, y)) {
                            prop = true;
                            tmp.propagate_move(x, y, true);
                        } else {
                            tmp.propagate_stop(x, y, true);
                        }
                    }
                }
            }

            if (prop) {
                cout << "Tick " << i << ":\n";
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = end - start;
                cout << "Время выполнения: " << elapsed.count() << endl;
                for (size_t x = 0; x < N; ++x) {
                    cout << tmp.field[x] << "\n";
                }
            }
        }
    }
};

class FluidFactory {
    using CreatorFunction = std::function<std::unique_ptr<FluidBase>()>;
public:
    std::unordered_map<std::string, CreatorFunction> creators;

	template <int N, int M, typename T1, typename T2, typename T3>
    void registerType(std::string name) {
        creators[name] = []() {
            return std::make_unique<Fluid<N, M, T1, T1, T2>>();
        };
    }

	std::unique_ptr<FluidBase> create(std::string name) const {
        auto it = creators.find(name);
        if (it != creators.end()) {
            return it->second();
        }
        throw std::runtime_error("Unknown Fixed type: " + name);
    }

};