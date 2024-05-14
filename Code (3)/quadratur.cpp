#include "unit.h"
#include "quadratur.h"
#include <iostream>
double Quadratur_Mittepunkt() {
    double a = 0.1;
    double b = 0.1;
    double epsilon = 0.1;
    getExample(1, a, b, epsilon, false, 300);
    std::cout << a << ' ' << b << ' ' << epsilon << '\n'; 
}

int main() {
    Quadratur_Mittepunkt();
}