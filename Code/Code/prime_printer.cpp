#include "prime_printer.h"

bool GeneratePrime::check_prime(vector<int> mult,vector<int> no_of_primes, int ord,int current ,bool j_prime=true ){
  int index = 2; 
  while (index < ord && j_prime) { 
    while (mult[index] < current){
      mult[index] += no_of_primes[index] + no_of_primes[index]; 
    }
    if (mult[index] == current) {
      j_prime=false;
    } 
    index++;
  }
  return j_prime; 
}

vector<int> GeneratePrime::generate(int amount){
  const int kOrdMax = 30;
  const int max_number_of_primes = amount;
  vector<int> no_of_primes(max_number_of_primes+1);
  bool j_prime;
  vector<int> mult(kOrdMax+1);

  int current=1;
  int index=1;
  no_of_primes[index] = 2;
  int ord = 2;
  int square = 9;

  while (index < max_number_of_primes) {
    do {
        current += 2;
        if (current == square) {
          ord++;  
          square=no_of_primes[ord]*no_of_primes[ord];   
          mult[ord-1]=current;
        }
        j_prime=check_prime(mult, no_of_primes, ord, current);
    } while (!j_prime);
    index++;
    no_of_primes[index]=current;
  }
return no_of_primes;
}

void PrimePrinter::print_rows(vector<int> no_of_primes, int rowoffset, int max_number_of_primes) {
  for (int c = 0; c <= kColoumn-1; c++){
        if (rowoffset+c*kRows <= max_number_of_primes){
          std::cout << std::setw(10) << no_of_primes[rowoffset+c*kRows];
        }
      }
}

void PrimePrinter::print(int inp_no, vector<int> no_of_primes) {
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
