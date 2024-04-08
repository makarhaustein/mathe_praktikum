#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
# include < vector >
using std :: vector ;

void print() {
  const int max_number_of_primes = 300;
  const int rows = 50;
  const int coloumn = 4;
  const int ordmax = 30;
  vector<int> no_of_primes(max_number_of_primes+1);
  int pagenumber;
  int pageoffset;
  int rowoffset;
  int c;
  int j;
  int k;
  bool jprime;
  int ord;
  int SQUARE;
  int N;
  vector<int> MULT(ordmax+1);

  j=1;
  k=1;
  no_of_primes[1] = 2;
  ord = 2;
  SQUARE = 9;

  while (k < max_number_of_primes) {
    do {
        j += 2;
        if (j == SQUARE) {
          ord++;  
          SQUARE=no_of_primes[ord]*no_of_primes[ord];   
          MULT[ord-1]=j;
        }
        N=2;
        jprime=true;
        while (N < ord && jprime) { 
          while (MULT[N] < j){
            MULT[N] += no_of_primes[N] + no_of_primes[N]; 
          }
          if (MULT[N] == j) {
            jprime=false;
          } 
          N++;
        }
    } while (!jprime);
    k++;
    no_of_primes[k]=j;
  }

  pagenumber = 1;
  pageoffset = 1;
  
  while (pageoffset <= max_number_of_primes) {
    std::cout << "The First ";
    std::cout << max_number_of_primes ;
    std::cout << " Prime Numbers --- Page ";
    std::cout << pagenumber;
    std::cout << std::endl;
    for (rowoffset=pageoffset; rowoffset <= pageoffset+rows-1; rowoffset++) {
      for (c=0; c <= coloumn-1; c++){
        if (rowoffset+c*rows <= max_number_of_primes){
          std::cout << std::setw(10) << no_of_primes[rowoffset+c*rows];
        }
      }
      std::cout << std::endl;
    }
    std::cout << "\f" << std::endl;
    pagenumber++;
    pageoffset += rows*coloumn;
  }
}
