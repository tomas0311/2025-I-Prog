#include <iostream>
#include <cmath>

int main(int argc, char **argv){

    long k = std::stol(argv[1]);
    int two = 1;
    int one = 0;
    long e = 0;
    long suma = 0;

    for(long ii = 1; ii <= k; ++ii) {
        e=one+two;
        //std::cout << e <<"\n";//aaaaaaaaaaaaaaaa
        one=two;
        two=e;

        if(e>k){
        std::cout << "La suma de los impares de Fibonacci menores al numero es: "<< suma <<"\n";
            break;
        }
        
        if(e%2!=0){
            suma=suma+e;
        }
    }
}