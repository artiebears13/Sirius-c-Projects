#include <iostream>

void print_matrix(int **a, int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<std::endl;

    }
}

int main() {
    int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int n=3;
    auto ptr_a=**a;
    print_matrix(ptr_a,n);
    return 0;
}
