#include <iostream>
#include <string>
using namespace std;

void storeByLRef(const string & s)     // 이때 레퍼런스로 파라미터 넘기기에 복사는 안일어남, 하지만 함수 내부에서 힙의 "abc"복사되고 b가 이를 가리킴
{
  string b = move(s);   // const 있지만  move 쓰면 카피가 됨 
}

class Cat
{
  public:
    void setName (string name)
    {
      mName = move(name);
    }
    private:
      string mName;
};

int main()
{
  string a = "nocode";
  storeByLRef(a);
  cout << "a: " << a << endl;     // "nocode" 찍힘, a 는 불변

  string b = move(a);           // ownership을 a에서 b로 넘겨준 것임
  cout << "b: " << b << endl;   // "nocode" 찍힘
  cout << "a: " << a << endl;   // 소유권이 넘어가서 아무것도 안찍힘


  Cat kitty;
  string s = "kitty";

  // kitty.setName(s);   //1 copy, 최초의 "kitty"를 s가 가리키고, 복사한 "kitty"를 name 이 가리키게되고 이 소유권을  kitty.mName에 넘겨줌
  kitty.setName("navi"); // 0 copy, kitty.mName 이 스택에 만들어지고, 이는 아직 아무것도 가리키지 않음. 이때 컴파일러는 setName 함수가 알밸류를 넘기는 것을 알고 name이 가리키는 힙 공간에 바로 "navi"를 
                         // 가리키게 하고, move로 소유권을 mName에게 넘기며 끝

  return 0;
}