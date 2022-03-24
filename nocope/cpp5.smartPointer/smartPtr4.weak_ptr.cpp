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
    void speak()
    {
      cout << "meow" << mAge << endl;
    }
    ~Cat()
    {
      cout << "cats destructor" << endl;
    }
  private:
    int mAge;
};


int main()
{
  weak_ptr<Cat> wPtr;
  {
    shared_ptr<Cat> sPtr = make_shared<Cat>();
    wPtr = sPtr;    // sPtr 가 가리키는 오브젝트를 가리킴
  }

  if (const auto spt = wPtr.lock())     // 위크 포인터는 오브젝트를 사용하기위해서 shared ptr 를 반환받아서 사용해야함, 위에서 wPtr는 스코프가 끝나면서 사라졌기에 이 조건에 안걸림
  {
    cout << "ref count: " << wPtr.use_count() << endl;
    spt->speak();
  }
  else
  {
    cout << "pointing nothing" << endl;
  }

  return 0;

}


/*
위크포인터는 ref count 에 카운트가 안됨
라이프사이클에 관여못함
*/