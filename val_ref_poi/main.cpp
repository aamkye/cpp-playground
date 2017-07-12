// gcc main.cpp -o main -std=c++1z -lstdc++

#include <iostream>

using namespace std;

int val(int a){
  return a+=2;
}
int ref(int& a){
  return a+=2;
}
int poi(int* a){
  return *a+=2;
}

int main(){
  int* wskC;

  int a = 2;
  int b = 2;
  int c = 2;

  wskC = &c;

  cout << a << " " << val(a) << " "<< a << " " << endl;
  cout << b << " " << ref(b) << " "<< b << " " << endl;
  cout << *wskC << " " << poi(wskC) << " "<< *wskC << " " << endl;

  return 0;
}