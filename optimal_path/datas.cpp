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