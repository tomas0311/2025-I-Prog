#include <fstream>
#include <functional>
#include <iostream>
#include <cmath>

using fptr = std::function <double(double)>;
using algptr = std::function< double(double,double,int, fptr)>;
double simpson (double a, double b, int n, fptr f);
double trapezoid (double a, double b, int n, fptr f);
double integration_richardson(fptr f, algptr alg, double a, double b, int n,  int alpha);
double f(double x );

int main(void) {
    double I_EXACTA = 1.56898093601156;
    std::ofstream file("integration(sin(ex)).txt");
    file.precision(15);
    file.setf(std::ios::scientific);
    const int steps = 30;
    for (int i = 0; i < steps; ++i) {
    double ii = 2 * std::pow(10, 6.0 * i / (steps - 1)); 
    double ERR_TRAP = std::abs(1 - trapezoid(-5, 5, ii , f) / I_EXACTA) ;
    double ERR_SIMP = std::abs(1 - simpson(-5, 5, ii , f) / I_EXACTA) ;
    double ERR_TRAP_RICH = std::abs(1 - integration_richardson(f , trapezoid , -5 , 5 , ii , 2) / I_EXACTA) ;
    double ERR_SIMP_RICH = std::abs(1 - integration_richardson(f , simpson , -5 , 5 , ii , 2) / I_EXACTA) ;
    file << ii << " "
         <<  ERR_TRAP << " "
         <<  ERR_SIMP << " "
         <<  ERR_TRAP_RICH << " "
         <<  ERR_SIMP_RICH << "\n";        
}
}
double simpson (double a, double b, int n, fptr f){
    if (n%2 != 0){
        n = n+1;
    }
    double sum = 0;
    double sum_1 = 0;

    double delta = (b-a)/n;
    for( int ii = 1 ; ii <= (n/2 - 1); ii++){
        double x_k = a + 2*ii*delta;
        sum += f(x_k);
    }
     for( int ii = 1 ; ii <= (n/2); ii++){
        double x_k = a + (2*ii-1)*delta;
        sum_1 += f(x_k);
    }
    double result = delta/3*(f(a) + 4 * sum_1 + 2* sum + f(b));
    return result;
}
double trapezoid (double a, double b, int n, fptr f){
    double sum = 0;
    double delta = (b-a)/n;
    for( int ii = 1 ; ii < n; ii++){
        double x_k = a + ii*delta;
        sum += f(x_k);
    }
return delta*(f(a)/2 + sum + f(b)/2);
}
 double f(double x){
    return std::sin(std::exp(x));
 }
 double integration_richardson(fptr f, algptr alg, double a, double b, int n,  int alpha){
    double aux = std::pow(2.0, alpha);
    double val1 = alg(a , b , n , f);
    double val2 = alg(a , b,  2*n , f);
    return (aux*val2 - val1)/(aux - 1.0);
 }