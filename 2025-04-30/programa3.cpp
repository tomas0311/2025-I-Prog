#include <iostream>
#include <cmath>
#include <string>
int fibonacci (int k);
int sum(int n);
int main(int argc, char **argv){
    int num = std::stoi(argv[1]);
    if (num < 2){
        std::cout << "Numero fuera de rango:" << num << "\n";
    }
    else {
        std::cout << sum(num) << "\n";
    }    
}
int fibonacci (int k){
    if (k == 1){
        return 1;
    }
    if (k == 2){
        return 2;
    }
    int ii = 3;
    int n_a = 1;
    int n_b = 2;
    while ( ii <= k){
        int n_f = n_a + n_b;
        n_a = n_b;
        n_b =n_f;   
        ii++;
    }
    return n_b;
}
int sum (int n){
    int suma = 0;
    for ( int ii = 1; fibonacci(ii) <= n ; ii++){
        if(fibonacci(ii)%2 != 0){
            suma += fibonacci(ii);
        }
    }
    return suma;
}
    