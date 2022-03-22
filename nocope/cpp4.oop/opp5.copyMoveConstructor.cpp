#include <iostream>
#include <string>
using namespace std;

class Cat
{
  public:
    // Cat()=default;  디폴트로 매개변수 없는 생성자 설정
    Cat(string name, int age):mName(move(name)),mAge(age){      // 1. constructor
      cout << mName << " constuctor" << endl;
    };
    Cat(const Cat& other):mName(other.mName),mAge(other.mAge)   // 3. copy constructor
    {
      // mName = other.mName;
      // mAge = other.mAge;
      cout << mName << " copy constuctor" << endl;
    }
    Cat(Cat&& other):mName(move(other.mName)),mAge(other.mAge)   // 3. move constructor, 여기서 kitty1 이 가리키는 "kitty"의 소유권이 kitty3에게 넘어옴
    {
      cout << mName << " move constuctor" << endl;
    }
    ~Cat()                                                      // 2. destructor
    {
      cout << mName << " destuctor" << endl;
    }
    void print()
    {
      cout << mName << " " << mAge << endl;
    }
  private:
    string mName;
    int mAge;
};


int main()
{
  Cat kitty1("kitty", 1);
  //Cat kitty2{kitty1};  // 어사인먼트가 아니라 카피 컨스트럭터가 호출됨  copy constructor
  Cat kitty2 = kitty1;
  Cat kitty3{move(kitty1)};

  return 0;
}


/*
위와같은 클래스가 있을때 컴파일러는 자동으로 아래와 같은 것들을 만듬
1. constructor

2. destructor

3. copy/move constructor
  copy: 기존 객체를 똑같이 카피할때 사용하는 메소드
  move: 기존 객체를 새로운 객체로 오너십 이동

4. copy/move assignment



검색어 "c++ rule of three(five) "
*/