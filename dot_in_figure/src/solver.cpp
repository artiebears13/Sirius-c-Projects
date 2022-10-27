#include <iostream>
#include <fstream>
#include <vector>
#include "Line.h"


int solver(std::vector<float> x_points, std::vector<float> y_points, float x, float y){
    int cross_counter=0;
    for (int i = 0; i < x_points.size()-1; i++) {
        float x1 = x;
        float y1 = y;
        float x2 = x_points[i+1];
        float y2 = y_points[i+1];
        //std::cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<std::endl;



        Line nowline(x1, y1, x2, y2);
        if (nowline.get_pos(x, y) == 1) {
            ++cross_counter;
        }
        if (nowline.get_pos(x, y) == 2) {
            cross_counter=-1;
            return cross_counter;
        }
    }
    if (cross_counter%2==0){
        cross_counter=0;
    }
    else{
        cross_counter=1;
    }
    return cross_counter;
}
