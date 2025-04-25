#include <iostream>
#include <cmath>
#include <iomanip> 

// codigo aproximación pi 

double pi_aprox(int n) {
    double pi = 0.0;
    for (int k = 0; k < n; ++k) {
        double term = 1.0 / pow(16, k) * (
            4.0 / (8 * k + 1) -
            2.0 / (8 * k + 4) -
            1.0 / (8 * k + 5) -
            1.0 / (8 * k + 6)
        );
        pi += term;
    }
    return pi;
}

int main() {
   
    std::cout << std::setprecision(16);
    std::cout << std::scientific;
    
    for (int n = 1; n <= 20; ++n) {
        double pi_aprox_n = pi_aprox(n);
        double error_relativo = std::abs(1 - pi_aprox_n / M_PI);

        std::cout << "n = " << n << ", pi_aprox(n) = " << pi_aprox_n
                  << ", error relativo = " << error_relativo << std::endl;
    }


    return 0;
}
