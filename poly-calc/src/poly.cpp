//
// Created by ArtMed on 03.11.2022.
//

#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
#include "poly.h"

using namespace std;

Poly::Poly(string params) {
    while(params[0] == '[' || params[0] == ' ')
        params.erase(0, 1);

    while(params[params.size() - 1] == ']' || params[params.size() - 1] == ' ')
        params.erase(params.size() - 1, 1);


    int pos = 0;
    while ((pos = params.find(" ")) != string::npos) {
        coefs.push_back(stod(params.substr(0, pos)));
        params.erase(0, pos + 1);
    }
    coefs.push_back(stod(params));
}

Poly Poly::operator+(Poly poly) {
    Poly ans(max(coefs.size(), poly.coefs.size()));
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


Poly Poly::operator-(Poly poly) {
    Poly ans(max(coefs.size(), poly.coefs.size()));

    for (int i = 0; i < coefs.size(); ++i) {
        ans.coefs[i] = coefs[i];
    }
    for (int i = 0; i < poly.coefs.size(); ++i) {     //until lenght less-len poly
        ans.coefs[i] -= poly.coefs[i];
    }

    return ans;
}

Poly Poly::operator*(Poly poly) {
    int len_ans = (coefs.size() - 1) + (poly.coefs.size() - 1) + 1;
    Poly ans = Poly(len_ans);
    for (int i = 0; i < coefs.size(); i++)
        for (int j = 0; j < poly.coefs.size(); j++)
            ans.coefs[i + j] += coefs[i] * poly.coefs[j];
    return ans;
}

Poly Poly::integral() {
    Poly ans = Poly(coefs.size() + 1);
    for(int i = 1; i <= coefs.size(); i++)
        ans.coefs[i] = coefs[i - 1] / i;
    return ans;
}

Poly Poly::derivative() {
    Poly ans = Poly(coefs.size() - 1);
    for (int i = 0; i < coefs.size()-1; ++i) {
        ans.coefs[i]=coefs[i+1]*(i+1);
    }
    return ans;
}


std::ostream &operator<<(std::ostream &os, Poly p) {
    for (int i = 0; i < p.coefs.size(); ++i) {
        os << p.coefs[i] << " ";
    }
    os << std::endl;
}

