/********************************************************************
 *  Name       : unit.h                                             *
 *  Verwendung : Schnittstelle zu Praktikumsumgebung (MAPRA),       *
 *               Adaptive Quadratur                                 *
 *  Autor      : Karl-Heinz Brakhage, Kolja Brix, IGPM RWTH Aachen  *
 *  Datum      : April 2007                                         *
 *******************************************************************/
#ifndef _QUADRATUR_H
#define  _QUADRATUR_H
#include <cmath>
#include "unit.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <map>

namespace intergralnew{
 double aquidistance(double (*g)(double x), double a, double b, double epsilon) ; 
 double determine_smallest_interval(double (*g)(double x), double a, double b, double epsilon,std:: map <double,double> &function_values) ; 
 double adaptive(double (*g)(double x), double a, double b, double epsilon) ; 
 double evaluate(double (*g)(double x), double a,std:: map <double,double> &function_values ) ; 
 double midpointIntegral(double (*g)(double x), double a, double b,std:: map <double,double> &function_values ) ; 
 double trapezoidalIntegral(double (*g)(double x), double a, double b,std:: map <double,double> &function_values );
 double recursive(double (*g)(double x), double a, double b, double epsilon,std:: map <double,double> &function_values) ; 
 double simpsonsIntegral(double (*g)(double x), double a, double b,std:: map <double,double> &function_values ) ; 
 void main_rountine2(void);
 void main_rountine(void);
}

#endif
