#include <iostream>
#include "liba.hpp"
#include <vector>

void printSum(int a, int b) {
  std::cout << "Sum of "<< a << " and " << b << " is : " \
    << sumIntegers(a,b) << "\n";
}

int main(int argc, const char* argv[]) {
  puts("hola!!!\n");
  printSum(32,6);
  printSum(33, 45);
  printSum(33, 55);
  printSum(44, 524);
  std::cout << "Sum of " << 4 << " and " << 42 << " is: " \
    << sumIntegers(33,44) << "\n";
  printSum(44, 55);

  std::vector<std::string> vs;
  vs.reserve(33);
  vs.emplace_back(std::string("this is a new string!"));
  
     

  return EXIT_SUCCESS;

}


