//
// Created by ArtMed on 05.11.2022.
//
#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <complex>

using namespace std;

template<typename R>
class Quat {
public:
    R s = 0;
    R x = 0;
    R y = 0;
    R z = 0;

    Quat() = default;

    explicit Quat(R n) : s(n), x(n), y(n), z(n) {};

//    template <typename R>
    Quat(R a1, R b1, R c1, R d1) : s(a1), x(b1), y(c1), z(d1) {};

    Quat operator+(const Quat &q);

    Quat operator-(const Quat &q);

    Quat operator*(const Quat &q);

    Quat& operator+=(const Quat &q);

    Quat &operator=(int n) {
        this->s= n;
        this->x = n;
        this->y = n;
        this->z = n;
        return *this;
    }


    Quat<R> operator*(R k);

    bool operator==(Quat q);

    bool operator!=(Quat q);
};

template<typename R>
ostream &operator<<(ostream &os, Quat<R> &q) {
    os << "(" << q.s << ", [" << q.x << ", " << q.y << ", " << q.z << "])";
    return os;
}


template<typename R>
bool Quat<R>::operator==(Quat<R> q) {
    return this->s == q.s && this->x == q.x && this->y == q.y && this->z == q.z;
}

template<typename R>
bool Quat<R>::operator!=(Quat<R> q) {
    return this->s != q.s || this->x != q.x || this->y != q.y || this->z != q.z;
}

template<typename R>
Quat<R> Quat<R>::operator+(const Quat<R> &q) {
    return Quat<R>(this->s + q.s, this->x + q.x, this->y + q.y, this->z + q.z);
}

template<typename R>
Quat<R> &Quat<R>::operator+=(const Quat<R> & q) {
    this->s = s + q.s;
    this->x = x + q.x;
    this->y = y + q.y;
    this->z = z + q.z;
    return *this;
//
}

template<typename R>
Quat<R> Quat<R>::operator-(const Quat<R> &q) {
    return Quat<R>(this->s - q.s, this->x - q.x, this->y - q.y, this->z - q.z);
}

template<typename R>
Quat<R> Quat<R>::operator*(const Quat<R> &q) {
    return Quat<R>(
            this->s * q.s - this->x * q.x - this->y * q.y - this->z * q.z, //=a
            this->s * q.x + this->x * q.s + this->y * q.z - this->z * q.y,  //=b
            this->s * q.y - this->x * q.z + this->y * q.s + this->z * q.x,  //=c
            this->s * q.z + this->x * q.y - this->y * q.x + this->z * q.s  //=d
    );
}


template<typename R>
Quat<R> Quat<R>::operator*(R k) {
    return Quat<R>(this->s * k, this->x * k, this->y * k, this->z * k);
}

