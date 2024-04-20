// Copyright (c) 2022, The MaPra Authors.

#ifndef A2_SORTIERALGORITHMEN_H 
#define A2_SORTIERALGORITHMEN_H 

#include <iostream>
#include <utility>
#include <vector>

std::vector<unsigned int> BubbleSort(std::vector<unsigned int> array);
std::vector<unsigned int> SelectionSort(std::vector<unsigned int> array);
std::vector<unsigned int> InsertSort(std::vector<unsigned int> array);
void Heapify(std::vector<unsigned int>* array, int root_idx);
std::vector<unsigned int> HeapSort(std::vector<unsigned int> array);
std::vector<unsigned int> QuickSortEasy(std::vector<unsigned int> array);
std::vector<unsigned int> QuickSortMedian(std::vector<unsigned int> array);
std::vector<unsigned int> MergeSort(std::vector<unsigned int> array);

#endif  // Aufgabe2
