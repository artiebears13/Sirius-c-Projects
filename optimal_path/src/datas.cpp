#include <iostream>
#include "datas.h"
#include <vector>
#include <fstream>
#include <sstream>

std::vector<int> get_row(std::string line) {
    std::stringstream line_stream;
    line_stream << line;
    std::vector<int> coordinates;
    std::string point;
    while (std::getline(line_stream, point, ' ')) {
        try {
            coordinates.push_back(std::stoi(point));
        }
        catch (std::invalid_argument) {
            exit(-1);
        }
    }
    return coordinates;
}

void output_matrix(Vertice *p, int n, int k){

    std::cout<<"----------MATRIX:------------"<<std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout<<std::endl;
        for (int j = 0; j < k; ++j) {
            std::cout<<p[i*n+j].own_weight<<" ";
        }
    }
    std::cout<<std::endl<<"---------------------------"<<std::endl;
}


std::pair<std::vector<int>, std::vector<int>> get_path(Vertice *p, int n, int k, int start,int finish_j) {

    int i = n - 1;
    int j = finish_j;
    std::vector<int> path_X;
    std::vector<int> path_Y;
    while (i != 0 || j != start) {
        path_X.push_back(i);
        path_Y.push_back(j);
        switch (p[i*n+j].previous) {
            case up:
                i -= 1;
                break;
            case rright:
                j += 1;
                break;
            case lleft:
                j -= 1;
                break;
        }
    }
    path_X.push_back(i);
    path_Y.push_back(j);
    std::cout << "PATH: ";
    std::pair<std::vector<int>, std::vector<int>> results;
    results.first=path_X;
    results.second=path_Y;

    return results;
}