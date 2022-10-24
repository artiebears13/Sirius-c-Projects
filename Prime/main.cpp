#include <iostream>
#include "math.h"

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
    int start= 2;
    int end = 10000;
    std::cout <<std::endl<<"Primes in Ranges : "<<countPrimes(start,end);
    return 0;
}
