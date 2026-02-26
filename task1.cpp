#include "task1.h"

Person::Person(const std::string& name, int height) : name_(name), height_(height) {}
std::string Person::print() const {
  return name_ + ", рост: " + std::to_string(height_);
}
