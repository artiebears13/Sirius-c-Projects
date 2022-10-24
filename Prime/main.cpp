#include <iostream>
#include "math.h"
#include <chrono>

bool isprime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) { return false; }
    }
    return true;
}

int countPrimes(int start,int end){
    int count=0;
    for(int i=start;i<=end;i++){
        if(isprime(i)==1)
        { count++; }
    }
    return count;
}

int main() {
    int first= 2;
    int last = 100000;
    auto start = std::chrono::steady_clock::now();
    std::cout <<std::endl<<"Primes in Ranges : "<<countPrimes(first,last)<<std::endl;

    auto end = std::chrono::steady_clock::now();    auto elapsed = end - start;
    std::cout << "Time = " << std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count() / 1e9 << " seconds" << std::endl;

    return 0;
}
