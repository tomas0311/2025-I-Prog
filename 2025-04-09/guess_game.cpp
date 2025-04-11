            #include <iostream>
            //declaracion de l funcion play
            void play(void); 

                int main(void) {
                    play();
                    

                    return 0;
            }
//implementacion
void play(void)
{
    const int NUM = 10;
                    int guessed_number = NUM + 1;
                    const int MIN = 1;
                    const int MAX = 100;
                    
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
