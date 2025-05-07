#include <iostream>
#include <cmath>
#include <fstream>
bool isprime (long n);
int nth_twin_primes (int n);
int main (void){
    std::ofstream file("norm_twins_prime.txt");
    for (int ii = 1; ii <= 100; ii++){
        double norm = std::sqrt ((nth_twin_primes(ii)*nth_twin_primes(ii))+((nth_twin_primes(ii)+2)*(nth_twin_primes(ii)+2)));
        file << ii << " "
             << norm << "\n";
    }
    file.close();
    return 0;
}
int nth_twin_primes (int n){
    int ii = 0;
    int kk = 2;
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
    return kk;
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
