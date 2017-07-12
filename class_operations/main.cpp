#include <typeinfo>
#include <iostream>

class testA {
 public:
  testA() {}
};

class testB : public testA {
 public:
  testB() {}
};

template <class C, class P>
bool IsDerivedFrom() {
  return std::is_base_of<C, P>::value;
}

template <class A, class B>
bool IsSameClass() {
  return (typeid(A) == typeid(B));
}

int main() {
  testA *obj1 = new testA();
  testB *obj2 = new testB();
  testA *obj3 = new testA();

  std::cout << IsDerivedFrom<testA, testB>() << std::endl;
  std::cout << IsSameClass<testA, testA>() << std::endl;

  return 0;
}
