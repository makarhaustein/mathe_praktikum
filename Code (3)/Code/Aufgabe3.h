// Copyright (c) 2022, The MaPra Authors.

#ifndef AUFGABE3_H_
#define AUFGABE3_H_

#include <iostream>
#include <string>
#include <vector>

#include "student.h"

namespace Aufgabe3 {

// Funktionen zur Ueberpruefung der Ergebnisse
// geben zurueck, ob ein Fehler entdeckt wurde
std::vector<unsigned int>  BubbleSort( std::vector<unsigned int> input_id);
std::vector<unsigned int>  AuswahlSort(std::vector<unsigned int> input_id);
std::vector<unsigned int>  MergeSort(std::vector<unsigned int> input_id); 

}  // namespace mapra

#endif  // UNIT_H_
