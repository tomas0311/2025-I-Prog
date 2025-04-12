#include <iostream>
#include <random>
//declaracion de l funcion play
void play( int min_val, int max_val); 

int main(void) {
    play( 1 ,100);
    play( 1 ,1000);
    

    return 0;
}
//implementacion
void play( int min_val, int max_val)
{
    std::cout << "Empieza el juego \n";
    const int MIN = min_val;
    const int MAX = max_val;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>
    distrib (MIN , MAX);
    const int NUM = distrib(gen);
    int guessed_number = NUM + 1;
    
    while (guessed_number != NUM){
    std::cout << "adivina un numero entre " << MIN << " y " << MAX << ":\n";
    std::cin >> guessed_number;
    std::cout << "escribiste " << guessed_number << "\n";
    if (guessed_number > MAX) {
        std::cout << "DEBE SER UN NUMERO MENOR O IGUAL A " << MAX << "!!!!" << "\n";
        continue ;
    }
    if (guessed_number < MIN) {
        std::cout << "DEBE SER UN NUMERO MAYOR O IGUAL A " << MIN << "!!!!" << "\n";
        continue ;
    }
    if (guessed_number == NUM) {
        std::cout << "GANASTE!!!!!!!!!!!!!\n"; 
    } else if (guessed_number > NUM) {
        std::cout << "Te pasaste.\n";
    }
        else {// es menor
        std::cout << "Te falto.\n";
    }
    }
}
