#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>

void print() {
  int max_number_of_primes = 300;
  int rows = 50;
  int coloumn = 4;
  int ordmax = 30;
  int no_of_primes[max_number_of_primes+1];
  int pagenumber;
  int pageoffset;
  int rowoffset;
  int C;
  int J;
  int K;
  bool jprime;
  int ord;
  int SQUARE;
  int N=0;
  int MULT[ordmax+1];

  J=1;
  K=1;
  no_of_primes[1] = 2;
  ord = 2;
  SQUARE = 9;

  while (K < max_number_of_primes) {
    do {
        J += 2;
        if (J == SQUARE) {
          ord++;  
          SQUARE=no_of_primes[ord]*no_of_primes[ord];   
          MULT[ord-1]=J;
        }
        N=2;
        jprime=true;
        while (N < ord && jprime) { 
          while (MULT[N] < J){
            MULT[N] += no_of_primes[N] + no_of_primes[N]; 
          }
          if (MULT[N] == J) {
            jprime=false;
          } 
          N++;
        }
    } while (!jprime);
    K++;
    no_of_primes[K]=J;
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
      for (C=0; C <= coloumn-1; C++){
        if (rowoffset+C*rows <= max_number_of_primes){
          std::cout << std::setw(10) << no_of_primes[rowoffset+C*rows];
        }
      }
      std::cout << std::endl;
    }
    std::cout << "\f" << std::endl;
    pagenumber++;
    pageoffset += rows*coloumn;
  }
}
