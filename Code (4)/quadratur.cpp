#include "quadratur.h"

   double intergralnew:: evaluate(double (*g)(double), double x, std::map<double, double> &function_values) {
        if (function_values.find(x) == function_values.end()) {
            function_values[x] = g(x);
        }
        return function_values[x];
    }

     double intergralnew:: midpointIntegral(double (*g)(double), double a, double b, std::map<double, double> &function_values) {
        return (b - a) * evaluate(g, (a + b) / 2, function_values);
    }

    double intergralnew:: trapezoidalIntegral(double (*g)(double), double a, double b, std::map<double, double> &function_values) {
        return ((b - a) / 2) * (evaluate(g, a, function_values) + evaluate(g, b, function_values));
    }

    double intergralnew:: simpsonsIntegral(double (*g)(double), double a, double b, std::map<double, double> &function_values) {
        return ((b - a) / 6) * (evaluate(g, a, function_values) + evaluate(g, b, function_values) + 4 * evaluate(g, (a + b) / 2, function_values));
    }

   double intergralnew::recursive(double (*g)(double), double a, double b, double epsilon, std::map<double, double> &function_values) {
        if (std::abs(midpointIntegral(g, a, b, function_values) - trapezoidalIntegral(g, a, b, function_values)) <= epsilon ) {
            return simpsonsIntegral(g, a, b, function_values);
        }
        return recursive(g, a, (a + b) / 2, epsilon / 2, function_values) + recursive(g, (a + b) / 2, b, epsilon / 2, function_values);
    }

    double intergralnew::adaptive(double (*g)(double), double a, double b, double epsilon) {
        std::map<double, double> function_values;
        function_values[a] = g(a);
        function_values[b] = g(b);
        return recursive(g, a, b, epsilon, function_values);
    }
    void main_rountine(){
    bool id = false; 
    int method;
    while (!id)
    {
        std::cout << "Suchen Sie eine id aus (id >= 0) \n";
        std::cin >> method;
        if (method >= 0){
         id = true;
        }
    }
    double a,b,epsilon,result1; 
    getExample(method,a,b,epsilon); 
    result1 = intergralnew::adaptive(f,a,b,epsilon); 
    checkSolution(result1);
    }

    double g(double x) {
        return x; 
    }
    double h(double x) {
        return x*x; 
    }

    int main() {
        main_rountine();
        return 0; 
    }


