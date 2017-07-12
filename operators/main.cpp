#include <iostream>

class MyParent{
  protected:
    std::string name;
  public:
    MyParent(){}

    MyParent(std::string name):name(name){
      std::cout << "MyParent init " << this->name << std::endl;
    }

    ~MyParent(){
      std::cout << "MyParent destroy " << this->name << std::endl;
    }

    MyParent operator ()(std::string name){
      MyParent O(name);
      std::cout << "MyParent operator () " << this->name << std::endl;
      return O;
    }

    MyParent operator =(MyParent O){
      std::cout << "MyParent operator = " << this->name << std::endl;
      return *this;
    }

    int sum(int a, int b){
      return a+b;
    }
};

class MyChild: public MyParent{
  public:

    MyChild(){}

    MyChild(std::string name) : MyParent(name){
      std::cout << "MyChild init " << this->name << std::endl;
    }

    ~MyChild(){
      std::cout << "MyChild destroy " << this->name << std::endl;
    }

    MyChild operator ()(std::string name){
      MyChild O(name + "_OP1");
      std::cout << "MyChild operator () " << this->name << std::endl;
      return O;
    }

    MyChild operator =(const MyChild& O){
      MyChild N(O.name + "_OP2");
      std::cout << "MyChild operator = " << this->name << std::endl;
      return N;
    }
};

int main(){
  MyChild A("A");
  MyChild B("B");
  std::cout << std::endl;
  
  B = A("C");
  std::cout << std::endl;
  
  std::cout << B.sum(54,6) << std::endl;
  std::cout << std::endl;
  
  return 0;
}