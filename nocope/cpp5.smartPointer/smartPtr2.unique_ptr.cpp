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




/*
exclusive ownership
어떤 객체를 단 하나의 포인터만 가리킬 수 있다는 개념


unique pointer

shared pointer
*/