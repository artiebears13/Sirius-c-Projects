#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>

int fill(int a, int b)
{
    return a+b;
}

enum prev {
    left,
    right,
    up,
    none
};

struct Vertice {
    bool visited;
    int path_weight;
    int own_weight;
    prev previous;
};






int main(int argc, char** argv) {




    std::string filename=argv[1];
    int n = std::stoi(argv[2]); // dimention
    int start=std::stoi(argv[3]); //start number
    int finish_j=std::stoi(argv[4]);//end number
    std::ifstream file(filename);
    std::string line;
    int N = 5;
    Vertice p[n][n];


    // Read file
    int current_line = 0;
    while(std::getline(file, line))
    {
        std::vector <int> coordinates;
        std::stringstream line_stream;
        line_stream << line;
        std::string point;
        while(std::getline(line_stream, point, ' '))
        {
            try
            {
                coordinates.push_back(std::stoi(point));
            }
            catch (std::invalid_argument){
                return -1;
            }
        }
        for (int j = 0; j < N; ++j){
            p[current_line][j].own_weight = coordinates[j];
        }
        ++current_line;
    }






    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            p[i][j].visited= false;
            p[i][j].path_weight= std::numeric_limits<int>::max();
            p[i][j].previous=none;
        }
    }
    p[0][start].path_weight=0;



std::cout<<"----------MATRIX:------------"<<std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout<<std::endl;
        for (int j = 0; j < n; ++j) {
            std::cout<<p[i][j].own_weight<<" ";
        }

    }
    std::cout<<std::endl<<"---------------------------"<<std::endl;



    bool end=false;  //end=true if all points was visited
    while (!end) {


//      searching min weight not visited point

        int min_weight = std::numeric_limits<int>::max();
        int min_i = -1;  //-1 to detect if min not found
        int min_j = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; ++j) {
                if (!(p[i][j].visited) && (p[i][j].path_weight < min_weight)) {
                    min_weight = p[i][j].path_weight;
                    min_i = i;
                    min_j = j;
                }
            }
        }

        //if min_i!=-1 we found min point and can check neighbours
        if (min_i != -1) {

//-----------------checking bottom point
            if ((min_i != n - 1) && (!p[min_i + 1][min_j].visited)
                && (p[min_i + 1][min_j].path_weight > p[min_i][min_j].path_weight + p[min_i][min_j].own_weight)) {
                p[min_i + 1][min_j].path_weight = p[min_i][min_j].path_weight + p[min_i][min_j].own_weight;
                p[min_i + 1][min_j].previous = up;
            }

//----------------checking right point
            if ((min_j != n - 1) && (!p[min_i][min_j + 1].visited)
                && (p[min_i][min_j + 1].path_weight > p[min_i][min_j].path_weight + p[min_i][min_j].own_weight)) {
                p[min_i][min_j + 1].path_weight = p[min_i][min_j].path_weight + p[min_i][min_j].own_weight;
                p[min_i][min_j + 1].previous = left;
            }
//----------------checking left point
            if ((min_j != 0) && (!p[min_i][min_j - 1].visited)
                && (p[min_i][min_j - 1].path_weight > p[min_i][min_j].path_weight + p[min_i][min_j].own_weight)) {
                p[min_i][min_j - 1].path_weight = p[min_i][min_j].path_weight + p[min_i][min_j].own_weight;
                p[min_i][min_j - 1].previous = right;
            }

            p[min_i][min_j].visited = true;  //after checked all neighbours dot became visited

        } else {
            end = true;   //if didnt found min = all points visited
        }
    }

    std::cout<<std::endl<<"PATH WEIGHT:"<<p[n-1][4].path_weight<<std::endl;

// -----------output results-----------


int i=n-1;
int j=finish_j;
std::vector<int> path_X;
std::vector<int> path_Y;
    while (i!=0 || j!=start){
        path_X.push_back(i);
        path_Y.push_back(j);
        switch (p[i][j].previous) {
            case up:
                i-=1;
                break;
            case right:
                j+=1;
                break;
            case left:
                j-=1;
                break;
        }
    }
    path_X.push_back(i);
    path_Y.push_back(j);
    std::cout<<"PATH: ";
    for (int k = path_Y.size()-1; k >= 1; --k) {
        std::cout<<"("<<path_X[k]<<","<<path_Y[k]<<") -> ";
    }
    std::cout<<"("<<path_X[0]<<","<<path_Y[0]<<")"<<std::endl;


//    for (int i = 0; i < n; ++i) {
//        std::cout<<std::endl;
//        for (int j = 0; j < n; ++j) {
//            std::cout<<p[i][j].previous<<" ";
//        }
//
//    }
//
//
//    for (int i = 0; i < n; ++i) {
//        std::cout<<std::endl;
//        for (int j = 0; j < n; ++j) {
//            std::cout<<p[i][j].path_weight<<" ";
//        }
//
//    }

//-------------------
    return 0;
}
