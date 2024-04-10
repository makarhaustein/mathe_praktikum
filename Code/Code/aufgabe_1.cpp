#include "prime_printer.h"

int main() {
  P::generate_prime primes1;
  std::vector<int> temp = primes1.generate(300); 
  primes1.print(300, temp);
  return 0;
}
