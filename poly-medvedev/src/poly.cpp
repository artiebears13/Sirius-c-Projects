// поиск через трассировку луча

#include <iostream>
#include <vector>
#include<cmath>
#include <numbers>
#include "poly.h"

using namespace std;

int is_inside_poly(vector<float> x_arr, vector<float> y_arr, float x, float y, string ans) {
    long n = x_arr.size();
    float eps = 0.001;
    string get_ans;

    int counter = 0;
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
        if (dist == 0) {
            cout << "On the board";
            get_ans = "On the board";

            if (ans == get_ans) {
                return 0;
            }
            return 1;
        }

        if (x1 > x && x2 > x) {
            if (y1 < y2) {
                if (y1 < y && y < y2) counter++;
            } else if (y2 < y1) {
                if (y2 < y && y < y1) counter++;
            }
        }
    }

    if (counter % 2 != 0) {
        cout << "In poly";
        get_ans = "In poly";
    }
    else {
        cout << "Outside poly";
        get_ans = "Outside poly";
    }

    if (ans == get_ans) {
        return 0;
    }
    return 1;
}
