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




        int Line::get_pos(int x, int y) {
            bool check= false;
            if (y < y1 != y < y2 &&
                (x == (x2 - x1) * (y - y1) / (y2 - y1) + x1)) {
                check= true;
                return 2;
            }

            if ((y == y1 || y == y2) &&
                (x < (x2 - x1) * (y - y1) / (y2 - y1) + x1)) {
                check= true;
                return 2;
            }

            if (y < y1 != y < y2 &&
                x < (x2 - x1) * (y - y2) / (y2 - y1) + x1) {
                check= true;
                return 1;
            }
            if (!check)
            {
                return 0;
            }
        }


