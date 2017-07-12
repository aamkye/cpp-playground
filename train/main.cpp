#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;

class TrainComposition {
public:

  std::vector<int> train;
  void attachWagonFromLeft(int wagonId) {
    train.insert(train.begin(), wagonId);
  }

  void attachWagonFromRight(int wagonId) {
    train.insert(train.end(), wagonId);
  }

  int detachWagonFromLeft() {
    int val = train.front();
    train.erase(train.begin());
    return val;
  }

  int detachWagonFromRight() {
    int val = train.back();
    train.erase(train.end()-1);
    return val;
  }
};

#ifndef RunTests
int main() {
  TrainComposition tree;
  tree.attachWagonFromLeft(7);
  tree.attachWagonFromLeft(13);
  std::cout << tree.detachWagonFromRight() << "\n"; // 7
  std::cout << tree.detachWagonFromLeft(); // 13
}
#endif
