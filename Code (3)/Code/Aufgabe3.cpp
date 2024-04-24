#include "Aufgabe3.h"

template<class T> 
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
template<class T> 
std::vector<T> Aufgabe3:: AuswahlSort(std::vector<T> input_id){
  int index; 
  bool smaller_found = false; 
  for ( unsigned int i = 0; i < input_id.size()-1; i++){
      index = i; 
      for (unsigned int j = i+1; j < input_id.size(); j++){
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
template<class T> 
std::vector<T> Merge(std::vector<T> input_id, unsigned int left, std::vector<T> input_id2, unsigned int right) {
    std::vector<T> result(left + right);
    unsigned int i = 0, j = 0, k = 0;
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
        unsigned int mid = input_id.size() / 2;
        std::vector<T> left_array(input_id.begin(), input_id.begin() + mid);
        std::vector<T> right_array(input_id.begin() + mid, input_id.end());
        left_array = MergeSort(left_array);
        right_array = MergeSort(right_array);
        input_id = Merge(left_array, mid, right_array, input_id.size() - mid);
    }
    return input_id;
}
template < class T >
void  Aufgabe3::Read ( std :: ifstream & ifs , std :: vector <T >& array ){
    T value; 
    while(ifs >> value){
      array.push_back(value);
    }

}
template < class T >
void Aufgabe3::Print ( std :: ostream & os , const std :: vector <T >& array ){
  for (const T& i: array){
    os << i << " "; 
  }
  
}
void hauptfkt(){
    std::ifstream ifs, jfs, kfs; 
    ifs.open("C:/Users/aadia/OneDrive - Students RWTH Aachen University/Documents/uni/4/MAthe Prak/github/mathe_praktikum/Code (3)/Code/doubles.txt");
    jfs.open("C:/Users/aadia/OneDrive - Students RWTH Aachen University/Documents/uni/4/MAthe Prak/github/mathe_praktikum/Code (3)/Code/strings.txt");
    kfs.open("C:/Users/aadia/OneDrive - Students RWTH Aachen University/Documents/uni/4/MAthe Prak/github/mathe_praktikum/Code (3)/Code/studenten.txt");

    if (!ifs.is_open()) {
        std::cerr << "Failed to open file double." << std::endl;
        return;
    }
    if (!jfs.is_open()) {
        std::cerr << "Failed to open file strings." << std::endl;
        return;
    }
    if (!kfs.is_open()) {
        std::cerr << "Failed to open file student." << std::endl;
        return;
    }
    std::vector<double> doub; // Change int to the appropriate type if needed
    std::vector<std:: string> str;
    std::vector<mapra:: Student> student; 
    Aufgabe3::Read(ifs, doub);
    Aufgabe3::Read(jfs, str); 
    Aufgabe3::Read(kfs, student); 
    // Print out the data read from the file
    std:: string method; 
    bool A = false; 
    bool B = false; 
    bool M = false; 
    while( !A && !B  && !M ){
    std:: cout << "Suchen Sie eine Neue Sortieralgorithmus aus (B, A, M) \n";
    std:: cin >> method;  
    if (method.compare("A") == 0){
      A = true; 
    }else if (method.compare("B") == 0){
      B = true; 
    }else if (method.compare("M") == 0){
      M = true; 
    }
    }
    if (A){
      doub = Aufgabe3::AuswahlSort(doub); 
      str  = Aufgabe3::AuswahlSort(str); 
      student = Aufgabe3:: AuswahlSort(student); 
    }else if (B)
    {
      doub = Aufgabe3::BubbleSort(doub); 
      str  = Aufgabe3::BubbleSort(str); 
      student = Aufgabe3:: BubbleSort(student); 
    }else{
      doub = Aufgabe3::MergeSort(doub); 
      str  = Aufgabe3::MergeSort(str); 
      student = Aufgabe3:: MergeSort(student); 
    }
    Aufgabe3::Print(std:: cout, doub); 
    std:: cout << "\n"; 
    mapra::CheckSolution(doub);
    Aufgabe3::Print(std:: cout, str);
     std:: cout << "\n"; 
    mapra::CheckSolution(str);  
    Aufgabe3::Print(std:: cout,  student); 
     std:: cout << "\n"; 
    //mapra::CheckSolution(student); 
    ifs.close(); // Don't forget to close the file stream
    jfs.close(); 
    kfs.close(); 
}
int main(){
    hauptfkt(); 
    return 0;
}