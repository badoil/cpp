#include <iostream>
using namespace std;

class Plus
{
  public:
    explicit Plus(int a):localVar{a} {};
    int operator()(int x) const
    {
      return localVar + x;
    }
  private:
    int localVar;
};

int main ()
{
  Plus plus5(5);
  Plus plus3(3);

  cout << plus5(5) << endl;     // function object 만들어줌
  cout << plus3(3) << endl;

  return 0;
}



/*
함수형의 가장 근본은 함수를 변수처럼 다룬다는것
자바스크립트의 closure 가 대표적임

cpp에서도 그렇게 할 수 있는데, 이때 함수 오브젝트를 사용
클래스로 만든 오브젝트를 호출 가능한 객체로 만들기 위해서 오퍼레이터 오버로딩 사용

*/