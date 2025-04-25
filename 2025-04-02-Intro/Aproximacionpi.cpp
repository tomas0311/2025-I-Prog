#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double pi_aprox(int n) {
    double suma = 0.0;
    for (int k = 0; k <= n; ++k) {
        double denominador = pow(16, k);
        double termino = (4.0 / (8 * k + 1)) - 
                         (2.0 / (8 * k + 4)) - 
                         (1.0 / (8 * k + 5)) - 
                         (1.0 / (8 * k + 6));
        suma += termino / denominador;
    }
    return suma;
}

int main() {
    const double PI_REAL = M_PI;

    cout.precision(16);
    cout.setf(ios::scientific);

    cout << "  n       pi_aprox                error relativo" << endl;
    cout << "-----------------------------------------------" << endl;

    for (int n = 1; n <= 20; ++n) {
        double aproximacion = pi_aprox(n);
        double error_relativo = fabs(1.0 - aproximacion / PI_REAL);

        cout << setw(3) << n << "   "
             << aproximacion << "   "
             << error_relativo << endl;
    }

    return 0;
}
