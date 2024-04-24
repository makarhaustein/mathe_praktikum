// Copyright (c) 2022, The MaPra Authors.

#ifndef AUFGABE3_H_
#define AUFGABE3_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "student.h"

namespace Aufgabe3 {

// Funktionen zur Ueberpruefung der Ergebnisse
// geben zurueck, ob ein Fehler entdeckt wurde
template<typename T> 
std::vector<T>  BubbleSort( std::vector<T> input_id);
template<typename T> 
std::vector<T>  AuswahlSort(std::vector<T> input_id);
template<typename T> 
std::vector<T>  MergeSort(std::vector<T> input_id); 
template < typename T >
void  Read ( std :: ifstream & ifs , std :: vector <T >& array );
template < typename T >
void Print ( std :: ostream & os , const std :: vector <T >& array );
}  // namespace mapra

#endif  // UNIT_H_
