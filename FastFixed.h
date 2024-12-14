//
// Created by Артем Акулов on 14.12.2024.
//

#ifndef FASTFIXED_H
#define FASTFIXED_H

#include "Fixed.h"

template <int N, int M>
class FastFixed {
public:
    using StorageType = typename std::conditional<N <= 8, Fixed<8, M>,
                        typename std::conditional<N <= 16, Fixed<16, M>,
                        typename std::conditional<N <= 32, Fixed<32, M>,
                        //typename std::conditional<N == 64, int64_t, int64_t>::type>::type>::type>::type;
                        typename std::conditional<N <= 64, Fixed<64, M>, void>::type>::type>::type>::type;

    StorageType v;

    FastFixed(StorageType v) : v(v) {}
    FastFixed() : v(0) {}
    constexpr FastFixed(int v): v(v) {}
    constexpr FastFixed(float f): v(f) {}
    constexpr FastFixed(double f): v(f) {}
    std::strong_ordering operator<=>(const FastFixed&) const = default;
    bool operator==(const FastFixed&) const = default;

    static constexpr FastFixed from_raw(int64_t x) {
        FastFixed ret;
        ret.v = ret.v.from_raw(x);
        return ret;
    }
};

#endif //FASTFIXED_H
