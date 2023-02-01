
#include <iostream>
#include <random>

#include "randomy/randomy.hpp"

namespace randomy {

int getRandom() {
  std::random_device r;
  std::default_random_engine e1(r());

  std::uniform_int_distribution<int> uniform_dist(0, 99);
  return uniform_dist(e1);
}

void printRandom() {
  std::random_device r;
  std::default_random_engine e1(r());

  std::uniform_int_distribution<int> uniform_dist(0, 99);
  std::cout << "Random number: " <<  uniform_dist(e1) << "\n";
}

}  // namespace randomy
