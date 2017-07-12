#include <iostream>

class baseGenerator{
 public:
  baseGenerator(){}
  virtual ~baseGenerator(){}
  virtual int generate(){
    return 1;
  }
};

class newGenerator : public baseGenerator {
 public:
  newGenerator(){}
  virtual ~newGenerator(){}
  virtual int generate(){
    return 2;
  }
};

class printer{
 public:
  printer(baseGenerator* gen): gen(gen){}
  virtual ~printer(){}
  void print(){
    std::cout << this->gen->generate() << std::endl;
  }
 private:
  baseGenerator* gen;
};

int main(){
  newGenerator gr;
  printer pr(&gr);
  pr.print();
  return 0;
}