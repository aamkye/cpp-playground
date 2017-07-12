  #include <iostream>
using namespace std;
class fig {
 public:
  virtual float pole() const{
    return -1;
  }
};

class kolo: public fig {
 public:
  int a;

  kolo(int a):a(a){}

  float pole() const {
    return a * a * 3.14;
  }
};

class kwadrat: public fig {
 public:
  int a;

  kwadrat(int a):a(a){}

  float pole() const { 
    return a*a;
  }
};

int main(){
  fig* test_figObj = new kwadrat(5);
  kwadrat* test_kwadratObj = dynamic_cast<kwadrat*>(test_figObj);

  if (test_kwadratObj) {
    cout << "Figura jest kwadratem" << endl;
  } else {
    cout << "Figura nie jest kwadratem" << endl;
  }
  return 0;
}