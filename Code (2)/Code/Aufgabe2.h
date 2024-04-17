// Copyright (c) 2022, The MaPra Authors.

#ifndef Aufgabe2
#define Aufgabe2

#include <iostream>
#include <utility>
#include <vector>

class SortAlgorithm
{
public:
     std::vector<unsigned int> BubbleSort(unsigned int input_id);
     std::vector<unsigned int> AuswahlSort(unsigned int input_id);
     std::vector<unsigned int> InsertSort(unsigned int input_id);
     std::vector<unsigned int> HeapSort(unsigned int input_id);
     std::vector<unsigned int> QuickSortEasy(unsigned int input_id);
     std::vector<unsigned int> QuickSortMedian(unsigned int input_id);
     std::vector<unsigned int> MergeSort(unsigned int input_id);
};




#endif  // Aufgabe2
