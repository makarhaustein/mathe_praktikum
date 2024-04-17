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
std::vector<unsigned int> SortAlgorithm:: InsertSort( std::vector<unsigned int> input_id){
  int index; 
  for (int i = 1; i < input_id.size(); i++){
    for (int j = i; j > 0; j--){
      if (input_id[j] < input_id[j-1]){
        std::swap(input_id[j], input_id[j-1]);
      }
    } 
  }
  return input_id; 
 }
std:: vector<unsigned int> Heapfiy(std:: vector<unsigned int> input_id, int index, int size){
    int left = 2 * index+1 ;
    int right = 2 * index + 2;
    int largest = index;

    if (left < size && input_id[left] > input_id[largest]) {
        largest = left;
    }
    if (right < size && input_id[right] > input_id[largest]) {
        largest = right;
    }
    if (largest != index) {
        std::swap(input_id[index], input_id[largest]);
        input_id = Heapfiy(input_id, largest, size);
    }
  
  return input_id; 
}
std:: vector<unsigned int> createHeap(std:: vector<unsigned int> input_id){
  for (int i = (input_id.size()/2)-1; i >= 0 ; i--){
      input_id = Heapfiy(input_id, i, input_id.size()); 
  }
  return input_id; 
}
std::vector<unsigned int> SortAlgorithm:: HeapSort (std::vector<unsigned int>input_id){
    input_id = createHeap(input_id); 
    for (int i = 0; i < input_id.size()-1; i++){
      std::swap(input_id[0], input_id[input_id.size()-1-i]);
      input_id = Heapfiy(input_id, 0, input_id.size()-i-1); 
      for (int i = 0; i < 7; i++)
      {
        std :: cout << input_id[i]; 
      }
      std :: cout << "-----\n";
    }
    
    return input_id; 
}

