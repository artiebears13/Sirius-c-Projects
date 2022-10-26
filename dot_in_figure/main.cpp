#include <iostream>
#include <fstream>
#include <vector>
#include "Line.h"

int solver(std::vector<int> x_points, std::vector<int> y_points, int x[]){
    int cross_counter=0;
    for (int i = 0; i < x_points.size()-2; ++i) {
        int x1 = x_points[i];
        int y1 = y_points[i];
        int x2 = x_points[i+1];
        int y2 = y_points[i+1];
        //std::cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<std::endl;



        Line nowline(x1, y1, x2, y2);
        if (nowline.get_pos(x[0], x[1]) == 1) {
            ++cross_counter;
        }
        if (nowline.get_pos(x[0], x[1]) == 2) {
            cross_counter=-1;
            break;
        }
    }
    return cross_counter;
}


int main(int argc, char ** argv) {
    std::string filename;
    int X,Y;
    try{
        filename = argv[1];
        X = stod(argv[2]);
        Y = stod(argv[3]);
    }
    catch(invalid_argument){
        cerr << "Incorrect arguments formats\n";
        cerr << "Yours: \"" << argv[1] << " "  << argv[2] << " " << argv[3] << "\"\n";
        cerr << "Correct: \"<string> <double> <double>\"\n";
        exit(-1);
    }
    filename="C:\\Users\\ArtMed\\Desktop\\Sirius-c-Projects\\dot_in_figure\\"+filename

    //std::string filename = "C:\\Users\\ArtMed\\Desktop\\Sirius-c-Projects\\dot_in_figure\\file.txt";

    int x_coord, y_coord;
    //int x[2] = {5, 0}; //outside
    int x[2] = {X, Y};
    int cross_counter = 0;
    std::vector<int> x_points;
    std::vector<int> y_points;
    std::vector<int> now_point;

    std::string line;
    std::ifstream myfile(filename);
    std::fstream f(filename);


    while (!f.eof()) {
        f >> x_coord >> y_coord;
        //std::cout<<x_coord<<"  |   "<<y_coord<<std::endl;
        if (f.bad()) {
            std::cout << "Broke" << std::endl;
            f.close();
            exit(-1);
        }
        x_points.push_back(x_coord);
        y_points.push_back(y_coord);
    }
    f.close();
    x_points.push_back(x_points[0]);
    y_points.push_back(y_points[0]);

    cross_counter= solver(x_points,y_points,x);

    std::cout<<cross_counter<<std::endl;
    if (cross_counter==-1){
        std::cout<<"dot is on the border";
    }
    else
    {
        if (cross_counter % 2 == 0) {
            std::cout << cross_counter << " dot is outside" << std::endl;
        } else {
            std::cout << "dot is inside" << std::endl;
        }
    }



    return 0;
}
