#include <iostream>
#include "parser.h"
#include "errors_processing.h"
#include <vector>
#include <fstream>



int processing(int argc, char **argv, std::string &filename, double &x, double &y){
    auto err_info = parse_arguments(argc, argv, filename, x, y);

    if (int(err_info) < 0)
    {
        std::cerr << "Error parsing command line arguments: " << get_error_name(err_info) << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Successfully parsed command line, filename = "
                    <<filename << ", x = " << x << ", y = " << y << std::endl;
    }

    return 0;
}//
// Created by ArtMed on 29.10.2022.
//

//int read_file(std::string filename, std::vector<double> x_arr, std::vector<double> y_arr){
//
//    double x_coord;
//    double y_coord;
//    std::ifstream myfile(filename);
//    std::fstream f(filename);
//    int i=0;
//
//
//    while (!f.eof()) {
//        i++;
//        if (f.good()) {
//            try {
//            f >> x_coord >> y_coord;
//            x_arr.push_back(x_coord);
//            y_arr.push_back(y_coord);
//            std::cout<<"nice"<<std::endl;
//            }
//            catch (std::invalid_argument){
//                std::cerr<<"incorrect arguments in line "<<i<<std::endl;
//                return -1;
//            }
//        }
//
//    }
//    for (int i = 0; i < x_arr.size(); ++i) {
//        std::cout<<x_arr[i]<<"   |    "<<y_arr[i]<<std::endl;
//    }
//    f.close();
//    return 0;
//}
