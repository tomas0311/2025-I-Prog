#include <iostream>
#include <cstdlib> // Para std::stol
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <numero>" << endl;
        return 1;
    }

    long numero = stol(argv[1]);
    long mayorFactorPrimo = 0;
    long divisor = 2;

    while (numero > 1) {
        if (numero % divisor == 0) {
            mayorFactorPrimo = divisor;
            numero /= divisor;
        } else {
            divisor++;
            if (divisor * divisor > numero && numero > 1) {
                mayorFactorPrimo = numero;
                break;
            }
        }
    }

    cout << mayorFactorPrimo << endl;

    return 0;
}