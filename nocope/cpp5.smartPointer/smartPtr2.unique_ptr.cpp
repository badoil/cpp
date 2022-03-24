#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Animal {};
class Cat : public Animal
{
  public:
    Cat():mAge{0}
    {
      cout << "cats constructor" << endl;
    }
    ~Cat() noexcept
    {
      cout << "cats destructor" << endl;
    }
  private:
    int mAge;
};

class Dog: public Animal {};

class Zoo
{
  public:
    Zoo(int a)
    {
      if (a==1)
      {
        mAnimal = make_unique<Cat>();
      }
      else
      {
        mAnimal = make_unique<Dog>();
      }
    }

  private:
    unique_ptr<Animal> mAnimal;     // 클래스 밖에서 다른 포인터가 만들어진 객체를 가리키는 없도록, 오직 mAnimal만 그 객체를 가리키므로 라이프 사이클을 신경 안써도 됨
                                    // 또한 copy/move - constructor/assignment 안만들어도 됨
};

void foo(Cat * ptr)
{
  Cat * fooPtr = ptr;
}


int main()
{

  Cat * catPtr = new Cat();  
  Cat * catPtr1 = catPtr;   //  고양이 포인터 catPtr를 고양이 포인터1 catPtr1에 복사, 주소값 복사해서 catPtr1도 catPtr와 동일한 힙에 있는 고양이 객체 가리킴
  foo(catPtr);              // 함수가 스택프레임으로 올라가고 그 안에 매개변수 ptr, 로컬변수 fooPtr 모두 고양이 객체 가리킴, 즉 4개가 모두 동일한 고양이 객체 가리킴
  delete catPtr; 

  unique_ptr<Cat> catSmartPtr = make_unique<Cat>();
  unique_ptr<Cat> catSmartPtr1 = move(catSmartPtr);   // move 를 통해서 소유권 이전만 가능, 복사 불가능


  return 0;
}






/*
exclusive ownership
어떤 객체를 단 하나의 포인터만 가리킬 수 있다는 개념

위와같이 여러 포인터들이 같은 객체를 가리키면 복사가 일어나지 않기에 효율적이지만
버그가 일어나기 쉬운 구조임, 왜냐하면 여러 포인터 중에 하나를 지울 경우 로직과 안맞고 라이프사이클에 문제 생김

특히 클래스 멤버 변수가 포인터라면 스마트 포인터를 써서 copy/move - constructor/assignment 안만들어도 되도록 할 수 있음


unique pointer

shared pointer
*/