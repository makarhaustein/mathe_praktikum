// Copyright (c) 2022, The MaPra Authors.

#ifndef Aufgabe2_H
#define Aufgabe2_H

#include <iostream>
#include <utility>
#include <vector>

class SortAlgorithm{
public:
     std::vector<unsigned int> BubbleSort(std::vector<unsigned int>input_id);
     std::vector<unsigned int> AuswahlSort(std::vector<unsigned int> input_id);
     std::vector<unsigned int> InsertSort( std::vector<unsigned int> input_id);
     std::vector<unsigned int> HeapSort (std::vector<unsigned int>input_id);
     std::vector<unsigned int> QuickSortEasy( std::vector<unsigned int> input_id);
     std::vector<unsigned int> QuickSortMedian( std::vector<unsigned int>input_id);
     std::vector<unsigned int> MergeSort( std::vector<unsigned int> input_id);
};
#endif 
