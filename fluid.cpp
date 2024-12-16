#include "Headers.h"
#include "data.cpp"




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


//template<int N, int M, typename T1, typename T2, typename T3>
//int fluid() {
    //Data<N, M, T1, T2, T3> tmp;

int main(){
    Data<N, M, double, float, double> tmp;

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
        
        Fixed<64, 32> total_delta_p = 0;
        // Apply external forces
        for (size_t x = 0; x < N; ++x) {
            for (size_t y = 0; y < M; ++y) {
                if (tmp.field[x][y] == '#')
                    continue;
                if (tmp.field[x + 1][y] != '#')
                    tmp.velocity.add(x, y, 1, 0, tmp.g);
            }
        }

        // Apply forces from p
        memcpy(tmp.old_p, tmp.p, sizeof(tmp.p));
        for (size_t x = 0; x < N; ++x) {
            for (size_t y = 0; y < M; ++y) {
                if (tmp.field[x][y] == '#')
                    continue;
                for (auto [dx, dy] : deltas) {
                    int nx = x + dx, ny = y + dy;
                    if (tmp.field[nx][ny] != '#' && tmp.old_p[nx][ny] < tmp.old_p[x][y]) {
                        auto delta_p = tmp.old_p[x][y] - tmp.old_p[nx][ny];
                        auto force = delta_p;
                        auto &contr = tmp.velocity.get(nx, ny, -dx, -dy);
                        if (contr * tmp.rho[(int) tmp.field[nx][ny]] >= force) {
                            contr -= force / tmp.rho[(int) tmp.field[nx][ny]];
                            continue;
                        }
                        force -= contr * tmp.rho[(int) tmp.field[nx][ny]];
                        contr = 0;
                        tmp.velocity.add(x, y, dx, dy, force / tmp.rho[(int) tmp.field[x][y]]);
                        tmp.p[x][y] -= force / tmp.dirs[x][y];
                        total_delta_p -= force / tmp.dirs[x][y];
                    }
                }
            }
        }

        // Make flow from velocities
        tmp.velocity_flow = {};
        bool prop = false;
        do {
            tmp.UT += 2;
            prop = 0;
            for (size_t x = 0; x < N; ++x) {
                for (size_t y = 0; y < M; ++y) {
                    if (tmp.field[x][y] != '#' && tmp.last_use[x][y] != tmp.UT) {
                        auto [t, local_prop, _] = tmp.propagate_flow(x, y, 1);
                        if (t > 0) {
                            prop = 1;
                        }
                    }
                }
            }
        } while (prop);

        // Recalculate p with kinetic energy
        for (size_t x = 0; x < N; ++x) {
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
            for (size_t x = 0; x < N; ++x) {
                cout << tmp.field[x] << "\n";
            }
        }
    }
}