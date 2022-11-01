#include <iostream>
#include <vector>
#include <limits>
#include "src/datas.h"
#include "src/plotting.h"

#include "src/min_search.h"


int main(int argc, char **argv) {

    std::string filename = argv[1];
    int n = std::stoi(argv[2]); // dimention rows
    int k = std::stoi(argv[3]);  //dimention columns
    int start = std::stoi(argv[4]); //start number
    int finish_j = std::stoi(argv[5]);//end number
    std::ifstream file(filename);
    std::string line;
    int N = 5;
    Vertice p[n][k];


    // Read file
    int current_line = 0;
    while (std::getline(file, line)) {
        std::vector<int> coordinates;
        coordinates = get_row(line);
        for (int j = 0; j < k; ++j) {
            p[current_line][j].own_weight = coordinates[j];
        }
        ++current_line;
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            p[i][j].visited = false;
            p[i][j].path_weight = std::numeric_limits<int>::max();
            p[i][j].previous = none;
        }
    }
    p[0][start].path_weight = 0;


    output_matrix(&p[0][0], n, k);

    bool end = false;  //end=true if all points was visited
    while (!end) {


//      searching min weight not visited point

        std::pair<int, int> min_ind;
        min_ind = min_search(&p[0][0], n, k);

        //if min_i!=-1 we found min point and can check neighbours
        if (min_ind.first != -1) {

//-----------------checking bottom point (if bottom element exist and not visited and its path_weight>now element path weight + own weight)
            if ((min_ind.first != n - 1)
                && (!p[min_ind.first + 1][min_ind.second].visited)
                && (p[min_ind.first + 1][min_ind.second].path_weight >
                    p[min_ind.first][min_ind.second].path_weight + p[min_ind.first][min_ind.second].own_weight)) {

                p[min_ind.first + 1][min_ind.second].path_weight =
                        p[min_ind.first][min_ind.second].path_weight + p[min_ind.first][min_ind.second].own_weight;
                p[min_ind.first + 1][min_ind.second].previous = up;
            }

//----------------checking right point (if right element exist and not visited and its path_weight>now element path weight + own weight)
            if ((min_ind.second != k - 1)
                && (!p[min_ind.first][min_ind.second + 1].visited)
                && (p[min_ind.first][min_ind.second + 1].path_weight >
                    p[min_ind.first][min_ind.second].path_weight + p[min_ind.first][min_ind.second].own_weight)) {

                p[min_ind.first][min_ind.second + 1].path_weight =
                        p[min_ind.first][min_ind.second].path_weight + p[min_ind.first][min_ind.second].own_weight;
                p[min_ind.first][min_ind.second + 1].previous = left;
            }
//----------------checking left point (if left element exist and not visited and its path_weight>now element path weight + own weight)
            if ((min_ind.second != 0)
                && (!p[min_ind.first][min_ind.second - 1].visited)
                && (p[min_ind.first][min_ind.second - 1].path_weight >
                    p[min_ind.first][min_ind.second].path_weight + p[min_ind.first][min_ind.second].own_weight)) {

                p[min_ind.first][min_ind.second - 1].path_weight =
                        p[min_ind.first][min_ind.second].path_weight + p[min_ind.first][min_ind.second].own_weight;
                p[min_ind.first][min_ind.second - 1].previous = right;
            }

            p[min_ind.first][min_ind.second].visited = true;  //after checked all neighbours dot became visited

        } else {
            end = true;   //if didnt found min = all points visited
        }
    }

    std::cout << std::endl << "PATH WEIGHT:" << p[n - 1][4].path_weight << std::endl;

// -----------output results-----------

    std::pair<std::vector<int>, std::vector<int>> path_back;
    path_back = get_path(&p[0][0], n, k, start, finish_j);
    std::cout << "PATH: ";

    for (int l = path_back.first.size() - 1; l >= 1; --l) {
        std::cout << "(" << path_back.first[l] << "," << path_back.second[l] << ") -> ";
    }
    std::cout << "(" << path_back.first[0] << "," << path_back.second[0] << ")" << std::endl;

    //   to file for plot---------------------------

    std::string file_path = "path.txt";
    std::ofstream my_file;
    my_file.open(file_path);
    my_file.clear();

    for (int l = path_back.second.size() - 1; l >= 0; --l) {
        path_back.first[l] = n - 1 - path_back.first[l];
        my_file << path_back.second[l] << " " << path_back.first[l] << std::endl;
    }
    plot(file_path);

    return 0;
}
