// Copyright (c) 2022, The MaPra Authors.

#include "A2_SortierAlgorithmen.h"
#include "mapra_test.h"
#include "unit.h"
#include <string>

void TestBubblesort() {
  mapra::MapraTest test("BubbleSort");
  std::vector<unsigned int> trial = {6, 5, 4, 2, 1, 0, 3};
  std::vector<unsigned int> expected = {0, 1, 2, 3, 4, 5, 6};

  trial = BubbleSort(trial);
  test.AssertEq("Bubblesort", expected, trial);
  for (int i = 0; i < 4; i++) {
    trial = mapra::GetExample(i, 7);

    trial = BubbleSort(trial);
    mapra::CheckSolution(trial);
  }
}

void TestSelectionSort() {
  mapra::MapraTest test("AuswahlSort");
  std::vector<unsigned int> trial = {6, 5, 4, 2, 1, 0, 3};
  std::vector<unsigned int> expected = {0, 1, 2, 3, 4, 5, 6};
  trial = SelectionSort(trial);
  test.AssertEq("AuswahlSort", expected, trial);
  for (int i = 0; i < 4; i++) {
    trial = mapra::GetExample(i, 7);
    trial = SelectionSort(trial);
    mapra::CheckSolution(trial);
  }
}
void TestInsertSort() {
  mapra::MapraTest test("InsertSort");
  std::vector<unsigned int> trial = {6, 5, 4, 2, 1, 0, 3};
  std::vector<unsigned int> expected = {0, 1, 2, 3, 4, 5, 6};
  trial = InsertSort(trial);
  test.AssertEq("InsertSort", expected, trial);
  for (int i = 0; i < 4; i++) {
    trial = mapra::GetExample(i, 7);
    trial = InsertSort(trial);
    mapra::CheckSolution(trial);
  }
}
void TestHeapSort() {
  mapra::MapraTest test("HeapSort");
  std::vector<unsigned int> trial = {4, 6, 3, 5, 1, 0, 2};
  std::vector<unsigned int> expected = {0, 1, 2, 3, 4, 5, 6};
  trial = HeapSort(trial);
  test.AssertEq("HeapSort", expected, trial);
  for (int i = 0; i < 4; i++) {
    trial = mapra::GetExample(i, 7);
    trial = HeapSort(trial);
    mapra::CheckSolution(trial);
  }
}

void TestQuickSortEasy() {
  mapra::MapraTest test("QuickSortEasy");
  std::vector<unsigned int> trial = {2, 4, 6, 3, 5, 1, 0}; 
  std::vector<unsigned int> expected = {0, 1, 2, 3, 4, 5, 6};
  trial = QuickSortEasy(trial);
  test.AssertEq("QuickSortEasy", expected, trial);
  for (int i = 0; i < 4; i++) {
    trial = mapra::GetExample(i, 7);
    trial = QuickSortEasy(trial);
    mapra::CheckSolution(trial);
  }
}

void TestMergeSort() {
  mapra::MapraTest test("MergeSort");
  std::vector<unsigned int> trial = {6, 5, 4, 2, 1, 0, 3};
  std::vector<unsigned int> expected = {0, 1, 2, 3, 4, 5, 6};
  trial = MergeSort(trial);
  test.AssertEq("MergeSort", expected, trial);
  for (int i = 0; i < 4; i++) {
    trial = mapra::GetExample(i, 7);
    trial = MergeSort(trial);
    mapra::CheckSolution(trial);
  }
}

void TestQuickSortMedian() {
  mapra::MapraTest test("QuickSortMedian");
  std::vector<unsigned int> trial = {6, 5, 4, 2, 1, 0, 3};
  std::vector<unsigned int> expected = {0, 1, 2, 3, 4, 5, 6};
  trial = QuickSortMedian(trial);
  test.AssertEq("QuickSortMedian", expected, trial);
  for (int i = 0; i < 4; i++) {
    trial = mapra::GetExample(i, 7);
    trial = QuickSortMedian(trial);
    mapra::CheckSolution(trial);
  }
}

int main() { 
    TestBubblesort();
    TestSelectionSort();
    TestInsertSort();
    TestHeapSort();
    TestQuickSortEasy();
    TestQuickSortMedian();
    TestMergeSort();
    return 0;
}
