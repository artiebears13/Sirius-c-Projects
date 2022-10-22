#include <iostream>
#include <algorithm>

int length(int arr[]) {
    std::cout << "func"<<std::endl;

    int asize = sizeof(arr);
    int a1size = sizeof(arr[0]);
    std::cout<<"asize: "<<asize<<"      |       "<<a1size<<std::endl;
    int len=(asize/a1size);
    return len;
}

int main() {
    int a[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = rand() % 10;
        printf("a[%d]=%d \n", i, a[i]);
    }
    std::cout<<sizeof(a)<<"      |       "<<sizeof(a[0])<<std::endl;

    int len = length(a);
    std::cout << "size of a: " << len;
    return 0;
}
