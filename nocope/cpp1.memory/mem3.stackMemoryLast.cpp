#include <iostream>

class Cat 
{
  public:
    Cat()
    {
      m_age = 1;
    };
    ~Cat();
    void addAge(int arg)
    {
      m_age += arg;
    };
  private:
    int m_age;
};

int main()
{
  Cat cat;
  cat.addAge(10);

  return 0;
}





/*
스택메모리는 변수별로 쌓여가는 것이 아니라
스택프레임 단위로 쌓임
바로 이 스택프레임이 함수 단위임

컨트스트럭터, 디컨스트럭터, addAge 라는 세 함수에 따라서 스택프레임이 생김
메인 함수가 실행되면, cat 이라는 객체가 메모리에 올라가고 여기서 생성자 함수에 의해 m_age에 1로 초기화 됨
다음에 생성자 함수가 프리되고, addAge 함수가 스택프레임으로 올라감
이 스택프레임에는 return instructor address, arg(10), this 이 세가지로 구성됨
this는 object address 즉 cat 객체를 가리키고, 디스를 통해서 member variable에 접근
arg(10)에서 10을 this의 변수 즉 cat 객체의 m_age에 더해줌
이것이 끝나면 스택프레임이 프리되고 cat 객체의 m_age 는 11 이 되어있음
그 후 디컨스트럭터가 스택에 올라가고 모든 메인함수 프레임스택도 해제, 프로그램 종료

이렇게 추상적인 클래스를 더 로우한 레벨인 함수 단위로 보고, 이 함수가 스택에 어떻게 쌓이는지
멤버변수에 어떻게 접근하는지 이해해야함

*/