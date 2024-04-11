#include "mapra_test.h"
#include "prime_printer.h"

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

  std::ifstream goldFile("PerfectPrint.txt");
  std::ifstream leadFile("YourPrint.txt");

  std::string goldLine;
  std::string leadLine;
  int i = 1;
  // Zeile fuer Zeile vergleichen
  while (std::getline(goldFile, goldLine)) {
    std::stringstream ss;
    ss << "Line " << std::to_string(i) << "\t:";
    std::getline(leadFile, leadLine);
    test.AssertEq(ss.str(), goldLine, leadLine);
    i++;
  }
  std::getline(leadFile, leadLine);
  test.Assert("No more lines :", leadFile.eof());
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
  vector<int> (10) = prime.generate(10); 
  //another programm that creates prime and compare the results 
  
}
//final test for printing rowwise. 
int main() {
  TestPrintPrimes();
  TestChecker(); 
  return 0;
}
