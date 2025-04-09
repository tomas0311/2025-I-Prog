#include <iostream>
#include <string>


int main(void) {
    std::string nombre;
    std::cout <<"¿Cual es tu nombre?\n";
    std::getline (std::cin,nombre);
    std::cout << "Hola, " << nombre << "\n";  
    return 0;
}