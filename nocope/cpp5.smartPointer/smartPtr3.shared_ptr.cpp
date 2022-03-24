#include <iostream>
#include <memory>
#include <vector>
using namespace std;


class Cat
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
    shared_ptr<Cat> mVar;
  private:
    int mAge;
};

int main()
{
  // Cat * catPtr = new Cat();
  // Cat * catPtr1 = catPtr;

  shared_ptr<Cat> catPtr = make_shared<Cat>();
  cout << "ref count: " << catPtr.use_count() << endl;
  shared_ptr<Cat> catPtr1 = catPtr;
  cout << "ref count: " << catPtr.use_count() << endl;   

  shared_ptr<Cat> mPtr = make_shared<Cat>();
  mPtr->mVar = mPtr;                                          // 자기참조, mPtr이 Cat.mVar을 가리키고 있는 상황에서 Cat.mVar가 자기 자신을 가리킴, 즉 2개의 ref count
  cout << "mPtr ref count: " << catPtr.use_count() << endl;   // 2가 나오고, 메인함수가 종료되면서 mPtr는 사라지지만 자신을 가리크는 포인터는 남아서 메모리릭 발생 

  shared_ptr<Cat> kitty = make_shared<Cat>();
  shared_ptr<Cat> navi = make_shared<Cat>();
  kitty->mVar = navi;     // 순환참조 발생
  navi->mVar = kitty;     // 순환참조일때도 메모리릭이 일어남

  return 0;
}


/*
unique pointer: exclusive ownership

shared pointer
공유하는 포인터라도 RAII 를 지켜줘야하는데 이를 지키면서도
언제 객체를 해제해줘야 하는지 알고 있다는 뜻
ref count 그 객체를 가리키는 레퍼런스가 몇개인지 추적하는 방식으로 동작
레퍼런스 카운트가 0이 되는 순간 클래스의 디스트럭터를 콜해주면서 오브젝트를 해제
여러개의 shared pointer들이 오브젝트의 라이프 사이클을 공유할 수 있게됨

메인 함수가 끝나면서 ref count 가 0이 되면서 디스트럭터 호출
위에서 보듯이 자기참조, 순환참조가 일어나면 어쩔 수 없이 메모리릭은 발생
*/