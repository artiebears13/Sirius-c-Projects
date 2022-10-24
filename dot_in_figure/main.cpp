#include <iostream>
#include <fstream>
#include <vector>
#include "Line.h"




int main() {
    std::string filename = "C:\\Users\\ArtMed\\Desktop\\Sirius-c-Projects\\dot_in_figure\\poly.txt";

    int x_coord, y_coord;
    int x[2] = {220, 200}; //outside
    int cross_counter = 0;
    std::vector<int> x_points;
    std::vector<int> y_points;
    std::vector<int> now_point;

    std::string line;
    std::ifstream myfile(filename);
    std::fstream f(filename);


    while (!f.eof()) {
        f >> x_coord >> y_coord;
        if (f.bad()) {
            std::cout << "Broke" << std::endl;
            f.close();
            exit(-1);
        }
        x_points.push_back(x_coord);
        y_points.push_back(y_coord);
    }
    f.close();

    for (int i = 1; i < x_points.size(); ++i) {
        int &x1 = x_points.at(i - 1);
        int &y1 = y_points.at(i - 1);
        int &x2 = x_points.at(i);
        int &y2 = y_points.at(i);


        Line nowline(x1, y1, x2, y2);
        if (nowline.x_cross_line(x[0], x[1]) == 1) {
            ++cross_counter;
        }
    }
    int last = x_points.size() - 1;

    int &x1 = x_points.at(last);
    int &y1 = y_points.at(last);
    int &x2 = x_points.at(0);
    int &y2 = y_points.at(0);
    if ((x1 == x1) && (y1 == y2)) {

    } else {
        Line nowline(x1, y1, x2, y2);
        if (nowline.x_cross_line(x[0], x[1]) == 1) {
            ++cross_counter;
        }
    }


    if (cross_counter % 2 == 0) {
        std::cout << cross_counter << " dot is outside" << std::endl;
    } else {
        std::cout << "dot is inside" << std::endl;
    }


    return 0;
}
