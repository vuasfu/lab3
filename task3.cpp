#include "task3.h"
#include <sstream>

City::City(const std::string& name) : name_(name) {}

void City::AddPath(City* destination, int cost){
  paths_.emplace_back(destination, cost);
}

std::string City::print() const {
  std::ostringstream oss;
  oss << name_;

  if (!paths_.empty()) {
    oss << " -> ";
    for (size_t i = 0; i < paths_.size(); ++i) {
      oss << paths_[i].first->name_ << ":" << paths_[i].second;
      if (i != paths_.size() - 1) {
        oss << ", ";
      }
    }
  }

  return oss.str();
}