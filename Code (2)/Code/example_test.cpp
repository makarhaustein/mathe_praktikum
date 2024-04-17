// Copyright (c) 2022, The MaPra Authors.

#include "mapra_test.h"
#include "Aufgabe2.h"
#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std:: vector<unsigned int> trial = {6,5,4,3,2,1,0}; 
  SortAlgorithm test1; 
  trial = test1.InsertSort(trial);
  for ( int i = 0; i < 7; i++){
    std:: cout << trial[i]; 
  }
  mapra::MapraTest test("Beispiel");
  test.Assert("cin works", std::cin.good());
  test.AssertEq("max(-4,3) is 3", 3, std::max(-4, 3));
  test.AssertEq("max(3,-4) is 3", 2, std::max(3, -4));  // extra falsch
  return 0;
}

