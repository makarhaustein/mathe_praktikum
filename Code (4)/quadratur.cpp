#include "quadratur.h"
#include "unit.h"
#include <cmath>
#include <iostream>
#include <math.h>

double Mittelpunktsregel(double a, double b) { return f((a + b) / 2); }

double Adaptives_Zerlegen(double a, double b, double f_a, double f_b,
                          double f_mpr, double epsilon, long local_depth,
                          long *max_depth) {
    if (fabs((b-a)*(f_mpr - (f_a + f_b) / 2)) < epsilon) {
        if (local_depth > *max_depth) 
            *max_depth = local_depth;
        return (b-a)*((f_a + f_b) / 6 + 4 * f_mpr / 6);
    } else {
        double mid = (a + b) / 2;
        return Adaptives_Zerlegen(a, mid, f_a, f_mpr, Mittelpunktsregel(a, mid),
                                  epsilon / 2, local_depth + 1, max_depth)  +
               Adaptives_Zerlegen(mid, b, f_mpr, f_b, Mittelpunktsregel(mid, b),
                                  epsilon / 2, local_depth + 1, max_depth) ;
    }
}

void Quadratur() {
    double a{};
    double b{};
    double epsilon{};
    std::cout << "Id der Funktion dessen Integral approximiert werden soll: ";
    int id{};
    std::cin >> id;
    getExample(id, a, b, epsilon, true, 300);
    std::cout << a << " " << b << ' ' << ' ' << epsilon << '\n';
    long max_depth{0};
    double approx{Adaptives_Zerlegen(a, b, f(a), f(b), Mittelpunktsregel(a, b),
                                     epsilon, 1, &max_depth)};
    std::cout << "Bei Äquidistanter Schrittweite sind insgesamt "
              << std::pow(2, max_depth) + 1
              << " Funktionsauswertungen notwendig.\n";
    checkSolution(approx);
}

int main() { Quadratur(); }