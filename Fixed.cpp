//
// Created by Артем Акулов on 16.12.2024.
//
using namespace std;

template<int N, int M>
class Fixed {
public:
    using StorageType = typename std::conditional<N == 8, int8_t,
        typename std::conditional<N == 16, uint16_t,
        typename std::conditional<N == 32, uint32_t,
        typename std::conditional<N == 64, uint64_t, void>::type>::type>::type>::type;

    constexpr Fixed(int v): v(v << M) {}
    constexpr Fixed(float f): v(f * (1 << M)) {}
    constexpr Fixed(double f): v(f * (1 << M)) {}
    constexpr Fixed(): v(0) {}

    static constexpr Fixed from_raw(__int128_t x) {
        Fixed ret;
        ret.v = x;
        return ret;
    }
    template<int N1, int M1>
    constexpr Fixed(const Fixed<N1, M1>& other) {
        if (M > M1) {
            v = other.v >> (M1 - M);
        } else if (M1 < M) {
            v = other.v << (M - M1);
        } else {
            v = other.v;
        }
    }
    StorageType v;

    std::strong_ordering operator<=>(const Fixed&) const = default;
    bool operator==(const Fixed&) const = default;
};

constexpr std::array<pair<int, int>, 4> deltas{{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

template<int N, int M>
static constexpr Fixed<N, M> inf = Fixed<N, M>::from_raw(std::numeric_limits<int32_t>::max());

template<int N, int M>
static constexpr Fixed<N, M> eps = Fixed<N, M>::from_raw(deltas.size());



template<int N, int M>
Fixed<N, M> operator+(Fixed<N, M> a, Fixed<N, M> b) {
    return Fixed<N, M>::from_raw(a.v + b.v);
}

template<int N, int M, typename T>
Fixed<N, M> operator+(Fixed<N, M> a, T b) {
    return a + Fixed<N, M>(b);
}

template<int N, int M>
Fixed<N, M> operator-(Fixed<N, M> a, Fixed<N, M> b) {
    return Fixed<N, M>::from_raw(a.v - b.v);
}

template<int N, int M, typename T>
Fixed<N, M> operator-(Fixed<N, M> a, T b) {
    return a - Fixed<N, M>(b);
}

template<int N, int M>
Fixed<N, M> operator*(Fixed<N, M> a, Fixed<N, M> b) {
    return Fixed<N, M>::from_raw(((__int128) a.v * b.v) >> M);
}

template<int N, int M, typename T>
Fixed<N, M> operator*(Fixed<N, M> a, T b) {
    return a * Fixed<N, M>(b);
}

template<int N, int M>
Fixed<N, M> operator/(Fixed<N, M> a, Fixed<N, M> b) {
    return Fixed<N, M>::from_raw(((__int128) a.v << M) / b.v);
}

template<int N, int M, typename T>
Fixed<N, M> operator/(Fixed<N, M> a, T b) {
    return a / Fixed<N, M>(b);;
}

template<int N, int M>
Fixed<N, M> &operator+=(Fixed<N, M> &a, Fixed<N, M> b) {
    return a = a + b;
}

template<int N, int M, typename T>
Fixed<N, M> &operator+=(Fixed<N, M> &a, T b) {
    return a = a + b;
}

template<int N, int M>
Fixed<N, M> &operator-=(Fixed<N, M> &a, Fixed<N, M> b) {
    return a = a - b;
}

template<int N, int M, typename T>
Fixed<N, M> &operator-=(Fixed<N, M> &a, T b) {
    return a = a - b;
}

template<int N, int M>
Fixed<N, M> &operator*=(Fixed<N, M> &a, Fixed<N, M> b) {
    return a = a * b;
}

template<int N, int M, typename T>
Fixed<N, M> &operator*=(Fixed<N, M> &a, T b) {
    return a = a * b;
}

template<int N, int M>
Fixed<N, M> &operator/=(Fixed<N, M> &a, Fixed<N, M> b) {
    return a = a / b;
}

template<int N, int M, typename T>
Fixed<N, M> &operator/=(Fixed<N, M> &a, T b) {
    return a = a / Fixed<N, M>(b);
}

template<int N, int M>
Fixed<N, M> operator-(Fixed<N, M> x) {
    return Fixed<N, M>::from_raw(-x.v);
}

template<int N, int M>
Fixed<N, M> abs(Fixed<N, M> x) {
    if (x.v < 0) {
        x.v = -x.v;
    }
    return x;
}

template<int N, int M>
ostream &operator<<(ostream &out, Fixed<N, M> x) {
    return out << x.v / (double) (1 << M);
}


mt19937 rnd(1337);

template<int N, int M>
Fixed<N, M> random01(Fixed<N, M> val) {
    return Fixed<N, M>::from_raw((rnd() & (((int64_t)1 << M) - 1)));
}

float random01(float val) {
    return rand() / (float) RAND_MAX;
}

double random01(double val) {
    return rand() / (double) RAND_MAX;
}