#include "prime_printer.h"


bool GeneratePrime :: check_prime(vector<int> mult,vector<int> no_of_primes, int ord,int current ,bool jprime=true ){
  int n = 2; 
  while (n < ord && jprime) { 
    while (mult[n] < current){
      mult[n] += no_of_primes[n] + no_of_primes[n]; 
    }
    if (mult[n] == current) {
      jprime=false;
    } 
    n++;
  }
  return jprime; 
}
vector<int> GeneratePrime :: generate(int inp_no){

  //30
  const int max_number_of_primes = inp_no;
  vector<int> no_of_primes(max_number_of_primes+1);
  bool jprime;
  vector<int> mult(kOrdMax+1);

  int current=1;
  int index=1;
  no_of_primes[1] = 2;
  int ord = 2;
  int square = 9;

  while (index < max_number_of_primes) {
    //do finds the next prime number
    do {
        current += 2;
        if (current == square) {
          ord++;  
          square=no_of_primes[ord]*no_of_primes[ord];   
          mult[ord-1]=current;
        }
        jprime=check_prime(mult, no_of_primes, ord, current);
    } while (!jprime);
    index++;
    no_of_primes[index]=current;
  }
return no_of_primes;
}
void PrimePrinter :: print_rows(vector<int> no_of_primes, int rowoffset, int max_number_of_primes) {
  for (int c = 0; c <= kColoumn-1; c++){
        if (rowoffset+c*kRows <= max_number_of_primes){
          std::cout << std::setw(10) << no_of_primes[rowoffset+c*kRows];
        }
      }

}
void PrimePrinter :: print(int inp_no, vector<int> no_of_primes) {
  const int max_number_of_primes = inp_no;
  int pagenumber = 1;
  int pageoffset = 1;
  
  while (pageoffset <= max_number_of_primes) {
    std::cout << "The First ";
    std::cout << max_number_of_primes ;
    std::cout << " Prime Numbers --- Page ";
    std::cout << pagenumber;
    std::cout << std::endl;
    for (int rowoffset=pageoffset; rowoffset <= pageoffset+kRows-1; rowoffset++) {
      print_rows(no_of_primes, rowoffset, max_number_of_primes); 
      std::cout << std::endl;
    }
    std::cout << "\f" << std::endl;
    pagenumber++;
    pageoffset += kRows*kColoumn;
  }
}
