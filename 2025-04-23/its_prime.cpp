#include <iostream>
#include <cmath>
bool its_prime (long n);
int main(void) {
    std::cout << 2 << ":" << its_prime(2) << "\n";
    std::cout << 10000 << ":" << its_prime(10000) << "\n";
    std::cout << 10000457 << ":" << its_prime(10000457) << "\n";
    return 0;
}
bool its_prime (long n) {
    bool flag = true ;
    if (n <= 1){
        std::cerr << "n esta fuera de rango";    
        return false ;
    }
    if ( n == 2){
        return true ;
    }
    for ( long i = 2 ; i <= std::sqrt(n) ; i++){
        if ( n % i == 0){
            flag = false ;
            break;
        }
    }
    return flag;

}