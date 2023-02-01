#include <iostream>

#include "adder/adder.hpp"

int main(int argc, char* argv[]) {
  std::cout << "hello caracola!\n";
  std::cout << "the result is " << adder::add2(3) << "\n";
  std::cout << "the result is " << adder::add3(3) << "\n";
  std::cout << "the result is " << adder::add4(3) << "\n";
}

