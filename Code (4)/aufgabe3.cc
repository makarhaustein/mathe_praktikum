#include "aufgabe3.h"


std::tuple<double,double> evaluate(double (*g)(double x), double a, double b,std:: vector<double> &evaluated_values, std:: vector<double>& positions){
    int index_a,index_b; 
    bool found_a,found_b;
    double value_a,value_b;  
    for(int i = 0; i < positions.size(); i++){
        if(positions[i] == a){
            index_a = i; 
            found_a = true; 
        }else if (positions[i] == b){
            index_b = i; 
            found_b = true; 
        }
        if(found_a && found_b){
            break; 
        }
    }
    if(found_a){
        value_a = evaluated_values[index_a]; 
    }else{
        value_a = g(a); 
        positions.push_back(a); 
        evaluated_values.push_back(value_a); 
    }
    if(found_b){
        value_b = evaluated_values[index_b]; 
    }else{
        value_b = g(b); 
        positions.push_back(b); 
        evaluated_values.push_back(value_b); 
    }
    return std::make_tuple(value_a,value_b); 
}
double mittlepunktIntegral(double (*g)(double x), int n, double a, double b,std:: vector<double> &evaluated_values, std:: vector<double>& positions){
    std::tuple<double,double> values = evaluate(g,(double(a)+double(b))/2,b,evaluated_values,positions); 
    if(n <= 1){ 
         return double((b-a)) * std:: get<0>(values); 
    }else{
        double sum = 0; 
        double h = double((b-a)) / n ; 
        for(int i = 1; i< n; i++){
            values = evaluate(g,(a+i*h +a * (i-1)*h)/2, b, evaluated_values,positions ); 
            sum += std::get<0>(values) * (a+i*h -(a+(i-1)*h)); 
        }
        return sum; 
    }
   
} 
double trapezIntegral(double (*g)(double x), int n, double a, double b,std:: vector<double> &evaluated_values, std:: vector<double>& positions){
    double h = double((b-a))/n; 
    std::tuple<double,double> values = evaluate(g,a,b,evaluated_values,positions); 
    if(n <= 1){
        return h * 0.5*(std:: get<0>(values) + std:: get<1>(values)); 
    }else{
        double sum = 0.5*(std:: get<0>(values) + std:: get<1>(values)); 
        for(int i = 1; i< n; i++){
            values = evaluate(g,(a+i*h),b,evaluated_values,positions);
            sum += std::get<0>(values); 
        }
        return h*sum; 
    }
}
double simsonsIntegral(double (*g)(double x),int n, double a, double b,std:: vector<double> &evaluated_values, std:: vector<double>& positions){
    std::tuple<double,double> values_1 = evaluate(g,a,b,evaluated_values,positions); 
    std::tuple<double,double> values = evaluate(g,(double(a)+double(b))/2,b,evaluated_values,positions); 
    if( n == 1 ){
        return double((b-a)) * (std:: get<0>(values_1)/6 + std:: get<1>(values_1)/6 +  ((std:: get<1>(values))*4)/6); 
    }else{
        double h = (b-a)/n; 
        double sum = std:: get<0>(values) + std:: get<1>(values); 
        for (int  i = 1; i < n; i++){
            values = evaluate(g,a+i*h,(2*a+i*h+(i-1)*h)/2,evaluated_values,positions); 
            sum += 2*std::get<0>(values) + 4*std::get<1>(values) ; 
        }
        return (h*sum)/6; 
    }
    
}

double integral_aquidistance(double (*g)(double x), double a, double b, double eplison ){
 std:: vector<double> evaluated_values; 
 std:: vector<double> positions; 
 std::vector<double> interval_position; 
 positions.push_back(a); 
 evaluated_values.push_back(g(a)); 
 positions.push_back(b); 
 evaluated_values.push_back(g(b));  
  
 int n = 1; 
 double mittle = mittlepunktIntegral(*g,n, a,b, evaluated_values, positions); 
 double trapez = trapezIntegral(*g,n,a,b,evaluated_values, positions); 

 double differenz = std:: abs(mittle-trapez);
 while( differenz > eplison){
    n++; 
    mittle = mittlepunktIntegral(*g,n, a,b, evaluated_values, positions); 
    trapez = trapezIntegral(*g,n,a,b,evaluated_values, positions); 
    differenz = std:: abs(mittle-trapez);
 }
  return simsonsIntegral(*g,n,a,b,evaluated_values, positions); 
}