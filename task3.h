#ifndef TASK3_H_
#define TASK3_H_

#include <string>
#include <vector>
#include <utility>

class City {
  public:
    explicit City(const std::string& name);
    void AddPath(City* destination, int cost);
    std::string print() const;

  private:
    std::string name_;
    std::vector<std::pair<City*, int>> paths_;
};

#endif 