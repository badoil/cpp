#include <iostream>
#include <memory>
#include <vector>
using namespace std;


class Cat
{
  public:
    Cat():mVar{make_unique<int>(1)}
    {
      cout << "cats constructor" << endl;
    }
    // Cat(const Cat & other):mVar{make_unique<int>(*other.mVar)}{}  // 컴파일러가 삭제한 copy constructor를 개발자가 이런 식으로 살릴 수 있긴 함
    // 이러면 힙에 새로운 1을 복사해서 이를 navi.mVar 가리키고 exclusive ownership 위반하지 않게됨
     
    ~Cat()
    {
      cout << "cats destructor" << endl;
    }
  private:
    unique_ptr<int> mVar;
};


int main ()
{
  Cat kitty;
  // Cat navi{kitty};   // 바로 에러, 이유는 kitty.mVar과 navi.mVar 모두 힙에 있는 1을 가리키는데 이는 unique_ptr의 exclusive ownership 위반이기 때문
                        // 컴파일러가 copy constructor를 삭제한 것

  return 0;
}




/*

위와같이 unique_ptr를 사용했을때 생기는 문제점을 인식하고 있어야함

shared_ptr를 사용했을때 생기는 문제점도 마찬가지
같은 오브젝트를 가리키고 있기 때문에 이를 각주로 표시하거나 그러면 좋음 


*/