#include <iostream>

int main(void) {
    const int NUM = 10;
    int guessed_number;
    std::cout << "adivina un numero entre 1 y 100:\n";
    std::cin >> guessed_number;
    if (guessed_number == NUM) {
        std::cout << "GANASTE!!!!!!!!!!!!!\n";
    } else {
        std::cout << "no ganaste, intentalo de nuevo\n";
    }

    return 0;
}