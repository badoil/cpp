#include <iostream>
#include <string>
using namespace std;

struct complexNum
{
  double real;
  double imag;

  complexNum(double r, double i):real(r),imag(i){};
  void print() const
  {
    cout << real << " " << imag << "i" << endl;
  }
};

complexNum operator+(const complexNum& lhs, const complexNum& rhs)
{
  complexNum c{lhs.real+rhs.real, lhs.imag+rhs.imag};
  return c;
}

class Cat
{
  public:
    Cat(string name, int age):mName(move(name)),mAge(age){};
    const string& name() const
    {
      return mName;
    }
    int age() const
    {
      return mAge;
    }
    void print(ostream& os) const   // cout은 ostream의 특수한 형태임
    {
      os << mName << " " << mAge << endl;
    };

  private:
    string mName;
    int mAge;
};

bool operator==(const Cat& lhs, const Cat& rhs)
{
  return lhs.age() == rhs.age() && lhs.name() == rhs.name();
}

bool operator<(const Cat& lhs, const Cat& rhs)
{
  if (lhs.age() < rhs.age())
  {
    return true;
  }
  return false;
}

ostream& operator<<(ostream& os, const Cat& c)      // operator overloading, print() 함수 대신에 이렇게 해도 됨
{
  return os<< c.name() << " " << c.age();
};

int main ()
{
  complexNum c1{1, 1};    // 1+i
  complexNum c2{1, 2};    // 1+2i
  complexNum c{c1+c2};    /// 2+3i
  c.print();

  Cat kitty{"kitty", 1};
  Cat navi{"navi", 2};
  kitty.print(cout);      // cout은 ostream의 특수한 형태임
  navi.print(cout);

  cout << kitty << endl;  // operator overloading 
  cout << navi << endl;

  if (kitty == navi)
  {
    cout << "they are same" << endl;
  }
  else
  {
    cout << "they are not same" << endl;
  }

  if (kitty < navi)
  {
    cout << "navi is older than kitty" << endl;
  }
  else{
    cout << "navi is not older than kitty" << endl;
  }

  return 0;
}



/*
function overloading 은 name mangling 때문에 가능
이는 static polymorphism 으로도 불림
어떤 함수가 바인딩될지 컴파일 시간에 결정되기 때문

STL 과 결합하여 더 강력한 cpp 개발을 지원
*/