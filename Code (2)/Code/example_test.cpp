// Copyright (c) 2022, The MaPra Authors.

#include "mapra_test.h"
#include "Aufgabe2.h"
#include <algorithm>
#include <iostream>
#include <string>
#include "unit.h"


void TestBubblesort() {
  mapra::MapraTest test("BubbleSort");
  std:: vector<unsigned int> trial = {6,5,4,2,1,0,3}; 
  std:: vector<unsigned int> expected = {0,1,2,3,4,5,6}; 
  SortAlgorithm test1; 
  trial = test1.BubbleSort(trial);
  test.AssertEq("Bubblesort",trial, expected );
  for (int i = 0; i < 4; i++){
   trial = mapra:: GetExample(i,7); 
   SortAlgorithm test1; 
   trial =  test1.BubbleSort(trial);
   mapra::CheckSolution(trial); 
  }
  
}

void TestAuswahl() {
  mapra::MapraTest test("AuswahlSort");
  std:: vector<unsigned int> trial = {6,5,4,2,1,0,3}; 
  std:: vector<unsigned int> expected = {0,1,2,3,4,5,6}; 
  SortAlgorithm test1; 
  trial = test1.AuswahlSort(trial);
  test.AssertEq("AuswahlSort",trial, expected );
  for (int i = 0; i < 4; i++){
   trial = mapra:: GetExample(i,7); 
   SortAlgorithm test1; 
   trial =  test1.AuswahlSort(trial);
   mapra::CheckSolution(trial); 
  }
}
void TestInsertSort() {
  mapra::MapraTest test("InsertSort");
  std:: vector<unsigned int> trial = {6,5,4,2,1,0,3}; 
  std:: vector<unsigned int> expected = {0,1,2,3,4,5,6}; 
  SortAlgorithm test1; 
  trial = test1.InsertSort(trial);
  test.AssertEq("InsertSort",trial, expected );
  for (int i = 0; i < 4; i++){
   trial = mapra:: GetExample(i,7); 
   SortAlgorithm test1; 
   trial =  test1.InsertSort(trial);
   mapra::CheckSolution(trial); 
  }
}
void TestHeapSort() {
  mapra::MapraTest test("HeapSort");
  std:: vector<unsigned int> trial = {6,5,4,2,1,0,3}; 
  std:: vector<unsigned int> expected = {0,1,2,3,4,5,6}; 
  SortAlgorithm test1; 
  trial = test1.HeapSort(trial);
  test.AssertEq("HeapSort",trial, expected );
  for (int i = 0; i < 4; i++){
   trial = mapra:: GetExample(i,7); 
   SortAlgorithm test1; 
   trial =  test1.HeapSort(trial);
   mapra::CheckSolution(trial); 
  }
}

void TestQuickSortEasy() {
  mapra::MapraTest test("QuickSortEasy");
  std:: vector<unsigned int> trial = {6,5,4,2,1,0,3}; 
  std:: vector<unsigned int> expected = {0,1,2,3,4,5,6}; 
  SortAlgorithm test1; 
  trial = test1.QuickSortEasy(trial);
  test.AssertEq("QuickSortEasy",trial, expected );
  for (int i = 0; i < 4; i++){
   trial = mapra:: GetExample(i,7); 
   SortAlgorithm test1; 
   trial =  test1.QuickSortEasy(trial);
   mapra::CheckSolution(trial); 
  }
}
void TestMergeSort() {
  mapra::MapraTest test("MergeSort");
  std:: vector<unsigned int> trial = {6,5,4,2,1,0,3}; 
  std:: vector<unsigned int> expected = {0,1,2,3,4,5,6}; 
  SortAlgorithm test1; 
  trial = test1.MergeSort(trial);
  test.AssertEq("MergeSort",trial, expected );
}

void QuickSortMedian() {
  mapra::MapraTest test("QuickSortMedian");
  std:: vector<unsigned int> trial = {6,5,4,2,1,0,3}; 
  std:: vector<unsigned int> expected = {0,1,2,3,4,5,6}; 
  SortAlgorithm test1; 
  trial = test1.QuickSortMedian(trial);
  test.AssertEq("QuickSortMedian",trial, expected );
  
}

int main() {
  TestQuickSortEasy(); 
  QuickSortMedian(); 
  std:: vector<unsigned int> trial; 
  for (int i = 0; i < 4; i++){
   trial = mapra:: GetExample(i,7); 
   SortAlgorithm test1; 
   trial =  test1.QuickSortEasy(trial);
   mapra::CheckSolution(trial); 
  }
  for (int i = 0; i < 4; i++){
   trial = mapra:: GetExample(i,7); 
   SortAlgorithm test1; 
   trial =  test1.QuickSortMedian(trial);
   mapra::CheckSolution(trial); 
  }
  TestAuswahl(); 
  TestBubblesort(); 
  TestHeapSort(); 
  TestInsertSort(); 
  TestMergeSort(); 

  
  return 0;
}