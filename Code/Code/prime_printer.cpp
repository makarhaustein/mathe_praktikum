#include "prime_printer.h"

bool GeneratePrime::check_prime(vector<int> mult,vector<int> no_of_primes, int ord,int current ,bool  is_prime_current = true;){
  int index = 2; 
  while (index < ord && j_prime) { 
    while (mult[index] < current){
      mult[index] += no_of_primes[index] + no_of_primes[index]; 
    }
    if (mult[index] == current) {
       is_prime_current = false;

    } 
    index++;
  }

  return is_prime_current; 

}

vector<int> GeneratePrime::generate(int amount){
  const int kOrdMax = 30;
  const int max_number_of_primes = amount;

  vector<int> primes_array(max_number_of_primes+1);
  bool is_prime_current;
  vector<int> mult(kOrdMax+1);

  int current=1;
  int found_primes_count=1;
  primes_array[1] = 2;

  int ord = 2;
  int square = 9;

  while (found_primes_count < max_number_of_primes) {
    do {
        current += 2;
        if (current == square) {
          ord++;
          square=primes_array[ord]*primes_array[ord];   
          mult[ord-1]=current;
        }

      is_prime_current=check_prime(mult, primes_array, ord, current);
    } while (!is_prime_current);
    found_primes_count++;
    primes_array[found_primes_count] = current;

  }
  return primes_array;
}

void PrimePrinter::print_rows(vector<int> primes_array, int rowoffset, int max_number_of_primes) {
  for (int c = 0; c <= kColoumn-1; c++){
        if (rowoffset+c*kRows <= max_number_of_primes){
          std::cout << std::setw(10) << primes_array[rowoffset+c*kRows];
        }
      }
}

void PrimePrinter::print(int inp_no, vector<int> primes_array) {
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
      print_rows(primes_array, rowoffset, max_number_of_primes); 
      std::cout << std::endl;
    }
    std::cout << "\f" << std::endl;
    pagenumber++;
    pageoffset += kRows*kColoumn;
  }
}
