#include "task4.h"
#include <sstream>


City2::City2(const std::string& name) : name_(name) {}

City2::City2(const std::string& name,
             const std::vector<std::pair<City2*, int>>& paths)
    : name_(name), paths_(paths) {}

// Добавление пути после создания города
void City2::AddPath(City2* destination, int cost) {
  paths_.emplace_back(destination, cost);
}

// Формирование строки с названием города и всеми путями
std::string City2::print() const {
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
