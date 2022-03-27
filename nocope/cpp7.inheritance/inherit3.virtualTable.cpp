#include <iostream>
using namespace std;

class Animal          
{
  public:
    virtual ~Animal()=default;
    virtual void speak()          // 8bytes
    {
      cout << "animal" << endl;
    }
  private:
    double height;       // 8bytes
};


class Cat: public Animal            
{
  public:     // virtual 정보 8바이트
    void speak() override     
    {
      cout << "meow" << endl;
    }
  private:
    double weight;       // 16bytes  Animal의 height 와 Cat의 weight로 더블 두개 16바이트
};


int main()
{
  cout << "animal size: " << sizeof(Animal) << endl;      // 16bytes
  cout << "cat size: " << sizeof(Cat) << endl;          // 24bytes

  Animal * polyCat = new Cat();     // *polyCat 포인터가 스택에 쌓이고 24바이트 고양이 객체가 힙에 생성
  polyCat->speak();                 // 고양이 객체에는 고양이 버추얼 테이블을 가리키는 주소정보가 있고, 이 버추얼 테이블에 Cat의 speak() 함수를 가리키는 주소정보가 있어서 이것으로 함수 호출
  delete polyCat;

  return 0;
}


/*
클래스에 virtual 들어가면 주소정보가 추가되서 8바이트 추가, 즉 포이터 정보가 추가
64비트 컴퓨터에서 모든 포인터는 8바이트 크기
이 포인터가 버추얼 테이블을 가리키는 것
즉 애니멀 클래스는 애니멀 버츄얼 테이블을 가리키고 이 애니멀 버추열 테이블이 virtual이 붙은
speak()함수 주소를 가지고 있는 것임

*/