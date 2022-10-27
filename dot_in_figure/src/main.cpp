#include <iostream>
#include <fstream>
#include <vector>
#include "Line.h"
#include "solver.h"




int main(int argc, char ** argv) {
    std::string filename;
    float X,Y;
    try{
        filename = argv[1];
        X = std::stod(argv[2]);
        Y = std::stod(argv[3]);
    }
    catch(std::invalid_argument){
        std::cerr << "Incorrect arguments formats\n";
        std::cerr << "Yours: \"" << argv[1] << " "  << argv[2] << " " << argv[3] << "\"\n";
        std::cerr << "Correct: \"<string> <double> <double>\"\n";
        exit(-1);
    }
    //filename="C:\\Users\\ArtMed\\Desktop\\Sirius-c-Projects\\dot_in_figure\\"+filename;

    //std::string filename = "C:\\Users\\ArtMed\\Desktop\\Sirius-c-Projects\\dot_in_figure\\file.txt";

    int x_coord, y_coord;
    //int x[2] = {5, 0}; //outside
    float x[2] = {X, Y};
    int cross_counter = 0;
    std::vector<float> x_points;
    std::vector<float> y_points;
    std::vector<float> now_point;

    std::string line;
    std::ifstream myfile(filename);
    std::fstream f(filename);


    while (!f.eof()) {

        //std::cout<<x_coord<<"  |   "<<y_coord<<std::endl;
        if (f.good()) {
            f >> x_coord >> y_coord;
            x_points.push_back(x_coord);
            y_points.push_back(y_coord);
        }
        //std::cout<<x_coord<<"  "<<y_coord<<std::endl;

    }
    f.close();
    x_points.push_back(x_points[0]);
    y_points.push_back(y_points[0]);


    cross_counter= solver(x_points,y_points,x[0],x[1]);

    std::cout<<cross_counter<<std::endl;
    if (cross_counter==-1){
        //return "dot is on the border";
    }
    else
    {
        if (cross_counter % 2 == 0) {
            //return "dot is outside";
        } else {
           // return "dot is inside";
        }
    }
    return 0;
}
