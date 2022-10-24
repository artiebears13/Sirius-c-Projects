#include <iostream>
#include "math.h"
#include <chrono>
#include <vector>
//#include "Eratosfen.h"

bool isprime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i*i<=num; i++) {
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

std::vector<int> get_primes(int n)
{
    std::vector<bool> is_prime(n, true);
    std::vector<int> primes;
    for (int i=2; i<=n; i++) {
        if (is_prime[i])
        {
            primes.push_back(i);
            if (i*i<=n)
                for (int j = 2*i; j <= n ; j+=i) {
                    is_prime[j]= false;

                }
        }

    }
    return primes;
}



int main() {
    int first= 2;
    int last = 100000;

    auto start = std::chrono::steady_clock::now();
    std::cout <<std::endl<<"Primes in Ranges : "<<countPrimes(first,last)<<std::endl;

    auto end = std::chrono::steady_clock::now();
    auto elapsed = end - start;
    std::cout << "Time = " << std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count() / 1e9 << " seconds" << std::endl;


    start = std::chrono::steady_clock::now();
    std::cout <<std::endl<<"Primes in Ranges : "<<get_primes(last).size()<<std::endl;

    end = std::chrono::steady_clock::now();
    elapsed = end - start;
    std::cout << "Time = " << std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count() / 1e9 << " seconds" << std::endl;



    return 0;
}
