#include <iostream>
using namespace std;

class Animal
{
  public:
    virtual void speak()
    {
      cout << "Animal" << endl;
    }
    virtual ~Animal() = default;
  private:
    double animalData;
};

class Cat: public Animal
{
  public:
    void speak() override
    {
      cout << "meow" << endl;
    }
    void knead()
    {
      cout << "kkuk kkuk" << endl;
    }
  private:
    double catData;
};

class Dog: public Animal
{
  public:
    void speak() override
    {
      cout << "bark" << endl;
    }
    void wagTail()
    {
      cout << "wagging" << endl;
    }
  private:
    double dogData;
};


int main()
{
  Cat * catPtr = new Cat();
  Animal * animalPtr = catPtr;  // upcasting 해줘도 animalPtr -> catPtr -> 고양이객체 -> 고양이 버추얼 테이블 
  animalPtr->speak();           // 그래서 "meow" 출력
  // animalPtr->knead();        // 이건 불가, Animal 클래스에 고양이만의 함수인 knead()가 없기 때문
  delete animalPtr;

  Animal * animalPtr2 = new Animal();
  // Cat * catPtr = animalPtr;  // implicit downcast, 컴파일러가 허용 안함
  // Cat * catPtr2 = static_cast<Cat*>(animalPtr2);    // static_cast로 다운캐스트 할 수 있지만 매우 위험
  Cat * catPtr2 = dynamic_cast<Cat*>(animalPtr2);   // 이를 피하기 위해 dynamic_cast사용, 
  if (catPtr2 == nullptr)       // 다이나믹 캐스트는 캐스트하려는 객체와 포인터의 클래스가 다르면 nullPtr 를 반환
  {
    cout << "this is not cat object" << endl;
    return 0;
  }
  catPtr2->speak();
  catPtr2->knead();
  delete animalPtr;


  return 0;
}







/*
다이나믹 캐스트는 사용 안하는 것이 베스트
올바른 클래스 구조를 만들었다면 다이내믹 캐스트 없이 함수 상속 관계만으로 우리가 원하는 동작 구현할 수 있음
run time type information - RTTI
구를 c++ 가이드에서 금지시킴, 하지만 학습을 위해 알아보자

업 캐스트: 자식클래스 객체가 부모클래스 타입으로 변환
다운 캐스트: 부모클래스 객체가 자식클래스 타입으로 변환

다이나믹 캐스트: 캐스트하려는 객체와 포인터의 클래스가 다르면 nullPtr 를 반환
즉 다이나킥 캐스트를 통해서 객체와 타입과 캐스트하고자 하는 클래스 타입이 일치하는지 런타임때 알아냄
각 버추얼 테이블에 클래스의 타입 인포메이션 포인터가 저장되어 있음
*/