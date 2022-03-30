#include <iostream>
#include <string>
using namespace std;

class Cat
{
  public:
    explicit Cat(string name):mName{name}{
      cout << mName << "Cat constructor" << endl;
    };
    ~Cat()
    {
      cout << mName << "~Cat()" << endl; 
    }
    Cat(const Cat& other): mName(other.mName)
    {
      cout << mName << "copy constructor" << endl;
    }
    Cat(Cat&& other) noexcept: mName{move(other.mName)}   // noexcept 붙여주면 힙에서 무브 컨스트럭터가 호출됨
    {
      cout << mName << "move constructor" << endl;
    }
  private:
    string mName;
};


int main()
{
  vector<Cat> cats;
  // cats.reserve(2);
  cats.emplace_back("kitty");
  cats.emplace_back("navi");

  return 0;

}


/*
reserve()로 메모리공간을 확보 없이 emplace_back을 하면 
힙에 배열이 복사 또는 이동해서 새로운 메모리 공간을 확보하게됨
noexcept 붙여주면 move constructor 무브 컨스트럭터가 호출되서 메모리 최적
처음에 copy constructor가 호출되서 복사가 일어난 것은 익셉션이 생길 수 있어서
안전하게 카피 컨트스트럭터 콜한 것임

가장 좋은 것은 처음부터 reserve()로 공간 확보하는 것
벡터 쓸때는 리저브로 메모리 공간 확보하는 것이 젤 중요!!
*/