#include <iostream>
#include "is_prime.h"

int main() {
    std::cout << "Enter a number: ";
    int typed;
    std::cin >> typed;

    if (is_prime(typed)) {
        std::cout << typed << " is prime" << std::endl;
    } else {
        std::cout << typed << " is not prime" << std::endl;
    }
    return 0;
}