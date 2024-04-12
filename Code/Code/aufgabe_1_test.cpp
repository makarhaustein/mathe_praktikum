#include "mapra_test.h"
#include "prime_printer.h"
#include <iostream>
#include <cmath>

void TestPrintPrimes() {
  mapra::MapraTest test("PrimePrintTester");

  std::ofstream out("YourPrint.txt");
  std::streambuf *coutbuf = std::cout.rdbuf();
  std::cout.rdbuf(out.rdbuf()); // cout auf Datei "YourPrint.txt" umleiten
  GeneratePrime primes;
  PrimePrinter printer;
  vector<int> temp = primes.generate(300); 
  printer.print(300, temp); 
  out.close();

  std::ifstream examplFile("PerfectPrint.txt");
  std::ifstream computedFile("YourPrint.txt");

  std::string exampleLine;
  std::string computedLine;
  int i = 1;
  // Zeile fuer Zeile vergleichen
  while (std::getline(examplFile, exampleLine)) {
    std::stringstream ss;
    ss << "Line " << std::to_string(i) << "\t:";
    std::getline(computedFile, computedLine);
    test.AssertEq(ss.str(), exampleLine, computedLine);
    i++;
  }
  std::getline(computedFile, computedLine);
  test.Assert("No more lines :", computedFile.eof());
  remove("YourPrint.txt");
  std::cout.rdbuf(coutbuf); // cout wieder auf Bildschirm leiten
}

void TestChecker(){
  GeneratePrime primes; 
  vector<int> multiples_1 = {0,0,0};
  vector<int> prime ={0,0,2,0};  
  int current = 4; 
  int order = 3;
  bool prime_check = primes.check_prime(multiples_1,prime,order,current, true); 
  if(prime_check == false){
    std:: cout << "1 Test passed \n" ;
  } else{
    std:: cout << "Test failed \n";
  }
  multiples_1[2] = 9; 
  prime[0] = 2; 
  prime[1] = 3; 
  prime[3] = 5; 
  order = 3;
  current = 7; 
  prime_check = primes.check_prime(multiples_1,prime,order,current, true); 
  if(prime_check == true){
    std:: cout << "2 Test passed \n";
  } else{
    std:: cout << "2 Test failed \n";
  }
}

void Testgenerate(){
  GeneratePrime prime; 
  int to_be_tested = 10;
  vector<int> computed_value(to_be_tested); 
  computed_value = prime.generate(to_be_tested); //hopefull generate 2,3,5,7,11,13,17,19,23,29

  int n  = 900; 
  vector<bool> value (n); //all values set to false
  vector<int>  prime_nr(to_be_tested); 
  int index = 1; 
  for (int i = 2; i < sqrt(n); i++){
      if (!value[i] ){
        prime_nr[index] = i; 
        index++; 
        if (index == to_be_tested){
          break;
        }
        for (int j = i*i; j < n; j += i){
          value[j] = true; 
        }  
      }
  }
  bool correct = true; 
  for ( int i = 0; i < 10; i++){
    if (prime_nr[i] != computed_value[i]){
      correct = false; 
      break; 
    }
  }
  if(correct == true){
    std:: cout << "3 Test passed \n";
  } else{
    std:: cout << "3 Test failed \n";
  } 
}

void TestRowPrinter(){
  mapra::MapraTest test("RowTester");
  std::ofstream out("YourRow.txt");
  std::cout.rdbuf(out.rdbuf()); // cout auf Datei "YourPrint.txt" umleiten
  GeneratePrime primes;
  PrimePrinter printer;
  vector<int> temp = primes.generate(300); 
  printer.print_rows(temp,1,300); 
  out.close();

  std::ifstream examplFile("YourRow.txt");
  std::ifstream computedFile("PerfectRow.txt");

  std::string exampleLine;
  std::string computedLine;
 
  std::getline(examplFile, exampleLine);
  std::stringstream ss;
  ss << "Line " << std::to_string(1) << "\t:";
  std::getline(computedFile, computedLine);
  test.AssertEq(ss.str(), exampleLine, computedLine);
}

int main() {
  TestPrintPrimes();
  TestChecker(); 
  Testgenerate();
  TestRowPrinter();
  return 0;
}
