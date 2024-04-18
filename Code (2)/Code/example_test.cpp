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
}

void TestAuswahl() {
  mapra::MapraTest test("AuswahlSort");
  std:: vector<unsigned int> trial = {6,5,4,2,1,0,3}; 
  std:: vector<unsigned int> expected = {0,1,2,3,4,5,6}; 
  SortAlgorithm test1; 
  trial = test1.AuswahlSort(trial);
  test.AssertEq("AuswahlSort",trial, expected );
}
void TestInsertSort() {
  mapra::MapraTest test("InsertSort");
  std:: vector<unsigned int> trial = {6,5,4,2,1,0,3}; 
  std:: vector<unsigned int> expected = {0,1,2,3,4,5,6}; 
  SortAlgorithm test1; 
  trial = test1.InsertSort(trial);
  test.AssertEq("InsertSort",trial, expected );
}
void TestHeapSort() {
  mapra::MapraTest test("HeapSort");
  std:: vector<unsigned int> trial = {6,5,4,2,1,0,3}; 
  std:: vector<unsigned int> expected = {0,1,2,3,4,5,6}; 
  SortAlgorithm test1; 
  trial = test1.HeapSort(trial);
  test.AssertEq("HeapSort",trial, expected );
}

void TestQuickSortEasy() {
  mapra::MapraTest test("QuickSortEasy");
  std:: vector<unsigned int> trial = {6,5,4,2,1,0,3}; 
  std:: vector<unsigned int> expected = {0,1,2,3,4,5,6}; 
  SortAlgorithm test1; 
  trial = test1.QuickSortEasy(trial);
  test.AssertEq("QuickSortEasy",trial, expected );
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
  std:: vector<unsigned int> trial = {6,5,4,3,2,1,0}; 
  std:: vector<unsigned int> expected = {0,1,2,3,4,5,6}; 
  SortAlgorithm test1; 
  trial = test1.QuickSortMedian(trial);
  test.AssertEq("QuickSortMedian",trial, expected );
}

int main() {
  QuickSortMedian();
  return 0;
}