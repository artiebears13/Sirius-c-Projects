#include <iostream>
#include <fstream>
#include <vector>
#include "solver.h"


int main(int argc, char **argv) {
    std::string filename;
    double X, Y;
    try {
        filename = argv[1];
        X = std::stod(argv[2]);
        Y = std::stod(argv[3]);
    }
    catch (std::invalid_argument) {
        std::cerr << "Incorrect arguments formats\n";
        std::cerr << "Yours: \"" << argv[1] << " " << argv[2] << " " << argv[3] << "\"\n";
        std::cerr << "Correct: \"<string> <double> <double>\"\n";
        exit(-1);
    }

    int x_coord, y_coord;
    //int x[2] = {5, 0}; //outside
    double x[2] = {X, Y};
    int cross_counter = 0;
    std::vector<double> x_points;
    std::vector<double> y_points;
    std::vector<double> now_point;

    std::string line;
    std::ifstream myfile(filename);
    std::fstream f(filename);


    while (!f.eof()) {
        if (f.good()) {
            f >> x_coord >> y_coord;
            x_points.push_back(x_coord);
            y_points.push_back(y_coord);
        }

    }
    f.close();
    x_points.push_back(x_points[0]);
    y_points.push_back(y_points[0]);


    int check = is_inside_poly(x_points, y_points, x[0], x[1]);
    cout << check << endl;
    if (check == -1) {
        cout << "dot is on the edge" << endl;

    } else {
        if (check == 1) {
            cout << "dot is outside" << endl;
        } else {
            cout << "dot is inside" << endl;
        }
    }
    return 0;
}
