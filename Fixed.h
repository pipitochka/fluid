//
// Created by Артем Акулов on 13.12.2024.
//

#ifndef FIXED_H
#define FIXED_H

using namespace std;
#include <type_traits>
#include <typeinfo>
#include <limits>

template <int N, int K>
class Fixed {
public:
    static_assert(N==8 || N == 16 || N == 32 || N == 64);
    using StorageType = typename std::conditional<N == 8, int8_t,
                        typename std::conditional<N == 16, int16_t,
                        typename std::conditional<N == 32, int32_t,
                        //typename std::conditional<N == 64, int64_t, int64_t>::type>::type>::type>::type;
                        typename std::conditional<N == 64, int64_t, void>::type>::type>::type>::type;

    StorageType v;
    constexpr Fixed(int v): v(v << K) {}
    constexpr Fixed(float f): v(f * (1 << K)) {}
    constexpr Fixed(double f): v(f * (1 << K)) {}
    constexpr Fixed(): v(0) {}

    static constexpr Fixed from_raw(int64_t x) {
        Fixed ret;
        ret.v = x;
        return ret;
    }

    //shows mistakes on mac os
    //auto operator<=>(const Fixed&) const = default;
    std::strong_ordering operator<=>(const Fixed&) const = default;
    bool operator==(const Fixed&) const = default;
};



#endif //FIXED_H
