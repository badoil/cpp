
#include <iostream>
#include <string>
using namespace std;

class Cat
{
  public:
    explicit Cat(int age):mAge(age) {};
    void speakAge() const               // speak() 함수는 mName을 변화시키지 않음
    {
      cout << "age: " << mAge << endl;
    }
  
  private:
    int mAge;     // mutable 붙이면 변수 변경 가능해짐, 하지만 가급적 사용하지 말것
};

class Cats
{
  public:
    void age(int age)
    {
      mAge = age;
    }
    int age() const
    {
      return mAge;
    }

    void name(string name)
    {
      mName = name;
    }
    // string name() const   // 여기서 return by value 를 하고 있으므로 복사가 한번 일어남
    // {
    //   return mName;
    // }
    const string& name() const   // 그래서 return by reference 를 하고 있으므로 복사가 안일어남
    {
      return mName;
    }
    

  private:
    string mName;
    int mAge;
};


int main()
{
  // const Cat navi = 1;   // implicit conversion 암묵적으로 age 에 1이 할당, 이를 방지하기 위해 explicit 키워드 사용
  const Cat navi(1);      // const 를 여기 붙이면 const 붙인 함수만 호출할 수 있음
  navi.speakAge(); 

  return 0;
}




/*
const 안전한 C++ 코드 작성을 위해서는 const를 붙일수 있는 모든곳에 const를 붙이는 습관. operator overloading 의 경우  함수 내에서 전달받은 인자를 수정할 이유가 없기때문에 const를 붙임
함수의 경우에도 멤버 변수의 값을 바꾸지 않는다면 무조건 const 붙여줌
컴파일러가 에러를 잡는데도 도움이 됨

explicit
constructor에 매개변수가 하나일때는 explicit 키워드 사용해주는 것이 좋음

friend
이 키워드는 oop 컨셉을 무너뜨릴 수 있으므로 가급적 사용말것

*/