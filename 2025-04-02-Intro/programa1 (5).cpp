//se debe ejecutar con isprime.cpp

#include <iostream>
#include <cmath>
//#include "isprime.h"

bool isprime(long n);

int main(int argc, char **argv){

    long int suma = 0;
    int k = std::stoi(argv[1]);

    for(int ii = k; ii >= 1; --ii) {
        if (isprime(ii) == true) {
            //std::cout << ii << ", "; 
            suma = suma + ii; 
        }
    }
    std::cout << "La suma de los primos menores es:" << suma << "\n";
    k=k-1;
}

bool isprime(long n) {
    // precondition checks
    // do something if n <= 1
    if (n <= 1) {
        //std::cerr << "Out of range number: " << n << "\n";
        return false;
    }
    // suppose it is prime
    bool flag = true; 
    if (n == 2) {
        return true;
    }
    // find divisors
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {
        if (n%ii == 0) { // ii is divisor
            flag = false;
            break; // end, at least one divisor
        }
    }
    return flag;
}