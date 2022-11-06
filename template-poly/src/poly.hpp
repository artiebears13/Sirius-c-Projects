//
// Created by ArtMed on 03.11.2022.
//
#pragma once

#include <vector>
#include <string>
#include "quat.hpp"

using namespace std;

enum operators{
    zero,   // for mapping  //остатки 6 задания
    pplus,
    mminus,
    multiply,
    derivative,
    integral,
    eempty
};
template <typename T>
class Poly {
public:
    vector<T> coefs = {};

    Poly() = default;

    Poly(int n){
        coefs.resize(n);
        for (int i = 0; i < coefs.size(); ++i) {
            coefs[i]=0;
        }
    };

    Poly<T>(vector<T> params): coefs(params){};

//    Poly<T>(string params);

    Poly<T> operator+(Poly<T> poly);
    Poly<T> operator-(Poly<T> poly);
    Poly<T> operator*(Poly<T> poly);
//    Poly<T> integral();
//    Poly<T> derivative();



       // внутри класса: a<<b;  <=>  a.operator<<(b);


};

//перегрузка вывода в поток
template <typename T>
std::ostream & operator<<(std::ostream &os, Poly<T> p) {
    for (int i = 0; i < p.coefs.size(); ++i) {
        if (i>1) {
            os <<" + "<< p.coefs[i] << "x^"<<i;
        }
        else if (i==0){
            os << p.coefs[i];
        } else if (i==1){
            os << " + " << p.coefs[i]<<"x" ;
        }
    }
    os << std::endl;
    return os;
}


//----------------------+-------------------
template <typename T>
Poly<T> Poly<T>::operator+(Poly<T> poly) {
    Poly<T> ans(max(coefs.size(), poly.coefs.size()));
    if (coefs.size() >= poly.coefs.size()) {
        for (int i = 0; i < coefs.size(); ++i) {
            ans.coefs[i] = coefs[i];
        }
        for (int i = 0; i < poly.coefs.size(); ++i) {     //until lenght less-len poly
            ans.coefs[i] += poly.coefs[i];
        }
    } else {
        for (int i = 0; i < poly.coefs.size(); ++i) {
            ans.coefs[i] = poly.coefs[i];
        }
        for (int i = 0; i < coefs.size(); ++i) {     //until lenght less-len poly
            ans.coefs[i] += coefs[i];
        }
    }
    return ans;
}

//----------------------------------------------

template <typename T>
Poly<T> Poly<T>::operator-(Poly<T> poly) {
    Poly<T> ans(max(coefs.size(), poly.coefs.size()));

    for (int i = 0; i < coefs.size(); ++i) {
        ans.coefs[i] = coefs[i];
    }
    for (int i = 0; i < poly.coefs.size(); ++i) {     //until lenght less-len poly
        ans.coefs[i] =ans.coefs[i] - poly.coefs[i];
    }

    return ans;
}

//--------------------------------------------
template <typename T>
Poly<T> Poly<T>::operator*(Poly<T> poly) {
    int len_ans = (coefs.size() - 1) + (poly.coefs.size() - 1) + 1;
    Poly<T> ans = Poly(len_ans);
    for (int i = 0; i < coefs.size(); i++)
        for (int j = 0; j < poly.coefs.size(); j++)
            ans.coefs[i + j] += coefs[i] * poly.coefs[j];
    return ans;
}




