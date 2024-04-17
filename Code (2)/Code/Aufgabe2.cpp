#include "Aufgabe2.h"

std::vector<unsigned int> SortAlgorithm:: BubbleSort( std::vector<unsigned int> input_id){
    for (int i = input_id.size()-1; i > 0; i--){
      for (int j = 0; j < i; j++){
        if (input_id[j] > input_id[j+1] ){
            std::swap(input_id[j], input_id[j+1]); 
        }
      }
    }
  return input_id; 
}
std::vector<unsigned int> SortAlgorithm:: AuswahlSort(std::vector<unsigned int> input_id){
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


