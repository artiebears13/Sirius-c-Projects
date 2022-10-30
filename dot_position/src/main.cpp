#include <iostream>
#include <fstream>
#include <vector>
#include "solver.h"
#include "errors_processing.h"
#include "parser.h"
#include <sstream>
#include <filesystem>


int main(int argc, char **argv) {
    std::string filename;
    double X, Y;



    int err=processing(argc, argv, filename, X, Y);
    if (err==-1){
        exit(-1);
    }

//    try {
//        filename = argv[1];
//        X = std::stod(argv[2]);
//        Y = std::stod(argv[3]);
//    }
//    catch (std::invalid_argument) {
//        std::cerr << "Incorrect arguments formats\n";
//        std::cerr << "Yours: \"" << argv[1] << " " << argv[2] << " " << argv[3] << "\"\n";
//        std::cerr << "Correct: \"<string> <double> <double>\"\n";
//        exit(-1);
//    }

    double x_coord, y_coord;
    double x[2] = {X, Y};
    int cross_counter = 0;
    std::vector<double> x_points;
    std::vector<double> y_points;
    std::vector<double> now_point;

    std::string line;
    std::ifstream file(filename);
    int i=0;
    while(std::getline(file, line))
    {
        i++;
        std::vector <double> coord;
        std::stringstream line_stream;
        line_stream << line;
        std::string point;
        while(std::getline(line_stream, point, ' '))
        {
            try
            {
                coord.push_back(std::stod(point));
            }
            catch (std::invalid_argument){
                cerr<<"wrong data in line "<<i;
                exit(-1);
            }
        }
        if (coord.size() < 2){
            cerr<<"not enough values in line "<<i;
            exit(-1);
        }
        else if (coord.size() > 2){
            cerr<<"too much values in line "<<i;
            exit(-1);
        }
        else
        {
            x_points.push_back(coord[0]);
            y_points.push_back(coord[1]);
        }
    }
    cout<<"correct file"<<endl;

//    for (int i = 0; i < x_arr.size(); ++i) {
//        std::cout<<x_arr[i]<<"   |    "<<y_arr[i]<<std::endl;
//    }

//    std::ifstream myfile(filename);
//    std::fstream f(filename);
//
//
//    while (!f.eof()) {
//        if (f.good()) {
//            f >> x_coord >> y_coord;
//            x_points.push_back(x_coord);
//            y_points.push_back(y_coord);
//        }
//
//    }
//    f.close();
    //int file_arr= read_file(filename,x_points,y_points);


    x_points.push_back(x_points[0]);
    y_points.push_back(y_points[0]);
    for (int i = 0; i < x_points.size(); ++i) {
        cout<<x_points[i]<<"   |    "<<y_points[i]<<endl;
    }

    cout<<2;
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
