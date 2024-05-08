#include "aufgabe3.h"
#include <iostream>
#include <cmath>

std::tuple<double,double> evaluate(double (*g)(double x), double a, double b, std::vector<double> &evaluated_values, std::vector<double> &positions) {
    int index_a = -1, index_b = -1; 
    double value_a, value_b;

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
    if (index_a == -1) {
        value_a = evaluated_values[index_a]; 
    } else {
        value_a = g(a); 
        positions.push_back(a); 
        evaluated_values.push_back(value_a); 
    }
    if (index_b == -1) {
        value_b = evaluated_values[index_b]; 
    } else {
        value_b = g(b); 
        positions.push_back(b); 
        evaluated_values.push_back(value_b); 
    }
    return std::make_tuple(value_a, value_b); 
}

double mittlepunktIntegral(double (*g)(double x), int n, double a, double b, std::vector<double> &evaluated_values, std::vector<double> &positions) {
    std::tuple<double,double> values = evaluate(g, (a + b) / 2, b, evaluated_values, positions); 
    double sum = 0; 
    if (n <= 1) { 
         return (b - a) * std::get<0>(values); 
    } else {
        double h = (b - a) / n; 
        for (int i = 1; i < n; i++) {
            values = evaluate(g, (a + i * h + a * (i - 1) * h) / 2, b, evaluated_values, positions); 
            sum += std::get<0>(values) * (a + i * h - (a + (i - 1) * h)); 
        }
        return sum; 
    }
} 

double trapezIntegral(double (*g)(double x), int n, double a, double b, std::vector<double> &evaluated_values, std::vector<double> &positions) {
    double h = (b - a) / n; 
    std::tuple<double,double> values = evaluate(g, a, b, evaluated_values, positions); 
    double sum = 0.5 * (std::get<0>(values) + std::get<1>(values)); 

    if (n > 1) {
        for (int i = 1; i < n; i++) {
            values = evaluate(g, a + i * h, b, evaluated_values, positions);
            sum += std::get<0>(values); 
        }
    }
    
    return h * sum; 
}

double simpsonsIntegral(double (*g)(double x), int n, double a, double b, std::vector<double> &evaluated_values, std::vector<double> &positions) {
    std::tuple<double,double> values_1 = evaluate(g, a, b, evaluated_values, positions); 
    std::tuple<double,double> values = evaluate(g, (a + b) / 2, b, evaluated_values, positions); 

    if (n == 1) {
        return (b - a) * (std::get<0>(values_1) / 6 + std::get<1>(values_1) / 6 + (std::get<1>(values) * 4) / 6); 
    } else {
        double h = (b - a) / n; 
        double sum = std::get<0>(values) + std::get<1>(values); 

        for (int i = 1; i < n; i++) {
            values = evaluate(g, a + i * h, (2 * a + i * h + (i - 1) * h) / 2, evaluated_values, positions); 
            sum += 2 * std::get<0>(values) + 4 * std::get<1>(values); 
        }

        return (h * sum) / 6; 
    }
}

double integral_aquidistance(double (*g)(double x), double a, double b, double epsilon) {
    std::vector<double> evaluated_values; 
    std::vector<double> positions; 

    positions.push_back(a); 
    evaluated_values.push_back(g(a)); 
    positions.push_back(b); 
    evaluated_values.push_back(g(b));  
  
    int n = 1; 
    double mittle = mittlepunktIntegral(*g, n, a, b, evaluated_values, positions); 
    double trapez = trapezIntegral(*g, n, a, b, evaluated_values, positions); 
    double difference = std::abs(mittle - trapez);

    while (difference > epsilon) {
        n++; 
        mittle = mittlepunktIntegral(*g, n, a, b, evaluated_values, positions); 
        trapez = trapezIntegral(*g, n, a, b, evaluated_values, positions); 
        difference = std::abs(mittle - trapez);
    }
  
    return simpsonsIntegral(*g, n, a, b, evaluated_values, positions); 
}

double f(double x) {
    return x * x; 
}

int main() {
    std::cout << integral_aquidistance(f, 0, 10, 0.5); 
    return 0; 
}
