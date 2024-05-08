/********************************************************************
 *  Name       : unit.h                                             *
 *  Verwendung : Schnittstelle zu Praktikumsumgebung (MAPRA),       *
 *               Adaptive Quadratur                                 *
 *  Autor      : Karl-Heinz Brakhage, Kolja Brix, IGPM RWTH Aachen  *
 *  Datum      : April 2007                                         *
 *******************************************************************/
#ifndef _Aufgabe3_H
#define  _Aufgabe3_H
#include <cmath>
#include "unit.h"
#include <iostream>
#include <vector>
#include <tuple>

namespace intergral{
 std::tuple<double,double> evaluate(double (*g)(double x), double a, double b,std:: vector<double> &evaluated_values, std:: vector<double>& positions);
 double integral_aquidistance(double (*g)(double x), double a, double b, double eplison ); 
 double mittlepunktIntegral(double (*g)(double x),int n , double a, double b,std:: vector<double> &evaluated_values, std:: vector<double>& positions); 
 double simsonsIntegral(double (*g)(double x), int n, double a, double b,std:: vector<double> &evaluated_values, std:: vector<double>& positions); 
 double trapezIntegral(double (*g)(double x), int n, double a, double b,std:: vector<double> &evaluated_values, std:: vector<double>& positions, std:: vector<double>& intervals_position); 
 double recursive_integral_aquidistance(double (*g)(double x), double a, double b, double eplison, int counter ,std:: vector<double> &evaluated_values, std:: vector<double>& positions);
 //int find_grad(double (*g)(double x)); 
}

#endif
