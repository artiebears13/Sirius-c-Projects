#include <vector>
#include <fstream>
#include <sstream>
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

void output_matrix(Vertice *p, int n, int k);
std::vector<int> get_row(std::string line);
std::pair<std::vector<int>, std::vector<int>> get_path(Vertice *p, int n, int k, int start, int finish_j);