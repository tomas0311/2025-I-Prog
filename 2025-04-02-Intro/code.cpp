#include <functional>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>

// using fptr = double(double);
using fptr = std::function<double(double)>;

// trapezoid(0.0, 1.0, 10, fun)
double trapezoid(double a, double b, int N, fptr fun);

double simpson(double a, double b, int N, fptr fun);

double ri_tr(double a,double b ,double N, fptr fun );

double ri_si(double a,double b ,double N, fptr fun );

double f(double x);

int main(void){
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);
    double valor_real = 1.56898093601156;
    
  
    std::ofstream file("integration.txt");
    file << std::scientific << std::setprecision(15);

    for(int N = 2; N <= 2000000; N = N*2 ) {
        double trapezoid_result = trapezoid(-5.0, 5.0, N, f);
        double simpson_result = simpson(-5.0, 5.0, N, f);
        double richardson_trapezoid_result = ri_tr(-5.0, 5.0, N, f);
        double richardson_simpson_result = ri_si(-5.0, 5.0, N, f);
        double error_trapezoid = std::abs(1.0 - (trapezoid(-5.0, 5.0, N, f)/valor_real));
        double error_simpson = std::abs(1.0 - ((simpson(-5.0, 5.0, N, f))/valor_real));
        double error_trapezoid_r = std::abs(1.0 - ((ri_tr(-5.0, 5.0, N, f))/valor_real));
        double error_simpson_r = std::abs(1.0 - ((ri_si(-5.0, 5.0, N, f))/valor_real));
        file << valor_real << " " 
                << N << " "
                << trapezoid_result << " "
                << simpson_result << " "
                << error_trapezoid << " "
                << error_simpson << " "
                << error_trapezoid_r << " "
                << error_simpson_r << " "
                << std::endl;
    }
    file.close();

    
    return 0;
}


double f(double x){
    return std::sin(std::exp(x));
  
}

double trapezoid(double a, double b, int N, fptr fun)
{
    double Deltax = (b-a)/N;
    double suma = 0.0;
    for(int k = 1; k <= N-1; k++) {
    //for(int k = N-1; k >= 1; k--) {
        double xk = a + k*Deltax;
        suma = suma + fun(xk);
    } 
    double result = Deltax*(0.5*fun(a) + suma + 0.5*fun(b));
    return result;
}

double simpson(double a, double b, int N, fptr fun){
    double Deltax = (b-a)/N;
    double suma = 0.0;
    double suma2 = 0.0;
    double xN = a + N*Deltax;
    if(N%2 == 0){
        for(int k = 1; k <= N/2; k++){
            double i = (2*k)-1;
            double xi = a + i*Deltax ;
            suma = suma + fun(xi);
        }
        for(int k = 1; k <= (N/2)-1; k++ ){
            double i = 2*k;
            double xi = a + i*Deltax;
            double xN = a + N*Deltax;
            suma2 = suma2 + fun(xi) ;
        }
        

    }
    double result = (((b-a)/N)/3)*(fun(a)+ 4*suma + 2* suma2 + fun(xN));
    return result; 
}

double ri_tr(double a,double b ,double N, fptr fun ){
    double IH = trapezoid( a,  b,  N, fun);
    double IHhalf = trapezoid( a,  b,  2* N, fun);
    double result = (4 * IHhalf - IH)/3;
    return result;
    
}

double ri_si(double a,double b ,double N, fptr fun ){
    double IH = trapezoid( a,  b,  N, fun);
    double IHhalf = trapezoid( a,  b,  2* N, fun);
    double result = (16 * IHhalf - IH)/15;
    return result; 

}