#include <iostream>
using namespace std;

int a = 0;
void foo();   // declaration, 링커는 이 선언을 foo.cpp 파일에서 찾음. 기본적으로 함수는 extern 임

int foo2(double a);
double bar2(int a);

int main()
{
  // extern int a;       // 이 파일 바깥 어딘가에 있어라고 알려줌
  cout << a << endl;
  foo();

  int b = 100;
  double c = bar2(b);
  int d = foo2(c);

  return 0; 
}




/*
extern, static


*/