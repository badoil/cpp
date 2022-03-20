#include "cat.h"

int main ()
{
  Cat kitty;
  kitty.speak();

  return 0;
}







/*
header, cpp file 로 이루어진 이유

전처리기가 main.cpp, cat.cpp 파일과 cat.h 헤더파일을 이용해서 하나의 translation unit을 만들고
이를 가지고  main.cpp, cat.cpp 파일 각각의 독립적인 컴파일을 통해, 각각의 오브젝트 파일을 만듬
이 독립된 오브젝트 파일을 연결하는게 링커

c++ 은 oop 언어이기에, 오브젝트의 선언 declaration 부분은 헤더 파일에
정의 definition 부분은 .cpp 파일에 넣어주는 것이 일반적

'#' 이 들어가는 부분은 전처리기가 개입
기본적으로 #include 는 .cpp 파일에 넣어야함


*/