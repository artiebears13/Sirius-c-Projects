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

template <typename R>
class Quat{
public:
    R s = 0;
    R x = 0;
    R y = 0;
    R z = 0;

    Quat()=default;
    explicit Quat(R n): s(n), x(n), y(n), z(n) {};
//    template <typename R>
    Quat(R a1, R b1, R c1, R d1): s(a1), x(b1), y(c1), z(d1){}

    Quat operator+ (Quat q);
    Quat operator- (Quat q);
    Quat operator* (Quat q);
    Quat operator+= (Quat q);
    Quat operator= (int n){
        s=n;
        x=n;
        y=n;
        z=n;
    }


    Quat<R> operator* (R k);

    bool operator== (Quat q);
    bool operator!= (Quat q);
};

template  <typename R>
ostream &operator<< (ostream& os, Quat<R>& q){
    os << "(" << q.s << ", [" << q.x << ", " << q.y << ", " << q.z << "])";
    return os;
}

//template <typename R>
//Quat<R>::Quat(){
//    a = 0;
//    b = 0;
//    c = 0;
//    d = 0;
//}


//    this->a = a;
//    this->b = b;
//    this->c = c;
//    this->d = d;


template <typename R>
bool Quat<R>::operator==(Quat<R> q){
    return s == q.s && x == q.x && y == q.y && z == q.z;
}

template <typename R>
bool Quat<R>::operator!=(Quat<R> q){
    return s != q.s || x != q.x || y != q.y || z != q.z;
}

template <typename R>
Quat<R> Quat<R>::operator+ (Quat<R> q){
    return Quat<R>(s + q.s, x + q.x, y + q.y, z + q.z);
}
template <typename R>
Quat<R> Quat<R>::operator+= (Quat<R> q){
    s=s + q.s;
    x=x+q.x;
    y=y+q.y;
    z=z+q.z;
//    return 0;
//    return Quat<R>(this->s + q.s, this->x + q.x, this->y + q.y, this->z + q.z);
}

template <typename R>
Quat<R> Quat<R>::operator- (Quat<R> q){
    return Quat<R>(s - q.s, x - q.x, y - q.y, z - q.z);
}

template <typename R>
Quat<R> Quat<R>::operator* (Quat<R> q){
    return Quat<R>(
            s * q.s - x * q.x - y * q.y - z * q.z,  //=a
             s * q.x + x * q.s + y * q.z - z * q.y,  //=b
             s * q.y - x * q.z + y * q.s + z * q.x,  //=c
             s * q.z + x * q.y - y * q.x + z * q.s   //=d
    );
}



template <typename R>
Quat<R> Quat<R>::operator* (R k){
    return Quat<R>(s * k, x * k, y * k, z * k);
}

