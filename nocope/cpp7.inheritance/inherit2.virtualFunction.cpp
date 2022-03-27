
#include <iostream>
#include <array>
using namespace std;

class Animal
{
  public:
    // Animal()
    // {
    //   cout << "animal constructor" << endl;
    // }
    // virtual ~Animal()       // virtual 키워드가 없으면 상속받은 자식 클래스의 객체가 소멸자를 호출 못함
    // {
    //   cout << "animal destructor" << endl;
    // }
    virtual ~Animal()=default;
    virtual void speak()
    {
      cout << "animal" << endl;
    }
};


class Cat: public Animal
{
  public:
    // Cat()
    // {
    //   cout << "cat constructor" << endl;
    // }
    // ~Cat()
    // {
    //   cout << "cat destructor" << endl;
    // }
    void speak() override    // 상속받은 애는 override 표시
    {
      cout << "meow" << endl;
    }
};

class Dog: public Animal
{
  public:
    void speak() override
    {
      cout << "bark" << endl;
    }  
};

int main ()
{
  // Cat kitty;

  // Cat * catPtr = new Cat;
  // delete catPtr;

  // Animal * polyCat = new Cat();   // 다이내믹 폴리모피즘
  // delete polyCat;

  // int i;
  // cin >> i;
  // Animal * animalPtr;
  // if(i==1)
  // {
  //   animalPtr = new Cat();
  // }
  // else
  // {
  //   animalPtr = new Animal();
  // }
  // animalPtr->speak();
  // delete animalPtr;


  array<Animal*, 5> animals;
  for(auto & animalPtr: animals)
  {
    int i = 0;
    cin >> i;
    if (i==1)
    {
      animalPtr = new Cat();
    }
    else
    {
      animalPtr = new Dog();
    }
  }
  for(auto & animalPtr: animals)
  {
    animalPtr->speak();
    delete animalPtr;
  }
  
 
  return 0;
}





/*
상속에서 생성자, 소멸자 어떤 순서로 실행되는지
virtual function 이 무엇인지

부모 클래스의 생성자 -> 자식클래스의 생성자 -> 자식클래스의 소멸자 -> 부모 클래스의 소멸자
이는 포인터도 마찬가지

dynamic polymorphism:
상속과 virtual 로 컴파일이 아닌 런타임때 어떤 객체를 생성할지 결정
그 객체의 상속받고 override한 virtual function을 만드는 것임

이때 부모 클래스의 소멸자가 virtual 키워드가 없으면 상속받은 자식 클래스의 객체가 소멸자를 호출 못함

*/