#include <iostream>
#include <cmath>
#include <string>
bool isprime (long n);
int nth_twin_primes (long n);
int main (void){
    nth_twin_primes(5098);
    return 0;
}
int nth_twin_primes (long n){
    long ii = 0;
    long kk = 2;
    while (ii != n){
        if (isprime(kk) == true and isprime (kk+2) == true){
            ii++;
            if (ii == n){
                break;
            }
            kk++;
        } else {
            kk++;
        }      
    }
    std::cout << "(" << kk << "," << kk+2 << ")" << "\n" ;
    return 0;
}
  
bool isprime(long n) {
    if (n <= 1) {
        std::cerr << "Out of range number: " << n << "\n";
        return false;
    }
    bool flag = true; 

    if (n == 2) {
        return true;
    }
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {
        if (n%ii == 0) {
            flag = false;
            break; 
        }
    }

    return flag;
}
