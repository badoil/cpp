#include <iostream>
using namespace std;

class Animal          
{
  public:
    virtual ~Animal()=default;
    virtual void speak() = 0;
    // {
    //   cout << "animal" << endl;
    // }
  private:
    double height;       // 8bytes
};


class Cat: public Animal            
{
  public:     // virtual 정보 8바이트
    void speak() override     
    {
      cout << "meow" << endl;
    }
  private:
    double weight;       // 16bytes  Animal의 height 와 Cat의 weight로 더블 두개 16바이트
};









/*
pure virtual function 이란 함수 implementation이 없는 virtual function
이 pure virtual function을 하나라도 가지고 있는 클래스를 abstract class 라 함
이 abstract class는 객체생성 불가, pure virtual function을 콜할 방법이 없음
만약 자식클래스가 부모추상클래스의 pure virtual function을 override해서 구현하지 않으면
객체생성 불가하고 컴파일 불가

pure virtual function으로 부모클래스가 인터페이스만 정의하고 구현은 자식 클래스가 하게끔 함
이를 인터페이스 클래스라고 함, 이때 함수의 구현뿐만 아니라 멤버변수도 정의하지 않는 것이 유지보수
쉬운 코드를 만들 수 있음. 왜냐하면 자식클래스에서는 부모클래스의 멤버변수가 불필요할 수 있음
그런데 매번 오버라이드해서 구현하는게 귀찮을 수 있으므로, 공통적인 메소드는 구현 부모 클래스에
두고 추상부모클래스와 구현부모클래스 둘 모두 상속받는 방법도 있음(다중상속)

*/