// поиск через сумму уголов

#include <iostream>
#include <vector>
#include<cmath>
#include <numbers>

double mix_sub(double first[3], double second[3]) {
    double cx = 0, cy = 0, cz = 1;
    return first[0] * second[1] * cz + first[1] * second[2] * cx + second[0] * cy * first[2] -
           first[2] * second[1] * cx - second[0] * first[1] * cz - first[0] * cy * second[2];
}


using namespace std;


// function return -1 if dot is on the edge,
// 1 if dot outside
// 0 if dot inside

int is_inside_poly(vector<double> x_arr, vector<double> y_arr, double x, double y) {

    int is_outside = 0;
    double first[3];
    double second[3];
    double eps = 1e-5;
    std::vector<double> angles;
    float cx = 0, cy = 0, cz = 1;

    for (int i = 0; i < x_arr.size() - 1; ++i) {
        double x1 = x_arr[i];
        double x2 = x_arr[i + 1];
        double y1 = y_arr[i];
        double y2 = y_arr[i + 1];

        first[0] = x1 - x;
        first[1] = y1 - y;
        first[2] = 0;
        second[0] = x2 - x;
        second[1] = y2 - y;
        second[2] = 0;

//        -----------------------------------------
//        we need to get mixed substraction sign
//        to get angle orientation
//        -----------------------------------------

        double det = mix_sub(first, second);
        int sign = (det >= 0) ? 1 : -1;

        double norm_a = std::sqrt(first[0] * first[0] + first[1] * first[0]);
        double norm_b = std::sqrt(second[0] * second[0] + second[1] * second[0]);

        //case if dot = vartex
        if ((norm_a < eps) or (norm_b < eps)) {
            return -1;
        }

        double cos_alpha = (first[0] * second[0] + first[1] * second[1]) / (norm_a * norm_b);


        double angle = std::acos(cos_alpha);
        angles.push_back(angle * sign);
    }
    double angles_sum = 0;
    for (int angle = 0; angle < angles.size(); ++angle) {

        angles_sum += angles[angle];

        //if angle is equals to pi, it means that dot is on the edge
        if (fabs(fabs(angles[angle]) - M_PI) < eps) {
            return -1;
        }
    }

    //if angle is equals to 2pi => dot is inside, otherwise => outside
    is_outside = !(fabs(fabs(angles_sum) - 2 * M_PI) < eps);


    return is_outside;


}
