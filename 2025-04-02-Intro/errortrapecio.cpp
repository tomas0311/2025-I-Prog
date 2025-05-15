#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

const double a = -5.0;
const double b = 5.0;
const double exact_value = 1.56898093601156;

double f(double x) {
    return sin(exp(x));
}

double trapecio(int N) {
    double h = (b - a) / N;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < N; ++i)
        sum += f(a + i * h);
    return h * sum;
}

double simpson(int N) {
    if (N % 2 != 0) N++; // Simpson requiere N par
    double h = (b - a) / N;
    double sum = f(a) + f(b);
    for (int i = 1; i < N; i++) {
        double x = a + i * h;
        sum += (i % 2 == 0 ? 2 : 4) * f(x);
    }
    return (h / 3.0) * sum;
}

double richardson(double I_h, double I_h2, int p) {
    return (pow(2, p) * I_h2 - I_h) / (pow(2, p) - 1);
}

int main() {
    std::ofstream fout("errores_integracion.csv");
    fout << "N,Trapecio,Trapecio+Richardson,Simpson,Simpson+Richardson\n";
    fout << std::setprecision(15);

    for (int N = 2; N <= 2000000; N *= 2) {
        double I_trap = trapecio(N);
        double I_trap2 = trapecio(2 * N);
        double I_simp = simpson(N);
        double I_simp2 = simpson(2 * N);

        double err_trap = std::abs((I_trap - exact_value) / exact_value);
        double err_trap_rich = std::abs((richardson(I_trap, I_trap2, 2) - exact_value) / exact_value);

        double err_simp = std::abs((I_simp - exact_value) / exact_value);
        double err_simp_rich = std::abs((richardson(I_simp, I_simp2, 4) - exact_value) / exact_value);

        fout << N << "," << err_trap << "," << err_trap_rich << "," << err_simp << "," << err_simp_rich << "\n";
    }

    fout.close();
    std::cout << "Datos guardados en errores_integracion.csv" << std::endl;
    return 0;
}
