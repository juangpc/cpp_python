#ifndef EMBEDDING_EXTENDED2_APP_HPP_
#define EMBEDDING_EXTENDED2_APP_HPP_

#include <string>

class App {
 public:
  App();

  int getReturnValue() const;
 private:
  int startLoop();

  int returnValue;
  std::string inputString;
  const std::string exitString;
};



#endif  // EMBEDDING_EXTENDED2_APP_HPP_
