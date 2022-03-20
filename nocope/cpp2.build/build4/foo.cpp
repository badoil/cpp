#include "foo.h"
#include <iostream>
using namespace std;

// int a = 100;

// static int a = 100;   // 스태틱은 이 변수를 하나의 트랜슬레이션 유닛이나 오브젝트 파일 내부에서만 접근 
                      // 링커가 이 파일의 오브젝트 파일에 접근 못함 


static void bar()         // 하나의 트랜슬레이션 유닛이나 오브젝트 파일 외부로 링크를 주지 않을때 static을 쓰는 것
{
  cout << "bar" << endl;
};

void foo ()
{
  cout << "foo" << endl;
  bar();                  // static은 트랜슬레이션 유닛이나 오브젝트 파일 내부에서 접근하기에 문제없음
};


int foo2(double a)
{
  return static_cast<int>(a);     // 타입 캐스팅 
}

double bar2(int a)
{
  return static_cast<double>(a);
}