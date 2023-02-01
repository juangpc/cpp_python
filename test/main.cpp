#include <iostream>

#include "adder/adder.hpp"
#include "calls/calls.hpp"
#include "randomy/randomy.hpp"

int main(int argc, char* argv[]) {
  std::cout << "hello caracola!\n";
  std::cout << "the result is " << adder::add2(3) << "\n";
  std::cout << "the result is " << adder::add3(3) << "\n";
  std::cout << "the result is " << adder::add4(3) << "\n";

  std::cout << " ------ " << "\n";
  calls::callback2(13);
  calls::callback1(12);
  calls::callback3(14);

  std::cout << " ------ " << "\n";
  calls::callback2(randomy::getRandom());
  calls::callback1(randomy::getRandom());
  calls::callback3(randomy::getRandom());

}

