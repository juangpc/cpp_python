#include <iostream>

#include "calls/calls.hpp"

namespace calls {

void callback1(int a) {
  std::cout << "Hello from callback1! With input: << " << a << "\n";
}

void callback2(int a) {
  std::cout << "Hello from callback2! With input: << " << a << "\n";
}

void callback3(int a) {
  std::cout << "Hello from callback3! With input: << " << a << "\n";
}

}  // namespace calls

