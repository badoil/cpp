#include <iostream>
using namespace std;

class Animal
{
  public:
    virtual void speak();
    virtual ~Animal()=default;
};

class Lion: virtual public Animal
{
  public:
    Lion()
    {
      cout << "lion constructor" << endl;
    }
    virtual void speak()
    {
      cout << "lion" << endl;
    }
    virtual ~Lion()
    {
      cout << "lion destructor" << endl;
    }
  private:
    double lionData;
};

class Tiger: virtual public Animal
{
  public:
    Tiger()
    {
      cout << "tiger constructor" << endl;
    }
    virtual void speak()
    {
      cout << "tiger" << endl;
    }
    virtual ~Tiger()
    {
      cout << "tiger destructor" << endl;
    }
  private:
    double tigerData;
};

class Liger: public Lion, public Tiger
{
  public:
    Liger()
      {
        cout << "liger constructor" << endl;
      }
    void speak() override
    {
      cout << "liger" << endl;
    }  
    virtual ~Liger()
      {
        cout << "liger destructor" << endl;
      }
  private:
    double ligerData;
};



/*
다이나믹 바인딩 할때
diamond inheritance

라이거가 타이거, 라이온으로부터 상속받고, 이 타이거 라이온이 애니멀로부터 상속받는 상황
그런데 라이거 객체를 생성할때, 타이거 라이온이 버츄얼 상속을 받지 않으면 애니멀 생성자가 두번 호출 

이를 해결하기 위해 버츄얼 상속을 해야함
다만 버추얼 상속을 하면 버추얼 상속받는 라이언 객체에 라이언 버츄얼 테이블 포인터와 라이언 데이터가 먼저 쌓이고 이어서 애니멀 버추얼 테이블 포인터와 애니멀 데이터가 쌓임(보통 상속에서는 반대순서에 라이언 데이터만 올러감)
이때 라이언 버추얼 테이블에는 thunk라이언 스피크 함수와 thunk라이언 소멸자 정보가 들어있고 이들 바로 위에 오프셋값으로 라이언캑체의 라이언 테이블로 가는 주소가 어디있는지 계산함
그것이 라이언 객체의 버츄얼 테이블 포인터이고 이것이 다시 라이언 버츄얼 테이블의 라이언 스피크함수와 소멸자 정보를 가리키고 있음
즉 라이언 버추얼 테이블에는 라이언 스피크함수 + 소멸자 정보 + 오프셋값 + thunk라이언 스피크 함수 + thunk라이언 소멸자 정보, 이렇게 들어있음

이것을 다이아몬드 상속에서 보면
버츄얼 안쓴 다이아몬드 상속의 라이거 객체:                  버츄얼 쓴 다이아몬드 상속의 라이거 객체:  
*VT                                               *VT
animal data                                       lion data
lion data                                         *VT
*VT                                               tiger data
animal data                                       liger data
tiger data                                        *VT
liger data                                        animal data

이때 애니멀 정보가 전자에서는 두개 들어가기에 어떤게 맞는건지 모르고 중복임
그래서 다이나믹 바인딩 하고 다이아몬드 상속일때 후자인 버츄얼을 쓴 상속 사용

Virtual inheritance같은경우는 실제로 잘 쓰이지 않지만 부득이하게 다이아몬드 상속을 할경우 사용해야합니다. 이번영상은 일반적인 상속이 아닌 가상상속의 내부 메카니즘을 설명하였을뿐이지, 
개발에 크게중요한내용은 아니니 C++의 모든메카니즘은 정확하게 돌아간다라는것만 이해하시고 넘어가셔도 됩니다
*/