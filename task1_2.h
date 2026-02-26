#ifndef TASK1_2_H_
#define TASK1_2_H_

#include <string>

class Name {
  public:
    Name(const std::string& first_name, const std::string& last_name, const std::string& ot_name );
    std::string print() const;

  private:
    std::string first_name_;
    std::string last_name_;
    std::string ot_name_;
};

#endif