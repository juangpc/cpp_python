#include "calls.hpp"
#include <iostream>

extern "C" {

void calls_call1(int a) {
  calls::call1(a);
}

void calls_call2(int a) {
  calls::call2(a);
}

void calls_call3(int a) {
  calls::call3(a);
}

}

namespace calls {
 
void call1(int a) {
  std::cout << "Hello from call1! with input "<< a << "\n"; 
}

void call2(int a) {
  std::cout << "Hello from call2! with input "<< a << "\n"; 
}

void call3(int a) {
  std::cout << "Hello from call3! with input "<< a << "\n"; 
}

}

