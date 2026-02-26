#include "task1_2.h"

Name::Name(const std::string& first_name, const std::string& last_name,
           const std::string& ot_name)
    : first_name_(first_name), last_name_(last_name), ot_name_(ot_name) {}

std::string Name::print() const {
  std::string result;

  if (!first_name_.empty()) {
    result += first_name_;
  }

  if (!last_name_.empty()) {
    if (!result.empty()) {
      result += " ";
    }
    result += last_name_;
  }

  if (!ot_name_.empty()) {
    if (!result.empty()) {
      result += " ";
    }
    result += ot_name_;
  }
  return result;
}