//
// Created by ArtMed on 03.11.2022.
//
#pragma once

#include <vector>
#include <string>

using namespace std;

enum operators{
    pplus,
    mminus,
    multiply,
    derivative,
    integral,
    empty
};

class Poly {
public:
    vector<double> coefs = {};

    Poly() = default;

    Poly(int n){
        coefs.resize(n,0);
    };

    Poly(vector<double> params): coefs(params){};

    Poly(string params);

    Poly operator+(Poly poly);
    Poly operator-(Poly poly);
    Poly operator*(Poly poly);
    Poly integral();
    Poly derivative();



       // внутри класса: a<<b;  <=>  a.operator<<(b);


};

std::ostream & operator<<(std::ostream &, Poly p);