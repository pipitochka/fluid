#include "Headers.h"
#include "Fixed.h"

using namespace std;


constexpr size_t N = 36, M = 84;
// constexpr size_t N = 14, M = 5;
constexpr size_t T = 1'000'000;
constexpr std::array<pair<int, int>, 4> deltas{{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

template <int N, int M>
Fixed<N, M> operator+(Fixed<N, M> a, Fixed<N, M> b) {
    return Fixed<N, M>::from_raw(a.v + b.v);
}

template <int N, int M>
Fixed<N, M> operator-(Fixed<N, M> a, Fixed<N, M> b) {
    return Fixed<N, M>::from_raw(a.v - b.v);
}

template <int N, int M>
Fixed<N, M> operator*(Fixed<N, M> a, Fixed<N, M> b) {
    return Fixed<N, M>::from_raw(((int64_t) a.v * b.v) >> 16);
}

template <int N, int M, class T>
Fixed<N, M> operator*(Fixed<N, M> a, T b) {
    return Fixed<N, M>::from_raw(((int64_t) a.v * Fixed<N, M>(b).v) >> 16);
}

template <int N, int M>
Fixed<N, M> operator/(Fixed<N, M> a, Fixed<N, M> b) {
    return Fixed<N, M>::from_raw(((int64_t) a.v << 16) / b.v);
}

template <int N, int M, class T>
Fixed<N, M> operator/(Fixed<N, M> a, T b) {
    return Fixed<N, M>::from_raw(((int64_t) a.v << 16) / Fixed<N, M>(b).v);
}

template <int N, int M>
Fixed<N, M> &operator+=(Fixed<N, M> &a, Fixed<N, M> b) {
    return a = a + b;
}

template <int N, int M>
Fixed<N, M> &operator-=(Fixed<N, M> &a, Fixed<N, M> b) {
    return a = a - b;
}

template <int N, int M>
Fixed<N, M> &operator*=(Fixed<N, M> &a, Fixed<N, M> b) {
    return a = a * b;
}

template <int N, int M, typename T>
Fixed<N, M> &operator*=(Fixed<N, M> &a, T b) {
    return a = a * b;
}

template <int N, int M>
Fixed<N, M> &operator/=(Fixed<N, M> &a, Fixed<N, M> b) {
    return a = a / b;
}

template <int N, int M, typename T>
Fixed<N, M> &operator/=(Fixed<N, M> &a, T b) {
    return a = a / b;
}


template <int N, int M>
Fixed<N, M> operator-(Fixed<N, M> x) {
    return Fixed<N, M>::from_raw(-x.v);
}

template <int N, int M>
Fixed<N, M> abs(Fixed<N, M> x) {
    if (x.v < 0) {
        x.v = -x.v;
    }
    return x;
}

template <int N, int M>
ostream &operator<<(ostream &out, Fixed<N, M> x) {
    return out << x.v / (double) (1 << 16);
}


static constexpr Fixed<N, M> inf = Fixed<N, M>::from_raw(std::numeric_limits<int32_t>::max());
static constexpr Fixed<N, M> eps = Fixed<N, M>::from_raw(deltas.size());

