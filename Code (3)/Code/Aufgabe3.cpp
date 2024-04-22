#include "Aufgabe3.h"

std::vector <unsigned int> Aufgabe3:: BubbleSort( std::vector<unsigned int> input_id){
    for (int i = input_id.size()-1; i > 0; i--){
      for (int j = 0; j < i; j++){
        if (input_id[j] > input_id[j+1] ){
            std::swap(input_id[j], input_id[j+1]); 
        }
      }
    }
  return input_id; 
}
std::vector<unsigned int> Aufgabe3:: AuswahlSort(std::vector<unsigned int> input_id){
  int index; 
  bool smaller_found = false; 
  for (int i = 0; i < input_id.size()-1; i++){
      index = i; 
      for (int j = i+1; j < input_id.size(); j++){
        if (input_id[index] > input_id[j] ){
            index = j; 
            smaller_found = true; 
        }
      }
      if ( smaller_found) {
          std::swap(input_id[i], input_id[index]);
          smaller_found = false; 
      }
      
    }  
  return input_id; 
}

std::vector<unsigned int> Merge(std::vector<unsigned int> input_id, int left, std::vector<unsigned int> input_id2, int right) {
    std::vector<unsigned int> result(left + right);
    int i = 0, j = 0, k = 0;
    while (i < left && j < right) {
        if (input_id[i] < input_id2[j]) {
            result[k] = input_id[i];
            k++; 
            i++; 
        } else {
            result[k] = input_id2[j];
            k++; 
            j++; 
        }
    }
    while (i < left) {
        result[k] = input_id[i];
        k++; 
        i++; 
    }
    while (j < right) {
        result[k] = input_id2[j];
        k++; 
        j++; 
    }
    return result;
}

std::vector<unsigned int> Aufgabe3::MergeSort(std::vector<unsigned int> input_id) {
    if (input_id.size() > 1) {
        int mid = input_id.size() / 2;
        std::vector<unsigned int> left_array(input_id.begin(), input_id.begin() + mid);
        std::vector<unsigned int> right_array(input_id.begin() + mid, input_id.end());
        left_array = MergeSort(left_array);
        right_array = MergeSort(right_array);
        input_id = Merge(left_array, mid, right_array, input_id.size() - mid);
    }
    return input_id;
}

