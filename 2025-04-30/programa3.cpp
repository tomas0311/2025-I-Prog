#include <iostream>
#include <cmath>
#include <string>
bool isprime (long n);
int fibonacci (int k);
int main(int argc, char **argv){
    int num = std::stoi(argv[1]);
    std::cout << fibonacci(num) << "\n";
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