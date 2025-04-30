#include <iostream>
#include <cmath>
#include <string>
bool isprime (long n);
long primefactor (long k);
int main(int argc, char **argv){
    long num = std::stol(argv[1]);
    std::cout << primefactor(num) << "\n";
    return 0;
} 

bool isprime (long n){
    bool flag = true;
    if (n <= 1) {
        std::cerr << "Out of range number: " << n << "\n";
        return false;
    }
    if (n == 2){
        return true;
    }
    for (long ii = 2 ; ii <= std::sqrt(n) ; ii++){
        if (n%ii == 0){
            flag = false;
            break;
        }

    }
    return flag;
}

long primefactor (long k){
    if (isprime(k) == true){
        return k;
    }
    long factor = 2;
    long pp = 1;
    long kk = k;
    while (kk / pp != 1){
        long div = 2;
        for(long nn = 2; nn <= std::sqrt(kk); nn++){
            if (kk%nn == 0 and isprime(nn) == true){
                div = nn;
                break;
            }
        }
        kk = kk / div;
        if (isprime(kk) == true){
            pp = kk;
        } 
        else {
            for(long nn = 2; nn <= std::sqrt(kk); nn++){
                if (kk%nn == 0 and isprime(nn) == true){
                pp = nn;
                break;        
                }
            }
        }
    }
    factor = kk;
    return factor;
}
