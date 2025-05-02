#include <iostream>

bool esPrimo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <numero>\n";
        return 1;
    }

    int limite = std::stoi(argv[1]);
    int suma = 0;

    std::cout << "Número ingresado: " << limite << "\n";

    for (int i = 2; i <= limite; ++i) {
        if (esPrimo(i))
            suma += i;
    }

    std::cout << "La suma de los números primos menores o iguales a " << limite << " es: " << suma << "\n";

    return 0;
}




