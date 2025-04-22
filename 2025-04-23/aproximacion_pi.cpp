#include <iostream>
#include <cmath>
double pi_aprox (int iteraciones) ; 
int main(void) {
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    std::cout <<  pi_aprox(5) << "\n";

    return 0;
}
double pi_aprox (int iteraciones) {
    double n_termino = 0 ;
    
    for ( int n = 0 ; n < iteraciones ; n++){
          double nf_termino = (1/(std::pow (16,n))) * (4.0/(8*n + 1) - 2.0/(8*n + 4) - 1.0/(8*n + 5) - 1.0/(8*n + 6)) ;
         n_termino = n_termino + nf_termino ;
         
    }
    return n_termino;
 
}



 