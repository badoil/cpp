#include <iostream>
using namespace std;


class Cat
{
  public:
    explicit Cat(int age):mAge{age}{};
    void speak() const 
    {
      cout << "meow" << endl;
    }
    void test() const 
    {
      auto lambda = [this]()
      {
        cout << "lambda" << endl;
        cout << this->mAge << endl;      // &가 this를 캡쳐해줌, this는 오브젝트의 포인터이므로  람다함수 스코프 바깥의 mAge, speak 에 접근 가능
        this->speak();
      };                           // 하지만 명시적으로 this를 쓰는 것이 좋음
      lambda();   
    }

  private:
    int mAge;
};

int main ()
{
  Cat kitty{1};
  kitty.test();

  return 0;
}