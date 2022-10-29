// поиск через сумму уголов

#include <iostream>
#include <vector>
#include<cmath>
#include <numbers>
#include "poly.h"

using namespace std;

class MyVector {
public:
    float x;
    float y;
    MyVector(float v1, float v2) {
        x = v1;
        y = v2;
    }
};

string is_inside_poly(vector<float> x_arr, vector<float> y_arr, float x, float y) {
    long n = x_arr.size();
    float eps = 1.5;

    float alfa_sum = 0;
    for (int i = 0; i < n; i++) {
        float x1 = x_arr[i];
        float y1 = y_arr[i];
        float x2, y2;
        if (i != n - 1) {
            x2 = x_arr[i + 1];
            y2 = y_arr[i + 1];
        }
        else {
            x2 = x_arr[0];
            y2 = y_arr[0];
        }
        float A = (y2 - y1);
        float B = -(x2 - x1);
        float C = - x1*(y2 - y1) + y1*(x2 - x1);
        float dist = abs(A*x + B*y + C)/sqrt(A*A + B*B);
        if (dist == 0) return "On the board";

        MyVector a(x1 - x, y1 - y);
        MyVector b(x2 - x, y2 - y);
        cout << "a " << a.x << " " << a.y << endl;
        cout << "b " << b.x << " " << b.y << endl;

        float cos_alfa = (a.x * b.x + a.y * b.y)/(sqrt(a.x * a.x + a.y * a.y) + sqrt(b.x * b.x + b.y*b.y));
        cout << "cos_alfa " << cos_alfa << endl;
        float alfa = acos(cos_alfa);
        cout << "alfa " << alfa << endl;

        float z_component = a.x * b.y - a.y * b.y;
        cout << "z_component " << z_component << endl;
        alfa_sum += alfa;
        //        if (z_component <= 0) {
        //            alfa_sum += alfa;
        //        } else {
        //            alfa_sum -= alfa;
        //        }
        cout << "alfa_sum " << alfa_sum << endl << endl;
    }

    cout << "2*M_PI " << 2*M_PI << endl << endl;
    if ((2*M_PI - eps <= alfa_sum && alfa_sum <= 2*M_PI + eps) || (-2*M_PI - eps <= alfa_sum && alfa_sum <= -2*M_PI + eps)) {
        return "In poly";
    }
    return "Outside poly";
}
