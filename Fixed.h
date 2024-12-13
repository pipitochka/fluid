//
// Created by Артем Акулов on 13.12.2024.
//

#ifndef FIXED_H
#define FIXED_H

using namespace std;

template <int N, int M>
class Fixed {
public:
    int32_t v;
    constexpr Fixed(int v): v(v << 16) {}
    constexpr Fixed(float f): v(f * (1 << 16)) {}
    constexpr Fixed(double f): v(f * (1 << 16)) {}
    constexpr Fixed(): v(0) {}

    static constexpr Fixed from_raw(int32_t x) {
        Fixed ret;
        ret.v = x;
        return ret;
    }

    //shows mistakes on mac os
    //auto operator<=>(const Fixed&) const = default;
    std::strong_ordering operator<=>(const Fixed&) const = default;
    bool operator==(const Fixed&) const = default;

    // friend Fixed<N, M> operator+(Fixed<N, M> a, Fixed<N, M> b);
    // friend Fixed operator-(Fixed a, Fixed b);
    // friend Fixed operator*(Fixed a, Fixed b);
    // friend Fixed<N, M> operator/(Fixed<N, M> a, Fixed<N, M> b);
    // friend Fixed &operator+=(Fixed &a, Fixed b);
    // friend Fixed &operator-=(Fixed &a, Fixed b);
    // friend Fixed &operator*=(Fixed &a, Fixed b);
    // friend Fixed &operator/=(Fixed &a, Fixed b);
    // friend Fixed operator-(Fixed x);
    // friend Fixed abs(Fixed x);
    // friend ostream &operator<<(ostream &out, Fixed x);
};



#endif //FIXED_H
