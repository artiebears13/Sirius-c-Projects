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

std::vector<int> get_row(std::string line);