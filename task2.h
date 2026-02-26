#ifndef TASK2_H_
#define TASK2_H_

#include "task1_2.h"
#include <string>

class PersonWithName {
  public:
    PersonWithName(const Name& name, int height);
    std::string print() const;

  private:
    Name name_;
    int height_;
};
#endif