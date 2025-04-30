#include <iostream>
#include <cmath>
#include <iomanip> 
double pi_aprox (int iteraciones) ; 
int main(void) {
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    std::cout << std::setw(4) << "n" << "  |  " << std::setw(25) << "Pi calculado" <<  "  |  " << std::setw(20) << "Error" << "\n";
    for (int n = 1 ; n <= 20 ; n++) {
        double pi_error = std::abs(1 - pi_aprox(n)/M_PI);
        std::cout << std::setw(4) << n << "  |  " << std::setw(25) << pi_aprox(n) <<  "  |  " << std::setw(20) << pi_error << "\n";
        
    }

    return 0;
}
double pi_aprox (int iteraciones) {
    double n_termino = 0 ;
    
    for ( int k = 0 ; k <= iteraciones ; k++){
          double nf_termino = (1/(std::pow (16,k))) * (4.0/(8*k + 1) - 2.0/(8*k + 4) - 1.0/(8*k + 5) - 1.0/(8*k + 6)) ;
         n_termino = n_termino + nf_termino ;
         
    }
    return n_termino;
 
}



 