#include <iostream>
#include <cmath>
#include <string>


bool isimpar (long k);
int sumimpares(int n);

bool isimpar (long k){

    return k % 2 != 0;
}

int sumimpares (int n) {
    int suma = 0;
    int a=0;
    int b=1;
    int fibonacci=a+b;
    while (fibonacci<=n){
        if (isimpar(fibonacci)){
            suma += a;
        }
        a=b;
        b=fibonacci;
        fibonacci=a+b;
    }
    return suma;
}


int main (int argc, char ** argv){
 
    int num = std::stoi(argv[1]);
    if (num < 2){
        std::cerr<<"El numero debe ser mayor o igual a 2 \n";
        return 0;
    }
    int sum = sumimpares(num);

    std::cout << "Suma de los impares en Fibonacci: " << sum << "\n";

    return 0;
}
