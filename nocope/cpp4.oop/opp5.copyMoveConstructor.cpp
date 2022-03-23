#include <iostream>
#include <string>
using namespace std;

class Cat
{
  public:
    // Cat()=default;  디폴트로 매개변수 없는 생성자 설정
    // Cat()=delete;   객체생성 막음
    // Cat(const Cat& other) = delete;    copy constructor 자동생성 막기
    // Cat& operator=(const Cat& other) = delete;     copy assignment 자동생성 막기

    Cat(string name, int age):mName(move(name)),mAge(age){      // 1. constructor
      cout << mName << " constuctor" << endl;
    };
    
    Cat(const Cat& other):mName(other.mName),mAge(other.mAge)   // 3. copy constructor
    {
      // mName = other.mName;
      // mAge = other.mAge;
      cout << mName << " copy constuctor" << endl;
    };
    
    Cat(Cat&& other):mName(move(other.mName)),mAge(other.mAge)   // 3. move constructor, 여기서 kitty1 이 가리키는 "kitty"의 소유권이 kitty3에게 넘어옴
    {
      cout << mName << " move constuctor" << endl;
    };

    Cat& operator=(const Cat& other)                // 4. copy assignment, 고양이 객체 레퍼런스를 받아서 복사
    {
      mName = other.mName;
      mAge = other.mAge;
      cout << mName << " copy assignment" << endl;
      return *this;      // Cat& 레퍼런스를 리턴
    };

    Cat& operator=(Cat&& other)
    {
      mName = move(other.mName);   // r-value 로 바꿔줘서 소유권 이전
      mAge = other.mAge;
      cout << mName << " move assignment" << endl;
      return *this;     // Cat& 레퍼런스를 리턴
    }

    ~Cat()                                              // 2. destructor
    {
      cout << mName << " destuctor" << endl;
    };
    void print()
    {
      cout << mName << " " << mAge << endl;
    };
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


  Cat kitty{"kitty", 1};  // copy assignment
  Cat navi{"navi", 2};
  kitty = navi;       // 키티 객체가 나비 객체로 복사
  kitty.print();      // 이름이 "navi", 2 로 나옴

  kitty = move(navi); // move assignment
  kitty.print();
  navi.print();     // navi의 mName의 소유권이 kitty에게로 옮겨가서 나이만 프린트됨

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


destructor,  move constructor, move assignment
얘들은 noexcept를 붙여줌. 이들은 새로운 리소스를 요청하고 있지 않음
사실 고양이 클래스의 멤버변수로 포인터를 쓰지 않기때문에 위와 같이 직접 해줄 필요 없음
컴파일러가 자동으로 해줌
고로 생산성 높이 개발하려면 포인터로 관리하지 않는게 좋음 

그러면 반대로 copy/move constructor, copy/move assignment 둘다 막을 수 있음
싱글턴 패턴같은 경우 객체가 하나만 필요하기 때문에 copy constructor/assignment 막아야함


검색어 "c++ rule of three(five) "
*/