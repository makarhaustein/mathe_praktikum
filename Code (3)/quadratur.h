#ifndef _QUADRATUR_H
#define _QUADRATUR_H

double Mittelpunktsregel(double a, double b); 
double Adaptives_Zerlegen(double a, double b, double f_a, double f_b,
                          double f_mpr, double epsilon, long local_depth,
                          long *max_depth);
void Quadratur();
 
#endif
