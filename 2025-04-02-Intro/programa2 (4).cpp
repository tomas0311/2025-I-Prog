#include <iostream>
#include <cmath>
//#include "isprime.h"
//bool isprime(long n);

int main(int argc, char **argv){

    long ultimo_primo = 0;
    long k = std::stol(argv[1]);

    while(k%2==0){
        //std::cout << 2 << "\n";
        ultimo_primo=2;
        k /= 2;
        if(k==1){
            std::cout << "El primo mayor es: "<< ultimo_primo << "\n";
            break;
        }
    }

    for(int i=3;i <= sqrt(k); i += 2){//me interesan solo impares
        while(k%i==0){
            //std::cout << i << "\n";
            ultimo_primo=i;
            k /=i;
        }
        if(k==1){
            std::cout << "El primo mayor es: "<< ultimo_primo << "\n";
            break;
        }
    }

    if(k>2){
        std::cout << "El primo mayor es: "<< k << "\n";
    }

    /*for(long ii = k; ii >= 1; --ii) { //codigo sin optimizar
        std::cout << "I";
        if (isprime(ii) == true) {
            if(k%ii == 0){
                std::cout << "El primo mayor es: "<< ii ;
                break;
            }else{
                std::cout << "C";                
                continue;
            }
        }
    }*/
}

/*bool isprime(long n) {
    // precondition checks
    // do something if n <= 1
    if (n <= 1) {
        std::cerr << "Out of range number: " << n << "\n";
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
}*/