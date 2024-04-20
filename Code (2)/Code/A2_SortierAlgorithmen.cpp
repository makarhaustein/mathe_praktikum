#include "A2_SortierAlgorithmen.h"
#include <algorithm>
#include <iostream>
#include <initializer_list>
#include <vector>

std::vector<unsigned int> BubbleSort(std::vector<unsigned int> array) {
    for(int i = array.size()-1; i > 0; --i) {
        for(int j = 0; j < i; ++j) { 
            if(array[j] > array[j+1]) {
                std::swap(array[j], array[j+1]);
            }
        }
    }
    return array;
} 

std::vector<unsigned int> SelectionSort(std::vector<unsigned int> array) {
    for(int i = 0; i < array.size()-1; ++i) {
        unsigned int min = array[i];
        int min_idx = i;
        for(int j = i; j < array.size(); ++j) { 
            if(array[j] < min) {
                min = array[j];
                min_idx = j;
            }
        }
        if (i != min_idx) {
            std::swap(array[i], array[min_idx]);
        }
    }
    return array;
} 
std::vector<unsigned int> InsertSort(std::vector<unsigned int> array) {
    if (array.size() <= 1) return array;

    for(int i = 1; i < array.size(); i++) {
        int counter = i;
        while (counter > 0 && array[counter-1] > array[counter]) {
            std::swap(array[counter-1], array[counter]);
            counter--;
        }
    }
    return array;
}

void Heapify(std::vector<unsigned int>* array, int root_idx, int sorted_list_idx) {
    if (root_idx*2 + 1 > sorted_list_idx - 1) return; // Root is leaf 
    
    if (root_idx*2 + 1 == sorted_list_idx - 1) { // Root has one leaf
        if (array->at(root_idx) >= array->at(root_idx*2+1)) return;
       
        std::swap(array->at(root_idx), array->at(root_idx*2+1)); // TODO: TEST!
        Heapify(array, root_idx*2+1, sorted_list_idx);
    } 
    else { // Root has two leafs
        int max_idx{ array->at(root_idx*2+1) >= array->at(root_idx*2+2)
            ? root_idx*2+1 : root_idx*2+2 };

        if (array->at(max_idx) > array->at(root_idx)) { 
            std::swap(array->at(root_idx), array->at(max_idx)); // TODO: TEST!
            Heapify(array, max_idx, sorted_list_idx);
        }
    }
}

std::vector<unsigned int> HeapSort(std::vector<unsigned int> array) {
    if (array.size() <= 1) return array;

    for (int i = array.size()/2; i >= 0; --i) {
        Heapify(&array, i, array.size());
    }
    for (int j = 1; j < array.size(); ++j) {
        std::swap(array[0], array[array.size()-j]);
        Heapify(&array, 0, array.size()-j);
    }
    return array;
}
/*
std::vector<unsigned int> QuickSortEasy(std::vector<unsigned int> array) {
    
}
void Partition(std::vector *array, int low_idx, int high_idx) {

}
std::vector<unsigned int> QuickSortMedian(std::vector<unsigned int> array);

std::vector<unsigned int> MergeSort(std::vector<unsigned int> array);
*/
