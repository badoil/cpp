#define ABCD 2    // 모던c++에서 constexpr int ABCD = 2; 이렇게 사용하는 게 좋다
#include <iostream>
#include <algorithm>
#include <limits>

int main()
{
  std::cout << std::numeric_limits<uint16_t>::max() << std::endl;
  std::cout << std::max(10, 100) << std::endl;
 
  #ifdef ABCD                       // conditionality
      std::cout << "1: yes\n";
  #else
      std::cout << "1: no\n";
  #endif
  
  #ifndef ABCD
      std::cout << "2: no1\n";
  #elif ABCD == 2
      std::cout << "2: yes\n";
  #else
      std::cout << "2: no2\n";
  #endif


  std::cout << __FILE__ << std::endl;   // 전처리기가 사용하는 매크로들, 얘들도 치환
  std::cout << __LINE__ << std::endl;
  std::cout << __DATE__ << std::endl;
  std::cout << __TIME__ << std::endl;
 
}





/*
'#' 이 들어가는 부분은 전처리기가 개입
전처리기는 아래와 같이 컴파일러 전에 처리하기에 전처리기

1. conditionality
전처리기가 조건을 처리
전처리기가 코드를 컴파일러에게 보내주기 전에 약간의 변형을 함
#define ABCD 2 이놈에 의해서
    std::cout << "1: yes\n";
    std::cout << "2: yes\n";
이 둘만 컴파일러가 보게됨

2. replace
3. copy and paste
  #pragma once 로 중복복제 방지
 

#define, #ifdef 이런 애들 대신에 constexpr if c++ standard library 사용해야함

*/