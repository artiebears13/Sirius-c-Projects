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

    explicit Quat(R n) : s(n), x(n), y(n), z(n) {};    // записываем в кватернион число

//    template <typename R>
    Quat(R a1, R b1, R c1, R d1) : s(a1), x(b1), y(c1), z(d1) {}; //основной конструктор кватеорниона

    Quat operator+(const Quat &q);  //перегрузка суммы

    Quat operator-(const Quat &q);    // перегрузка разности

    Quat operator*(const Quat &q);   //перегрузка умножения

    Quat& operator+=(const Quat &q);  //+= тоже перегружаем тк в полиноме используется этот оператор

    Quat &operator=(int n) {    // =числу (каждый коэф должен быть равен ему) тоже перегружаем тк в полиноме используется этот оператор
        this->s= n;
        this->x = n;
        this->y = n;
        this->z = n;
        return *this;
    }


    Quat<R> operator*(R k);     // умножение кватерниона на число

    bool operator==(Quat q);     //перегрузка сравнения 2 кватернионов (логической сравнение для if'ов )

    bool operator!=(Quat q);    // перегрузка логического не равно
};

template<typename R>
ostream &operator<<(ostream &os, Quat<R> &q) {          // перегрузка записи в поток (для cout)
    os << "(" << q.s << ", [" << q.x << ", " << q.y << ", " << q.z << "])";
    return os;
}

//реализация методов и перегрузок
template<typename R>
bool Quat<R>::operator==(Quat<R> q) {
    return this->s == q.s && this->x == q.x && this->y == q.y && this->z == q.z; //два кватерниона равны если равны покоэффициентно (тогда возваращаем true)
}


// != возвращает true если не равен хотя бы 1 коэффициент
template<typename R>
bool Quat<R>::operator!=(Quat<R> q) {
    return this->s != q.s || this->x != q.x || this->y != q.y || this->z != q.z;
}

//сумма - покоэффициентная сумма
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

//умножение на число - умножение каждого коэфа на число
template<typename R>
Quat<R> Quat<R>::operator*(R k) {
    return Quat<R>(this->s * k, this->x * k, this->y * k, this->z * k);
}

