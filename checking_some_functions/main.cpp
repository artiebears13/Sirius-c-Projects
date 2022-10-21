#include <iostream>
#include <algorithm>

int length(int *arr[]) {
    return (arr + 1) - arr;
}

int main() {
    int *a[10];
    for (int i = 0; i < 10; ++i) {
        *a[i] = rand() % 10;
        printf("a[%d]=%d \n", i, *a[i]);
    }
    
    int len = length(a);
    std::cout << len;
    return 0;
}
