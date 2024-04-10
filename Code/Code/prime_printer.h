#ifndef PRIME_PRINTER_H
#define PRIME_PRINTER_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
# include <vector>
using std :: vector ;
namespace P {
  class generate_prime {
    public: 
          bool check_prime(vector<int> mult,vector<int> no_of_primes, int ord,int current ,bool jprime=true ); 
          vector<int> generate(int inp_no); 
          void print_rows(vector<int> no_of_primes, int rowoffset, int max_number_of_primes); 
          void print(int inp_no, vector<int> no_of_primes); 
  };

}


#endif