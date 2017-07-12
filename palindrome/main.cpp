#include <string>
#include <stdexcept>
#include <iostream>
#include <cmath>

class Palindrome {
public:
  static bool isPalindrome(const std::string& word) {
    for(int a = 0; a != floor(word.length() / 2); a++) {
      if(word[a] != word[word.length()-a-1]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  std::cout << Palindrome::isPalindrome("deleveled");
}