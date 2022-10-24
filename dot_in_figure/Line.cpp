//
// Created by ArtMed on 24.10.2022.
//
#include <iostream>
#include "Line.h"



    Line::Line(int x_begin, int y_begin, int x_end, int y_end) {
        x1 = x_begin;
        x2 = x_end;
        y1 = y_begin;
        y2 = y_end;
    }

    bool Line::get_cross_x(int x, int y) {
        double k;
        k = (y1 - y2) / (x1 - x2);
        double b = y1 - k * x1;
        double x_cross = (y - b) / k;
        std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x_cross << std::endl;
        if (x_cross >= x) {
            return true;
        } else {
            return false;
        }
    };

    int Line::x_cross_line(int x, int y) {
        if (x1 >= x) {
            if (((y <= y2) && (y >= y1)) || ((y <= y1) && (y >= y2))) {
                if (get_cross_x(x, y)) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        }
    }


