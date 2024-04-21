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

int PartitionEasy(std::vector<unsigned int>* array, int low_idx, int high_idx) {
    unsigned int pivot = array->at(high_idx);
    int pivot_idx = high_idx;
    --high_idx;
    while(low_idx < high_idx) {
        if (array->at(low_idx) > pivot && array->at(high_idx) < pivot) {
            std::swap(array->at(low_idx), array->at(high_idx));
        }
        if (array->at(low_idx) < pivot) ++low_idx; 
        if (array->at(high_idx) >= pivot) --high_idx;
    }
    if (array->at(low_idx) > pivot) {
        std::swap(array->at(pivot_idx), array->at(low_idx));
    }
    return low_idx;
}

void QuickSortEasyRec(std::vector<unsigned int>* array, int low_idx, int high_idx) {
    if(low_idx < high_idx) {
        int pivot_location{ PartitionEasy(array, low_idx, high_idx) };
        QuickSortEasyRec(array, low_idx, pivot_location);
        QuickSortEasyRec(array, pivot_location+1, high_idx);
    }
}

std::vector<unsigned int> QuickSortEasy(std::vector<unsigned int> array) {
    QuickSortEasyRec(&array, 0, array.size()-1);
    return array;
}

int PartitionMedian(std::vector<unsigned int>* array, int low_idx, int high_idx) {
    int pivot_idx{ };
    if (high_idx-low_idx <= 1) { // max 2 elements
        pivot_idx = high_idx;
    }else {
        int mid_idx = (high_idx-low_idx)/2;
        if (array->at(low_idx) < array->at(mid_idx) < array->at(high_idx) || 
                array->at(high_idx) < array->at(mid_idx) < array->at(low_idx) ) 
            pivot_idx = mid_idx;
        else if (array->at(mid_idx) < array->at(low_idx) < array->at(high_idx) || 
                array->at(high_idx) < array->at(low_idx) < array->at(mid_idx) ) 
            pivot_idx = mid_idx;   
        else pivot_idx = high_idx;
    }
    unsigned int pivot{ array->at(pivot_idx) };

    --high_idx;
    while(low_idx < high_idx) {
        if (array->at(low_idx) > pivot && array->at(high_idx) < pivot) {
            std::swap(array->at(low_idx), array->at(high_idx));
        }
        if (array->at(low_idx) < pivot) ++low_idx; 
        if (array->at(high_idx) >= pivot) --high_idx;
    }
    if (array->at(low_idx) > pivot) {
        std::swap(array->at(pivot_idx), array->at(low_idx));
    }
    return low_idx;
}

void QuickSortMedianRec(std::vector<unsigned int>* array, int low_idx, int high_idx) {
    if(low_idx < high_idx) {
        int pivot_location{ PartitionEasy(array, low_idx, high_idx) };
        QuickSortEasyRec(array, low_idx, pivot_location);
        QuickSortEasyRec(array, pivot_location+1, high_idx);
    }
}

std::vector<unsigned int> QuickSortMedian(std::vector<unsigned int> array) {
    QuickSortEasyRec(&array, 0, array.size()-1);
    return array;
}
static int dbc = 0;
std::vector<unsigned int> MergeSort(std::vector<unsigned int> array) {
    if (array.size() > 1) {
        int mid = array.size() / 2;
        std::vector<unsigned int> arr1 = MergeSort(std::vector<unsigned int>(array.begin(), array.begin() + mid));
        std::vector<unsigned int> arr2 = MergeSort(std::vector<unsigned int>(array.begin() + mid, array.end()));
        int i = 0;
        int j = 0;
        while(i < arr1.size() && j < arr2.size()) {
            if (arr1[i] <= arr2[j]) {
                array[i+j] = arr1[i];
                ++i;
            }
            else {
                array[i+j] = arr2[j];
                ++j;
            }
        }
        if (i < arr1.size()) {
            for (int k = i+j; k < array.size(); ++k, ++i) {
                array[k] = arr1[i];
            }
        }
        else if (j < arr2.size()) {
            for (int k = i+j; k < array.size(); ++k, ++j) {
                array[k] = arr2[j];
            }
        }
    }
    return array;
}
