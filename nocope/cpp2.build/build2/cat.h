#include <vector>
#include <string>


// #ifndef CAT_H 
// #define CAT_H
#pragma once
class Cat
{
  public:
    void speak();
  private:
    std::vector<std::string> mFriends;
};
// #endif



/*

기본적으로 #include 는 .cpp 파일에 넣어야함
그러나
private:
  std::vector<std::string> mFriends; 이처럼 vector, string 라이브러리 필요하면 헤더파일에도 
#include 써야함

#ifndef CAT_H
#define CAT_H
class Cat
{
  public:
    void speak();
  private:
    std::vector<std::string> mFriends;
};
#endif
요래 하면, 전처리기를 사용하여 헤더파일의 켓 클래스를 중복으로 불러오는 에러를 방지
#pragma once 이거 사용하면 더 간단
*/