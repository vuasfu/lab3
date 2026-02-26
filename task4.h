#ifndef TASK4_H_
#define TASK4_H_

#include <string>
#include <vector>
#include <utility>

class City2 {
 public:
  // Только название города
  explicit City2(const std::string& name);

  // Название + сразу набор путей (город + стоимость)
  City2(const std::string& name, const std::vector<std::pair<City2*, int>>& paths);
  void AddPath(City2* destination, int cost);
  std::string print() const;

 private:
  std::string name_;
  std::vector<std::pair<City2*, int>> paths_;
};

#endif  
