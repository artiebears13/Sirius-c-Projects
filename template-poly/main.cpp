#include <iostream>
#include "src/poly.hpp"
#include <vector>
#include <complex>
#include "src/quat.hpp"

using namespace std;

int main() {
//    std::string p1 = "* + [1 0 1] [1 2 3]";
//    pair<vector<operators>, vector<Poly>> parsed;
//    parsed=input_parsing();

//    vector<double> p1={1.0, 2.5, 2.5};
//    vector<double> p2={9.0, 7.5, 7.5};
//    vector<complex<double>> vc1 {{1., 2.}, {3., 4.}, {5., 6.}};
//    vector<complex<double>> vc2 {{1., 2.}, {3., 4.}, {5., 6.}};
//    Poly poly1(vc1);
//    Poly poly2(vc2);
//
//    cout<<poly1+poly2;

    std::vector<Quat<double> > vq{{1., 2., 3., 4.},
                                  {5,  6,  7,  8}};
    Poly<Quat<double> > p3(vq);
//    cout << p3 << endl;

    std::vector<Quat<double> > vq1{{2., 4., 6., 8},
                                   {10., 12., 14., 16.}};
    Poly<Quat<double> > p4(vq1);
    cout << "first: " << p3 << endl;
    cout << "second: " << p4 << endl;
    cout << " + " << endl;
    cout << (p3 + p4) << endl;
    cout << (p3 - p4) << endl;
    cout << (p3 * p4) << endl;


//    cout<<calculate(parsed);




    return 0;

}
