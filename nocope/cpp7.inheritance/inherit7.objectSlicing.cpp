#include <iostream>
using namespace std;

class Animal
{
  public:
    //Animal(const Animal & other) = delete;      // copy constructor 삭제, 하지만 여기에 두면 자식클래스간의 copy constructor도 막아버림
    Animal() = default;
    Animal& operator=(Animal other) = delete;   // copy assignment 삭제
    virtual void speak()
    {
      cout << "Animal" << endl;
    }
    virtual ~Animal() = default;
  protected:
    Animal(const Animal & other) = delete;    // protected에 둠으로서 자식클래스간의 copy constructor 허용
  private:
    double animalData = 0.0f;
};

class Cat: public Animal
{
  public:
    Cat(double d): catData{d} {};
    void speak() override
    {
      cout << "meow" << endl;
    }
  private:
    double catData;
};

int main()
{
  Cat kitty{1.0};

  Animal & animalRef = kitty;
  animalRef.speak();                  // "meow"
  cout << "------------" << endl;
  //Animal animalObj = kitty; //copy constructor          // "Animal" 여기서 animalObj가 생성될때 버츄얼테이블 포인터와 애니멀 데이터만 가짐 따라서 copy constructor 일어날때 kitty의 매니멀데이터만 복사되고 
  //animalObj.speak();                                    // animalObj의 버추얼 테이블 포인터는 애니멀 버추얼 테이블을 가리킴, 따라서 "Animal"을 출력

  // Cat navi{kitty};         // 부모 클래스에서 copy constructor 삭제했기 때문에 자식클래스간의 copy constructor도 안됨

  return 0;
}



/*
object slicing
자식클래스 객체가 부모클래스 객체로 복사될때, 자식 객체의 정보가 잘려나간다는 의미에서 object slicing 이라고 부름
여기서는 kitty의 고양이 정보가 잘려나감
그래서 안전한 프로그래밍을 위해 copy constructor 자체를 없애줄 수 있음
그러나 이를 public에 둘 경우, 자식클래스간의 copy constructor 할때, 부모 클래스의 copy constructor 호출하는데 이거 자체가 막힘
그래서 이를 protected에 둬야함

operator overloading
이것도 상속에서 발생하는 문제
부모클래스의 오퍼레이터 정의를, 자식클래스로도 재정의해줘야 문제를 해결

이렇듯 상속은 신경써야할 것이 많음
그래서 가장 좋은 부모클래스는 pure abstract class 임
부모클래스가 pure abstract class라면 object slicing, operator overloading 모두 일어나지 않음

상속을 안쓰거나 쓰면 pure abstract class로 만들거나 하는게 좋음

*/