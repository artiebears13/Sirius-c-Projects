// поиск через вектор нормали ближайшей к точке прямой, ноправленной из многоугольника
// и вектор от точке к ближайшему отрезку (если угол == 0 - внутри, иначе - снаружи)

#include <iostream>
#include <vector>
#include<cmath>
#include "poly.h"

using namespace std;

string is_inside_poly_add(vector<float> x_arr, vector<float> y_arr, float x, float y) {
    long n = x_arr.size();
    // (x - x1)/(x2 - x1) = (y - y1)/(y2 - y1)
    // (x - x1)(y2 - y1) = (y - y1)(x2 - x1)
    // x(y2 - y1) - x1(y2 - y1) = y(x2 - x1) - y1(x2 - x1)
    // Ax + By + C = 0
    // A = (y2 - y1)
    // B = -(x2 - x1)
    // C = - x1(y2 - y1) + y1(x2 - x1)
    // dist = abs(Ax0 + By0 + C)/sqrt(A^2 + B^2)

    float eps = 0.001;

    // ближайший отрезок
    float min_dist = -1;
    float a_n, b_n, c_n;
    float dist;
    for (int i = 0; i < n; i++) {
        float x1 = x_arr[i];
        float y1 = y_arr[i];
        float x2, y2;
        if (i != n - 1) {
            x2 = x_arr[i + 1];
            y2 = y_arr[i + 1];
        } else {
            x2 = x_arr[0];
            y2 = y_arr[0];
        }
        float A = (y2 - y1);
        float B = -(x2 - x1);
        float C = - x1*(y2 - y1) + y1*(x2 - x1);
        dist = abs(A*x + B*y + C)/sqrt(A*A + B*B);
        cout << "p1 " << x1 << " " << y1 << endl;
        cout << "p2 " << x2 << " " << y2 << endl;
        cout << "dist " << dist << endl << endl;
        if (dist == 0) return "On the board";
        if (min_dist == -1) {
            min_dist = dist;
            a_n = A;
            b_n = B;
            c_n = C;
        }
        else {
            if (dist < min_dist) {
                min_dist = dist;
                a_n = A;
                b_n = B;
                c_n = C;
            }
        };
    }

    // Нормаль к ближ прямой (a_n, b_n)
    // Найдем точку на прямой, до которой ближайшее растояние от нашей точки
    // (нам нужны координаты этой точки и нормали прямой, чтобы найти вектор от заданой точки к этой точки)
    // ax + by + c = 0
    // y = -ax/b -c/b
    // y = kx + b0
    // k = -a/b b0 = -c/b
    // y = -kx + b1 - перпендикулярна (подставим x0 y0)
    // система
    // y = -kx + (y0 + kx0)
    // y = kx + b0

    float xe, ye; // координаты ближайшей точки на прямой
    float k = -a_n/b_n;
    float b0 = -c_n/b_n;
    xe = (y + k*x - b0)/ (2*k);
    ye = k*x + b0;

    float xv, yv; // координаты вектора от нашей заданой точки до ближайшей точки на прямой
    xv = xe - x;
    yv = ye - y;

    // Проблемма с тем, чтобы определить нормать для отрезка, которая будет направлена наружу многоугольника,
    // если мы найдем такую нормаль, то скалярное произведения векторов даст нам ответ

    return "";
}
