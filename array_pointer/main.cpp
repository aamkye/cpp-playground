#include <typeinfo>
#include <iostream>

void F(int *arrayA, int *arrayB, size_t N) {
  int pop = 0;
  for (int index1 = 0; index1 != (sizeof(arrayA)/2); index1++) {
    pop = 1;
    for (int index2 = 0; index2 != (sizeof(arrayA)/2); index2++) {
      if (index1 != index2) {
        pop *= arrayA[index2];
      }
    }
    arrayB[index1] = pop;
  };
}

int tempA[] = {2, 1, 5, 9};
int tempB[4] = {};

int main() {
  F(tempA, tempB, 4);
  for (auto & item1 : tempB)
    std::cout << item1 << std::endl;
  return 0;
}
