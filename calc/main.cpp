#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

class AppRunner{};
class IOParser{};
class ExprParser{};
class MathParser{};
class AppCore{};

bool validExpr(std::string expr)
{
  bool valid = true;
  valid = valid && std::count(expr.begin(), expr.end(), '(') % 2 == 0;
  return valid;
}

short containBrackets(std::string expr)
{
  return expr.find("(")!=std::string::npos ? true : false;
}

bool isOperatorPrecedence1(std::string operatorSign){
  return (operatorSign == "*" || operatorSign == "/");
}

bool isOperatorPrecedence2(std::string operatorSign){
  return (operatorSign == "+" || operatorSign == "-");
}

float calculate(std::string expr)
{
  while(containBrackets(expr))
  {
    // Bracket spliter
    std::size_t _beg = expr.find_last_of("(") + 1;
    std::size_t _end = expr.find(")", _beg);
    std::size_t _len = _end - _beg;
    float result = calculate(expr.substr(_beg, _len));
    
    // Replace expression with result without brackets
    expr.replace(_beg-1, _len+2, std::to_string(result));
  }

  //Begin
  std::vector<std::string> numbers;
  std::vector<std::string> operations;

  //Regex for splitting expressions
  std::regex re("([\\+\\-\\*\\/]{0,1}[0-9]+)([\\+\\-\\*\\/])?");
  std::smatch m;

  // Expression splitter
  while(expr.length() != 0)
  {
    std::regex_search(expr, m, re);
    if(m[1].str() != "")
    {
      numbers.push_back(m[1].str());
    }
    if(m[2].str() != "")
    {
      operations.push_back(m[2].str());
    }
    expr = expr.substr(m[0].str().length());
  }
  std::vector<std::string>::iterator it;
  it = std::find_if(operations.begin(), operations.end(), isOperatorPrecedence2);

  int pos = std::distance(it,operations.begin());

  std::cout << pos << ": " << numbers.at(pos) << std::endl;
  numbers.erase(operations.begin()+pos);

  // while((it = std::find_if(operations.begin(), operations.end(), isOperatorPrecedence2)) != operations.end())
  // {
    
  // }


  //MAGIC HERE
  //split for numbers and signs
  //merge everything
  return 5;
}

int main()
{
  //trim all the spaces
  std::string expr = "-6+-4*5";
  // std::string expr = "-(5+-2)*(6+-4)/4+1";
  // std::cout << expr << std::endl;
  if(!validExpr(expr))
  {
    throw new std::exception();
  }
  std::cout << calculate(expr) << std::endl;
  return 0;
}
/**
0) - PRECHECK + trim all the spaces
-(5+-2)*(6-4)+1
Searching for the last open bracket

1) (6-4) => 2
-(5+-2)*2+1
Searching for the last open bracket

2) (5+-2) => 3
-3*2+1
No brackets detected - do expressions by sign (check if expression is negative)

3) -3*1 => -6
-6+1
No brackets detected - do expressions by sign (check if expression is negative)

4) -6+1 = -5
==
No further expressions to calculate. Result is -5


-5 - -5 + 15
^  ^ ^
if(signPos == 0) sign is from number
number | sign (size=1) | number

Multiply first!

n  |s
-5 |-
-5 |+
15 |

n  |s
-10|+
15 |

791280882 Tomek Kondrat

*/