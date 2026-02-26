#ifndef TASK1_H_
#define TASK1_H_

#include <string>

class Person {
  public:
    Person(const std::string& name, int height);
    std::string print() const;

  private:
    std::string name_;
    int height_;
};

#endif  // TASK1_H_
