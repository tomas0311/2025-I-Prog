
#include <cmath>
#include <iostream>
#include <string>

long largest_prime_factor(long n);

long largest_prime_factor(long n) {
    long largest_prime = -1;
    while (n % 2 == 0) {
        largest_prime = 2;
        n /= 2;
    }
    for (long i = 3; i <= std::sqrt(n); i += 2) {
        while (n % i == 0) {
            largest_prime = i;  
            n /= i;
        }
    }
    if (n > 2) {
        largest_prime = n;
    }

    return largest_prime;
}
int main (int argc, char **argv){
    
    long num = std::stol(argv[1]);
    std::cout << "el mayor factor de " << num << " es: " << largest_prime_factor(num) << "\n";

    return 0;
}

