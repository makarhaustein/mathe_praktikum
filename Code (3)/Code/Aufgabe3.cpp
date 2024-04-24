#include "Aufgabe3.h"
template<typename T> 
std::vector <T> Aufgabe3:: BubbleSort( std::vector<T> input_id){
    for (int i = input_id.size()-1; i > 0; i--){
      for (int j = 0; j < i; j++){
        if (input_id[j] > input_id[j+1] ){
            std::swap(input_id[j], input_id[j+1]); 
        }
      }
    }
  return input_id; 
}
template<typename T> 
std::vector<T> Aufgabe3:: AuswahlSort(std::vector<T> input_id){
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
template<typename T> 
std::vector<T> Merge(std::vector<T> input_id, int left, std::vector<T> input_id2, int right) {
    std::vector<T> result(left + right);
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
template<typename T> 
std::vector<T>  Aufgabe3::MergeSort(std::vector<T> input_id) {
    if (input_id.size() > 1) {
        int mid = input_id.size() / 2;
        std::vector<T> left_array(input_id.begin(), input_id.begin() + mid);
        std::vector<T> right_array(input_id.begin() + mid, input_id.end());
        left_array = MergeSort(left_array);
        right_array = MergeSort(right_array);
        input_id = Merge(left_array, mid, right_array, input_id.size() - mid);
    }
    return input_id;
}
template < typename T >
void  Aufgabe3::Read ( std :: ifstream & ifs , std :: vector <T >& array ){
    T value; 
    while(ifs >> value){
      array.push_back(value);
    }

}
template < typename T >
void Aufgabe3::Print ( std :: ostream & os , const std :: vector <T >& array ){
  for (const T& i: array){
    os << i << " "; 
  }
  
}
int main(){
    std::ifstream ifs; 
    ifs.open("C:/Users/aadia/OneDrive - Students RWTH Aachen University/Documents/uni/4/MAthe Prak/github/mathe_praktikum/Code (3)/Code/doubles.txt");
    if (!ifs.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    std::vector<double> data; // Change int to the appropriate type if needed
    Aufgabe3::Read(ifs, data);

    // Print out the data read from the file
   std:: ofstream fout ( " results.txt " );
    Aufgabe3:: Print(fout, data); 
    fout.close(); 
    ifs.close(); // Don't forget to close the file stream
    return 0;
}