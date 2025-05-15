#include <iostream>
#include <fstream>
#include <cmath>
#include <functional> 

//Declaracion

using fptr = std::function<double(double)>;

double trapezoid(double a, double b, int n, fptr f); // Declaracion funcion trapezoid
double simpson(double a, double b, int n, fptr f); // Declaracion funcion simpson

using algptr = std::function<double(double, double, int, fptr)>;

double richardson(double a, double b, int n, fptr f, algptr alg, int alpha); // Declaracion extrapolacion de Richardson

//Implementacion

double trapezoid(double a, double b, int n, fptr f){ // Implementacion de la funcion-meotodo trapezoid

    double delta = (b-a)/n;
    double f_0 = (f(a))/2;
    double f_n = (f(b))/2;
    double S = 0.0;
    for (int k = 1; k <= n-1; k++){
        double xk = a + k*delta;
        S += f(xk);
    } 
    return delta*(f_0+S+f_n);

}

double simpson(double a, double b, int n, fptr f){ // Implementacion de la funcion-emtodo simpson

    if (n % 2 != 0 ){ // verificacion de paridad de n para el metodo simpson
        n += 1;
    }
    double delta = (b-a)/n;
    double f_0 = f(a);
    double f_n = f(b);
    double S1 = 0.0;
    for (int k = 1; k <= n/2; k++){
        double x2k1 = a + ((2*k)-1)*delta;
        S1 += f(x2k1);
    } 
    double S2 = 0.0;
    for (int k = 1; k <= (n/2)-1; k++){
        double x2k = a + (2*k)*delta;
        S2 += f(x2k);
    }

    return (delta/3)*(f_0+(4*S1)+(2*S2)+f_n);

}

double richardson(double a, double b, int n, fptr f, algptr alg, int alpha) // Implementacion de extrapolacion de Richardson adaptada a los metodos de integracion
{
    double aux = std::pow(2.0, alpha);
    double val1 = alg(a, b, n, f);
    double val2 = alg(a, b, n*2.0, f);
    return (aux*val2 - val1)/(aux - 1.0);
}

//Main

double f(double x);

int main(void){
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);
    const double a = -5.0; // Extremo izquierdo del intervalo de integracion
    const double b = 5.0; // Extremo derecho del intervalo de integracion
    double exact_result = 1.56898093601156; // Valor exacto de la integral de sen(e^x): [-5.0 , 5.0]

    //std::cout << trapezoid(a, b, n, f) << "\n";
    //std::cout << simpson(a, b, n, f) << "\n";

    std::ofstream file("integration.txt"); // Para enviar los datos a un archivo .txt

    for(double n = 2.0; n <= 2.0e6; n *= 10.0){ // Inicio del bucle donde  2 < n < 2.0e⁶ 

    double trapezoid_result= trapezoid(a, b, n, f);
    double simpson_result = simpson(a, b, n, f);
    double richardson_trapezoid_result = richardson(a, b, n, f, trapezoid, 2);
    double richardson_simpson_result = richardson(a, b, n, f, simpson, 4);
    double error_trapezoid = std::abs(1.0 - (trapezoid_result/exact_result));
    double error_simpson = std::abs(1.0-(simpson_result/exact_result));
    double error_richardson_trapezoid = std::abs(1.0-(richardson_trapezoid_result/exact_result));
    double error_richardson_simpson = std::abs(1.0-(richardson_simpson_result/exact_result));

    file        << n << " \t " // se usa \t para separar las columnas de datos y que se ve mas limpio
                << error_trapezoid << " \t  " 
                << error_simpson << " \t  " 
                << error_richardson_trapezoid << "\t  " 
                << error_richardson_simpson << "\n";
    }    
    file.close();
    return 0;
}

double f(double x){ // funcion a integrar
    return std::sin(std::exp(x));
}
