#include "task2.h"

PersonWithName::PersonWithName(const Name& name, int height) : name_(name), height_(height) {}

std::string PersonWithName::print() const {
  return name_.print() + ", рост: " + std::to_string(height_);
}