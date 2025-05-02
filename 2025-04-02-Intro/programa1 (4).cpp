
#include <cmath>
#include <iostream>
#include <string>

bool isprime (long n);

bool isprime (long n){
    bool flag = true;
    if (n == 2) {
        return true;
    }
    if (n % 2==0) {
        return false;
    }
    for (long ii = 3; ii <= std::sqrt(n) + 1; ii+=2) {
        if (n%ii == 0) { 
            flag = false;
            break; 
        }
    }

    return flag;
}

int main(int argc, char **argv){
    int num = std::stoi(argv[1]);
    long suma = 0;
    for(int ii = 0; ii <= num; ++ii) {
        if (isprime(ii) == true) {
            suma += ii;    
        }
    }
    std::cout << "la suma es: " << suma << "\n";

    return 0;
}



