#include <cmath>        // Biblioteca matematica estandar de C++
#include <functional>   // Permite usar funciones como objetos (std::function)
#include <fstream>      // Para manejar archivos (ofstream)
#include <iostream>     // Entrada y salida estándar (cout)

// Declaracion y tipos de funciones

// Tipo de puntero funcional que representa una funcion de R en R: f(x)
using fptr = std::function<double(double)>;

// Funciones de integracion numerica
double trapezoid(double a, double b, int N, fptr fun);  // Metodo del trapecio
double simpson(double a, double b, int N, fptr fun);    // Metodo de Simpson (requiere N par)

// Tipo de puntero a funciones de integracion que usen el mismo patron de firma
using intgptr = std::function<double(double, double, int, fptr)>;

// Mejora de precision por extrapolacion de Richardson
double richardson_integral(double a, double b, int N, fptr f, intgptr method, int alpha);

// Funcion a integrar (Definida Abajo)
double f(double x);

int main(int argc, char **argv) {
    std::cout.precision(15);                // Precision de 15 cifras decimales
    std::cout.setf(std::ios::scientific);   // Formato cientifico en consola

    // Definicion del intervalo de integracion y valor exacto (precalculado)
    const double a = -5.0;
    const double b = 5.0;
    const double exact_result = 1.56898093601156;  // ∫ sin(e^x) dx en [-5, 5]

    // Crear archivo de salida para registrar resultados
    std::ofstream file("integration.txt");

    // Barrido sobre N (número de subintervalos) en potencias de 2
    for (double N = 2; N <= 2000000; N *= 2.0) {
        // Cálculo con los métodos simples
        double I_trap = trapezoid(a, b, N, f);
        double I_simp = simpson(a, b, N, f);

        // Calculo usando el metodo de Richardson para mejorar el orden de error
        double trapecio_richardson = richardson_integral(a, b, N, f, trapezoid, 2); // Orden 2 → α = 2
        double simpson_richardson = richardson_integral(a, b, N, f, simpson, 4);    // Orden 4 → α = 4

        // Calculo de errores relativos (medida de precision)
        double error_trap   = std::abs(1.0 - I_trap / exact_result);
        double error_simp   = std::abs(1.0 - I_simp / exact_result);
        double error_trap_r = std::abs(1.0 - trapecio_richardson / exact_result);
        double error_simp_r = std::abs(1.0 - simpson_richardson / exact_result);

        // Guardar los resultados en el archivo
        file << N << " "
             << error_trap << " "
             << error_simp << " "
             << error_trap_r << " "
             << error_simp_r << " "
             << std::endl;
    }

    file.close();  // Cerrar el archivo
    return 0;
}


// Funcion a integrar
// f(x) = sin(e^x)
double f(double x) {
    return std::sin(std::exp(x));  // Esta funcion crece rapidamente en el intervalo [-5, 5]
}

// Metodo del trapecio
// Aproximacion de orden 2
double trapezoid(double a, double b, int N, fptr fun) {
    double Deltax = (b - a) / N;
    double suma = 0.0;

    // Suma de los valores intermedios: f(x₁) + f(x₂) + ... + f(xₙ₋₁)
    for (int k = 1; k <= N - 1; k++) {
        double xk = a + k * Deltax;
        suma += fun(xk);
    }

    // Formula del trapecio compuesta
    double result = Deltax * (0.5 * fun(a) + suma + 0.5 * fun(b));
    return result;
}


// Metodo de simpson
// Aproximacion de orden 4 (N debe ser par)
double simpson(double a, double b, int N, fptr fun) {
    double Deltax = (b - a) / N;
    double suma2k = 0.0;    // Suma de los pares (x₂, x₄, ...)
    double suma2k1 = 0.0;   // Suma de los impares (x₁, x₃, ...)

    for (int k = 1; k <= N/2 - 1; k++) {
        double x2k = a + 2*k*Deltax;
        suma2k += fun(x2k);
    }

    for (int k = 1; k <= N/2; k++) {
        double x2k1 = a + (2*k - 1)*Deltax;
        suma2k1 += fun(x2k1);
    }

    // Formula de Simpson compuesta
    double result = (Deltax / 3) * (fun(a) + 4 * suma2k1 + 2 * suma2k + fun(b));
    return result;
}

// Extrapolacion de richardson para integracion
// Aumenta la precision del método base
// Parametros:
// - alg: metodo base (e.g., trapecio o Simpson)
// - alpha: orden del método base
double richardson_integral(double a, double b, int N, fptr f, intgptr alg, int alpha) {
    double aux = std::pow(2.0, alpha);            // Factor de correccion
    double val1 = alg(a, b, N, f);                // Aproximacion con N
    double val2 = alg(a, b, 2 * N, f);            // Aproximacion con 2N
    return (aux * val2 - val1) / (aux - 1.0);     // Fórmula de Richardson
}
