#include <iostream>
#include <string>

int main(){
  short a = 1;
  std::cout << sizeof((+a)["23456"]) << std::endl;
}
