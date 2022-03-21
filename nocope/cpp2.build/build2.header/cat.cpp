#include <iostream>  //
#include "cat.h"

void Cat::speak()
{
  std::cout << "meow" << std::endl;
}



/*
전처리기는 
#include "cat.h" 이것을 보고
아래와 같이 치환함

class Cat
{
  public:
    void speak();
};

#include <iostream>  괄호는 standard library
#include "cat.h"    따옴표는 유저가 만든 파일

기본적으로 #include 는 .cpp 파일에 넣어야함

*/