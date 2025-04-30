#include <iostream>
#include <cmath>
#include <string>
#include "prime_utils.h"

int main(int argc, char **argv){
    long num = std::stoi(argv[1]);
    long sum = 0;
    for (long ii = 2 ; ii <= num ; ii++ ){

        if (isprime(ii) == true){
            sum += ii;
        }


    }
  std::cout  << sum << "\n";

}