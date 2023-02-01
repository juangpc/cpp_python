#include <iostream>

#include "adder/adder.hpp"
#include "calls/calls.hpp"
#include "randomy/randomy.hpp"

int main(int argc, char* argv[]) {
  std::cout << "hello caracola!\n";

  std::cout << " ------ " << "\n";
  std::cout << "the result is " << adder::add2(1) << "\n";
  std::cout << "the result is " << adder::add3(1) << "\n";
  std::cout << "the result is " << adder::add4(1) << "\n";

  std::cout << " ------ " << "\n";
  calls::callback2(4);
  calls::callback1(5);
  calls::callback3(6);

  std::cout << " ------ " << "\n";
  std::cout << "Random input: " << randomy::getRandom() << "\n";
  std::cout << "Random input: " << randomy::getRandom() << "\n";
  std::cout << "Random input: " << randomy::getRandom() << "\n";
}

