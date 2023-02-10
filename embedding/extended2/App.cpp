#include "App.hpp"
#include <iostream>

App::App():
exitString("exit") {
  returnValue = startLoop();
}

int App::startLoop() {
  bool continueLoop = true;

  while (continueLoop) {
    std::cout << "\nEnter function: ";
    getline(std::cin, inputString);
    if (inputString == exitString) {
      continueLoop = false;
    }
    std::cout <<"You typed: " << inputString << "\n";
  }
  return 0;
}

int App::getReturnValue() const {
  return returnValue;
}

