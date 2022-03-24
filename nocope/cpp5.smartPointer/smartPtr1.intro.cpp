#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Cat
{
  public:
    Cat(int age):mAge{age}
    {
      cout << mAge << "constructor" << endl;
    }
    ~Cat()
    {
      cout << "destructor" << endl;
    }
  private:
    int mAge;
};

class Cats
{
  public:
    Cats():mAge{0}
    {
      cout << mAge << "cats constructor" << endl;
    }
    ~Cats() noexcept
    {
      cout << "cats destructor" << endl;
    }
  private:
    int mAge;
};

void foo()
{
  cout << "foo start" << endl;
  unique_ptr<Cat> catPtr = make_unique<Cat>(2);   // 스마트 포인터
  vector<Cats> cats(5);                           // array 에 대한 스마트 포인터
  cout << "foo end" << endl;                      // 저 둘의 디스트럭터는 "foo end" 출력후에 호출되는데, 이는 스마트 포인터가 함수라는 스코프 베이스 이기 때문임
}


int main()
{
  Cat kitty{1};

  Cat * catPtr = new Cat(1);    // constructor 호출
  delete catPtr;                // desctructor 호출, 삭제를 까먹으면 메모리 릭 발생, 스택에 포인터 catPtr는 프로그램 종료 후 삭제되었는데, 힙에 객체는 그대로 있음 

  unique_ptr<Cat> catSmartPtr = make_unique<Cat>(3);   // 삭제 안해줘도 자동으로 desctructor 호출, 스코프 베이스

  cout << "before foo" << endl;
  foo();
  cout << "after foo" << endl;

  return 0;
}





/*
RAII
Resource Aquisition Is Initialization
리소스의 라이프사이클과 오브젝트의 리소스를 일치시킨다
리소스: heap memory, thread, file access, db connection, mutex

이번챕터에서 오브젝트는 스마트 포인터, 리소스는 힙 메모리
이 둘의 라이프사이클을 일치시키면 메모리릭을 원천적으로 차단할 수 있음


unique pointer : exclusive ownership

shared pointer : shared ownership
*/