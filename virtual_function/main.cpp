#include <iostream>
#include <iomanip>

using namespace std;
class vFig {
 public:
  virtual float pole() const{
    return -1;
  }
};

class vKolo: public vFig {
 public:
  int a;

  vKolo(int a):a(a){}

  float pole() const {
    return a * a * 3.14;
  }
};

class vKwadrat: public vFig {
 public:
  int a;

  vKwadrat(int a):a(a){}

  float pole() const { 
    return a*a;
  }
};

class fig {
 public:
  float pole() const{
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

void wyswietlPole(vFig &figura1, fig &figura2){
   cout << setw(8) << figura1.pole() << setw(8) << figura2.pole() << endl;
}

int main(){
  vFig vFigObj;
  vKolo vKoloObj(4);
  vKwadrat vKwadratObj(4);
  vFig* wsk_vFigObj = 0;

  fig figObj;
  kolo koloObj(4);
  kwadrat kwadratObj(4);
  fig* wsk_figObj = 0;

  cout << "Virtual function in the oldest class" << endl << endl;

  cout << setw(8) << "w/i" << setw(8) << "w/o" << endl;

  cout << endl << std::setfill ('-') << std::setw (16) << " Object -" << std::setfill (' ') <<  endl;
  cout << setw(8) << vFigObj.pole() << setw(8) << figObj.pole() << endl;
  cout << setw(8) << vKoloObj.pole() << setw(8) << koloObj.pole() << endl;
  cout << setw(8) << vKwadratObj.pole() << setw(8) << kwadratObj.pole() << endl;

  cout << endl << std::setfill ('-') << std::setw (16) << " Pointer -" << std::setfill (' ') <<  endl;
  wsk_vFigObj = &vFigObj;
  cout << setw(8) << wsk_vFigObj->pole() << setw(8) << wsk_figObj->pole() << endl;
  wsk_vFigObj = &vKoloObj;
  cout << setw(8) << wsk_vFigObj->pole() << setw(8) << wsk_figObj->pole() << endl;
  wsk_vFigObj = &vKwadratObj;
  cout << setw(8) << wsk_vFigObj->pole() << setw(8) << wsk_figObj->pole() << endl;

  cout << endl << std::setfill ('-') << std::setw (16) << " Reference -" << std::setfill (' ') <<  endl;
  wyswietlPole(vFigObj, figObj);
  wyswietlPole(vKoloObj, koloObj);
  wyswietlPole(vKwadratObj, kwadratObj);

  return 0;
}