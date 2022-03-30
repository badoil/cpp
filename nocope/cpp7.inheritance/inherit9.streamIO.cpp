#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Cat
{
  public:
    Cat(string name, int age):mName{move(name)}, mAge{age}{};
    void print(ostream & os)
    {
      os << mName << ", " << mAge << "\n";
    }

  private:
    string mName;
    int mAge;
};


int main()
{
  Cat kitty{"kitty", 3};
  Cat navi{"navi", 2};

  {   // 괄호를 쓰면 자동으로 파일 클로즈 해줌
    ofstream ofs{"test.txt"};
    if (!ofs)
    {
      cout << "test.txt can not open" << endl;
      return 0;
    }
    kitty.print(ofs);
    navi.print(ofs);
    // ofs.close(); 괄호 안에 있기에 불필요
  }
  return 0;
}











/*
상속 구조를 갖는
stream I/O 

검색어 "cpp reference io base"
*/