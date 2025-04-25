#include <iostream>
#include <cmath>
#include <iomanip>

double pi_aprox(int n) {
    double sum = 0.0;
    for (int k = 0; k <= n; k++) {
        double term = 1.0 / std::pow(16, k);
        term *= (4.0/(8*k + 1) - 2.0/(8*k + 4) - 1.0/(8*k + 5) - 1.0/(8*k + 6));
        sum += term;
    }
    return sum;
}

int main() {
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    
    std::cout << "n\tAproximacion\t\tError Relativo\n";
    std::cout << "------------------------------------------------\n";
    
    for (int n = 1; n <= 20; n++) {
        double approx = pi_aprox(n);
        double relative_diff = std::abs(1 - approx/M_PI);
        
        std::cout << n << "\t" << approx << "\t" << relative_diff << "\n";
    }
    
    return 0;
}