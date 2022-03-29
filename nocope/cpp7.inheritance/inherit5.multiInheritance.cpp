#include <iostream>
using namespace std;

class Lion
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

class Tiger
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

int main()
{
  Liger liger;
  cout << sizeof(Liger) << endl;    // 40bytes

  Tiger* polyTiger = new Liger();   // 이때 타이거 포인터는 라이거 버츄얼 테이블을 가리킴, 이때 포인터는 라이거 객체중 타이거부분만 볼 수 있음 
  polyTiger->speak();               // 라이거 버츄얼 테이블에 의해서 liger 를 출력
  delete polyTiger;

  Liger* polyLiger = new Liger();   // 이때 포인터는 라이거 객체중 타이거, 라이언 모두 볼 수 있고 이 둘이 라이거 버츄얼 테이블을 가리킴
  polyLiger->speak();
  delete polyLiger;

  return 0;
}





/*
지금까지 우리는 linear한 상속, 즉 부모클래스가 하나인 상속만 다룸
왜 선형적이냐면 상속 모양이 하나의 선과 같아서 그럼
다중상속에서 상속받는 순서에 따라 생성자가 호출되고 소멸자는 그 반대로 호출

위에서는 
lion constructor
tiger constructor
liger constructor
liger destructor
tiger destructor
lion destructor
이 순서로 진행

버츄얼테이블을 저장하는 포인터가 다중상속에서는 어떻게 저장되는지 알기 위해서 사이즈 봐야함
cout << sizeof(Liger) << endl 는 40bytes 출력하는데 
라이거 객체가 라이언객체(*Lion V table(8bytes) + lion data(8bytes)) + 타이거객체(*Tiger V table(8bytes) + tiger data(8bytes)) + 라이거데이터(8bytes) 로 이루어짐
총 40바이트

diamond inheritance
다음편 참고 

*/