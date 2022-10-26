#include <iostream>
#include <algorithm>
#include <array>
#include "square_solver.h"

inline int length(int arr[]) {
    std::cout << "func" << std::endl;


    int asize = sizeof(arr);
    int a1size = sizeof(arr[1]);
    std::cout << "asize: " << asize << "      |       " << a1size << std::endl;
    int len = (asize / a1size);
    return len;
}

void increnent(int *a) {
    ++*a;
}

int main() {
    /*int a[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = rand() % 10;
        printf("a[%d]=%d \n", i, a[i]);
    }
*/
     //std::cout<<sizeof(a)<<"      |       "<<sizeof(a[0])<<std::endl;
    // std::array<int,5> myints;
    //std::cout<<"size of myints: " << myints.size() << std::endl;
   // int len = length(a);
   // std::cout << "size of a: " << len;

    //int j = 10;
    //increnent(&j);
    //std::cout << "increment: " << j;
    square_solver(1,-7,12);

    return 0;
}
