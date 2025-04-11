            #include <iostream>

                int main(void) {
                    const int NUM = 10;
                    int guessed_number = NUM + 1;
                    
                    while (guessed_number != NUM){
                    std::cout << "adivina un numero entre 1 y 100:\n";
                    std::cin >> guessed_number;
                    std::cout << "escribiste " << guessed_number << "\n";
                    if (guessed_number > 100) {
                        std::cout << "DEBE SER UN NUMERO MENOR O IGUAL A 100!!!!" << "\n";
                        continue ;
                    }
                    if (guessed_number < 1) {
                        std::cout << "DEBE SER UN NUMERO MAYOR O IGUAL A 1!!!!" << "\n";
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

                    return 0;
            }