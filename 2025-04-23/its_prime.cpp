#include <iostream>
#include <cmath>
bool isprime (long n);
int main(void) {
    std::cout << 2 << ":" << isprime(2) << "\n";
    std::cout << 10000 << ":" << isprime(10000) << "\n";
    std::cout << 10000457 << ":" << isprime(10000457) << "\n";
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

