#include <iostream>
#include <vector>
template <typename I>
int bitShift(std::vector<I> a){
    long int value = 0;
    int sizeB = (a.size() - 1)*8;

    for(const auto& item: a){
        value += item << sizeB;
        sizeB-=8;
    }
    return value;
}

int main(){
    std::vector<int> b = {0, 116, 87, 53, 25, 0}; // = 1463097716
    // std::vector<int> b = {255,255,255,255,255}; // = 1463097716
    std::cout << bitShift(b) << std::endl;

    //1463097716 unsigned
    //1463097716 unsigned char
    //1463097600 long long int
    //1463097600 long int
    //1463097716 int
}
