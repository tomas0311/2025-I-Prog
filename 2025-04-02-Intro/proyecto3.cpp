// programa3.cpp
#include <iostream>
#include <cstdlib> // Para usar atoi

int main(int argc, char* argv[]) {
    // Verificar que se haya pasado un argumento
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <entero n >= 2>\n";
        return 1;
    }

    int n = std::atoi(argv[1]);

    if (n < 2) {
        std::cerr << "El número debe ser mayor o igual a 2.\n";
        return 1;
    }

    int a = 1, b = 2; // Los dos primeros términos
    int sumaImpares = 0;

    // Evaluar a (1) y b (2) antes de iterar
    if (a % 2 != 0 && a <= n) sumaImpares += a;
    if (b % 2 != 0 && b <= n) sumaImpares += b;

    while (true) {
        int siguiente = a + b;
        if (siguiente > n) break;

        if (siguiente % 2 != 0) {
            sumaImpares += siguiente;
        }

        a = b;
        b = siguiente;
    }

    std::cout << sumaImpares << std::endl;

    return 0;
}