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
 std::tuple<double,double> evaluate(double (*g)(double x), double a, double b, std::vector<double> &evaluated_values, std::vector<double> &positions, std::vector<int>&counter);
 double mittlepunktIntegral(double (*g)(double x), int n, double a, double b, std::vector<double> &evaluated_values, std::vector<double> &positions,std::vector<int>&counter ,double h  = -1) ; 
 double trapezIntegral(double (*g)(double x), int n, double a, double b, std::vector<double> &evaluated_values, std::vector<double> &positions,std::vector<int>&counter ,double h = -1);
 double simpsonsIntegral(double (*g)(double x), int n, double a, double b, std::vector<double> &evaluated_values, std::vector<double> &positions,std::vector<int>&counter ,double h = -1) ; 
 double integral_aquidistance(double (*g)(double x), double a, double b, double epsilon); 
 double adaptive(double (*g)(double x), double a, double b, double epsilon) ; 
 void main_rountine(void); 
}

#endif
