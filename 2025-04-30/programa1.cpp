#include <iostream>
#include <cmath>
#include <string>
bool isprime (long n);

int main(int argc, char **argv){
    long num = std::stoi(argv[1]);
    long sum = 0;
    for (long ii = 2 ; ii <= num ; ii++ ){

        if (isprime(ii) == true){
            sum += ii;
        }


    }
  std::cout  << sum << "\n";
  
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