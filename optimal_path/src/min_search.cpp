#include "datas.h"
#include <limits>



std::pair<int,int> min_search(Vertice *p, int n,int k) {
    int min_weight = std::numeric_limits<int>::max();
    std::pair<int,int> min_indexes;
    min_indexes.first = -1;  //-1 to detect if min not found
    min_indexes.second = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; ++j) {
            if (!(p[i*n+j].visited) && (p[i*n+j].path_weight < min_weight)) {
                min_weight = p[i*n+j].path_weight;
                min_indexes.first = i;
                min_indexes.second = j;
            }
        }
    }

    return min_indexes;
}