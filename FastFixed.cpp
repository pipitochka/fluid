//
// Created by Артем Акулов on 14.12.2024.
//
#include "FastFixed.h"

template <int N, int M>
FastFixed<N, M> operator+(FastFixed<N, M> a, FastFixed<N, M> b) {
    return FastFixed<N, M>(a.v + b.v);
}

template <int N, int M>
FastFixed<N, M> operator-(FastFixed<N, M> a, FastFixed<N, M> b) {
    return FastFixed<N, M>(a.v - b.v);
}

template <int N, int M>
FastFixed<N, M> operator*(FastFixed<N, M> a, FastFixed<N, M> b) {
    return FastFixed<N, M>(a.v * b.v);
}

template <int N, int M, class T>
FastFixed<N, M> operator*(FastFixed<N, M> a, T b) {
    return FastFixed<N, M>(a.v * b);
}

template <int N, int M>
FastFixed<N, M> operator/(FastFixed<N, M> a, FastFixed<N, M> b) {
    return FastFixed<N, M>(a.v / b.v);
}

template <int N, int M, class T>
FastFixed<N, M> operator/(FastFixed<N, M> a, T b) {
    return FastFixed<N, M>(a.v / b);
}

template <int N, int M>
FastFixed<N, M> &operator+=(FastFixed<N, M> &a, FastFixed<N, M> b) {
    a.v += b.v;
    return a;
}

template <int N, int M>
FastFixed<N, M> &operator-=(FastFixed<N, M> &a, FastFixed<N, M> b) {
    a.v -= b.v;
    return a;
}

template <int N, int M>
FastFixed<N, M> &operator*=(FastFixed<N, M> &a, FastFixed<N, M> b) {
    a.v *= b.v;
    return a;
}

template <int N, int M, typename T>
FastFixed<N, M> &operator*=(FastFixed<N, M> &a, T b) {
    a.v *= b;
    return a;
}

template <int N, int M>
FastFixed<N, M> &operator/=(FastFixed<N, M> &a, FastFixed<N, M> b) {
    a.v /= b.v;
    return a;
}

template <int N, int M, typename T>
FastFixed<N, M> &operator/=(FastFixed<N, M> &a, T b) {
    a.v /= b;
    return a;
}

template <int N, int M>
FastFixed<N, M> operator-(FastFixed<N, M> x) {
    FastFixed<N, M>q = FastFixed<N, M>(x.v);
    q.v = -q.v;
    return q;
}

template <int N, int M>
FastFixed<N, M> abs(FastFixed<N, M> x) {
    FastFixed<N, M>q = FastFixed<N, M>(x.v);
    q.v = fabs(q.v);
    return q;
}

template <int N, int M>
ostream &operator<<(ostream &out, FastFixed<N, M> x) {
    return out << x.v / (double) (1 << 16);
}

// template <int N, int M>
// static constexpr Fixed<N, M> inf = Fixed<N, M>::from_raw(std::numeric_limits<int32_t>::max());
//
// template <int N, int M>
// static constexpr Fixed<N, M> eps = Fixed<N, M>::from_raw(deltas.size());
