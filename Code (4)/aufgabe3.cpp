#include "aufgabe3.h"
#include <iostream>
#include <cmath>

std::tuple<double,double> evaluate(double (*g)(double x), double a, double b, std::vector<double> &evaluated_values, std::vector<double> &positions, std::vector<int>&counter) {
    int index_a = -1, index_b = -1; 
    double value_a, value_b;
    if((evaluated_values.size() == 0 ) || (positions.size() == 0 )) {
        std:: cout << "Empty arrays" << std:: endl; 
        return std:: make_tuple(0,0); 
    }
    for (unsigned int i = 0; i < positions.size(); i++) {
        if (positions[i] == a) {
            index_a = i;
        } else if (positions[i] == b) {
            index_b = i;
        }
        if ((index_a != -1) && (index_b != -1)) {
            break; 
        }
    }
    if (index_a != -1) {
        value_a = evaluated_values[index_a]; 
    } else {
        value_a = g(a); 
        counter[0] += 1; 
        positions.push_back(a); 
        evaluated_values.push_back(value_a); 
    }
    if (index_b != -1) {
        value_b = evaluated_values[index_b]; 
    } else {
        value_b = g(b); 
        counter[0] += 1; 
        positions.push_back(b); 
        evaluated_values.push_back(value_b); 
    }
    return std::make_tuple(value_a, value_b); 
}

double mittlepunktIntegral(double (*g)(double x), int n, double a, double b, std::vector<double> &evaluated_values, std::vector<double> &positions,std::vector<int>&counter ,double h  = -1) {
    std::tuple<double,double> values = evaluate(g, (a + b) / 2, b, evaluated_values, positions, counter);  
    double sum = 0; 
    if(h== -1){
        h = (b-a)/n; 
    }
    if (n <= 1) { 
         return h * std::get<0>(values); 
    } 
    for (int i = 1; i < n; i++) {
        values = evaluate(g, a+i*h-h/2, b, evaluated_values, positions,counter);
        sum += std::get<0>(values) * h; 
    }
     return sum; 
} 

double trapezIntegral(double (*g)(double x), int n, double a, double b, std::vector<double> &evaluated_values, std::vector<double> &positions,std::vector<int>&counter ,double h = -1) {
    if(h== -1){
        h = (b-a)/n; 
    }
    std::tuple<double,double> values = evaluate(g, a, b, evaluated_values, positions, counter); 
    double sum = 0.5 * (std::get<0>(values) + std::get<1>(values)); 

    if (n > 1) {
        for (int i = 1; i < n; i++) {
            values = evaluate(g, a + i * h, b, evaluated_values, positions,counter);
            sum += std::get<0>(values); 
        }
    }
    
    return h * sum; 
}

double simpsonsIntegral(double (*g)(double x), int n, double a, double b, std::vector<double> &evaluated_values, std::vector<double> &positions,std::vector<int>&counter ,double h = -1) {
    std::tuple<double,double> values_1 = evaluate(g, a, b, evaluated_values, positions, counter); 
    std::tuple<double,double> values = evaluate(g, (a + b) / 2, b, evaluated_values, positions,counter); 

    if (n == 1) {
        return (b - a) * (std::get<0>(values_1)  + std::get<1>(values_1)  + (std::get<1>(values) * 4) )/6; 
    } else {
        if(h== -1){
            h = (b-a)/n; 
        }   
        double sum = std::get<0>(values_1) + std::get<1>(values_1); 

        for (int i = 1; i < n; i++) {
            double x_i = a + i * h; // Current endpoint
            double x_im1 = a + (i - 1) * h; // Previous endpoint
            double x_mid = (x_i + x_im1) / 2; // Midpoint of the current subinterval
            values = evaluate(g, x_mid, x_i, evaluated_values, positions,counter); // Evaluate at midpoint
            sum += 2 * std::get<0>(values) + 4 * std::get<1>(values); // Apply Simpson's rule weights
        }
        return (h * sum) / 6; 
    }
}
double recursive_integral_aquidistance(double (*g)(double x), double a, double b, double epsilon, std::vector<double> &evaluated_values, std::vector<double>& positions, std::vector<int>&counter) {
    double mittle = mittlepunktIntegral(g, 1, a, b, evaluated_values, positions,counter);
    double trapez = trapezIntegral(g, 1, a, b, evaluated_values, positions,counter);
    if (std::abs(mittle - trapez) <= epsilon) {
        return simpsonsIntegral(g, 1, a, b, evaluated_values, positions,counter);
    } else {
        double left = recursive_integral_aquidistance(g, a, (a + b) / 2, epsilon / 2, evaluated_values, positions, counter);
        double right = recursive_integral_aquidistance(g, (a + b) / 2, b, epsilon / 2, evaluated_values, positions, counter);

        return left + right;
    }
}

double integral_aquidistance(double (*g)(double x), double a, double b, double epsilon) {
    std::vector<double> evaluated_values; 
    std::vector<double> positions; 
    positions.push_back(a); 
    evaluated_values.push_back(g(a)); 
    positions.push_back(b); 
    evaluated_values.push_back(g(b));  
    std::vector<int> counter; 
    counter.push_back(2); 
    double result = recursive_integral_aquidistance(*g,  a, b, epsilon, evaluated_values, positions, counter);
    std:: cout << "Integral_aquidistance no of eval  "<< counter[0] << std::endl; 
    return   result; 
}
double adaptive(double (*g)(double x), double a, double b, double epsilon) {
    std::vector<double> evaluated_values;
    std::vector<double> positions;
    positions.push_back(a);
    evaluated_values.push_back(g(a));
    positions.push_back(b);
    evaluated_values.push_back(g(b));
    std::vector<int> counter;
    counter.push_back(2); 
    double mittle = mittlepunktIntegral(g, 1, a, b, evaluated_values, positions,counter);
    double trapez = trapezIntegral(g, 1, a, b, evaluated_values, positions,counter);
    int n = 1;

    // Initial step size
    double h = (b - a);

    while (std::abs(mittle - trapez) > epsilon) {
        // Halve the step size
        h /= 2.0;
        
        // Double the number of segments
        n *= 2;

        // Recalculate mittlepunkt and trapezoidal integrals
        mittle = mittlepunktIntegral(g, n, a, b, evaluated_values, positions,counter ,h);
        trapez = trapezIntegral(g, n, a, b, evaluated_values, positions,counter,h);
    }
    double result = simpsonsIntegral(g, n, a, b, evaluated_values, positions,counter,h);
    std:: cout << "adaptive "<< counter[0] << std::endl; 
    return   result; 
}


double f(double x) {
    return x; 
}
double h(double x) {
    return x*x; 
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
    double a,b,epsilon,result1,result2; 
    getExample(method,a,b,epsilon); 
    result1 = integral_aquidistance(f,a,b,epsilon); 
    result2 = adaptive(f,a,b,epsilon); 
    std::cout << "Result of aquidistance " << result1 <<" near the exact value: " <<checkSolution(result1) << std::endl ;
    std::cout << "Result of aquidistance " << result2 <<" near the exact value: " <<checkSolution(result2) << std::endl ;
}
int main() {
    main_rountine(); 
    return 0; 
}



