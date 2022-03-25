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
  int three{3};     
             // 아리가 lambda expression, 사용자가 함수의 리턴 타입 정해주는 것보다 auto 쓰면 가독성 더 좋음, [ ]는 캡쳐부분
  auto lambdaPlus3 = [three](int x)      
  {
    return three + x;
  };

  Plus plus5(5);
  Plus plus3(3);

  cout << plus5(5) << endl;     // function object 만들어줌 
  cout << plus3(3) << endl;
  cout << lambdaPlus3(3) << endl;   // 람다함수의 인수는 람다함수 정의의 매개변수부분  

  return 0;
}



/*
함수형의 가장 근본은 함수를 변수처럼 다룬다는것
자바스크립트의 closure 가 대표적임

cpp에서도 그렇게 할 수 있는데, 이때 함수 오브젝트를 사용
클래스로 만든 오브젝트를 호출 가능한 객체로 만들기 위해서 오퍼레이터 오버로딩 사용

람다함수
어셈블리언어로 보면 function object와 람다함수는 완전 동일
람다함수의 캡쳐는 capture by value, by reference, by object(this) 로 나눔
capture by value : 람다함수 안에서 사용하는 변수나 오브젝트를 밸류로 캡쳐한다는 뜻, 딥 카피 된다는 뜻
  즉 함수 오브젝트의 localVar과 같이 메모리에 남아있게 된다는 뜻, 캡쳐된 값이 딥 카피되어서 메모리에 올라가므로
  너무 큰 값은 레퍼런스로 넘겨야함

capture by reference : [&three] 이렇게 레퍼런스만 넘김
  [=] , [&] 이렇게 하면 암묵적으로 밸류나 레퍼런스 찾아서 캡쳐하기도 함

*/