#include <stdexcept>
#include <iostream>
#include <vector>
#include <utility>

class TwoSum {
public:
  static std::pair<int, int> findTwoSum(const std::vector<int>& list, int sum) {
    for(auto & item1: list) {
      for(auto & item2: list) {
        if(item1 + item2 == sum) {
          // Print indexes
          return std::make_pair (&item1 - &list[0], &item2 - &list[0]);
        }
      }
    }
    return std::make_pair (-1,-1);
  }
};

#ifndef RunTests
int main() {
  std::vector<int> list;
  list.push_back(1);
  list.push_back(3);
  list.push_back(5);
  list.push_back(7);
  list.push_back(9);

  std::pair<int, int> indices = TwoSum::findTwoSum(list, 12);
  std::cout << indices.first << " and " << indices.second << std::endl;
}
#endif