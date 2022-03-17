#include <iostream>

struct ST 
{
  long a;     // 8bytes
  int b;      // 4bytes
  short c;    // 2bytes
}; 

class Cat
{
  public:
    void printCat(); // ???
  private:
    int age;      // 4bytes
    float weight;   // 4bytes
};

int foo(int c)
{
  int a;
  int b;
  int c = c+a+b;
  return c;
}

int main()
{
  std::cout << sizeof(ST) << std::endl;    // 스트럭트를 사용할때는 내부의 변수의 크기에 따라 사이즈 결정
  std::cout << sizeof(Cat) << std::endl;   // 클래스의 경우 함수는 메모리 사이즈와 관련이 없음

  Cat cat1;
  Cat cat2;

  Cat *catPtr = &cat1;
  std::cout << sizeof(catPtr) << std::endl;   // 타입과 상관없이 항상 8bytes 의 사이즈를 갖는다(64비트 환경에서)

  

  return 0;
}


/*
스트럭트를 사용할때는 내부의 변수의 크기에 따라 사이즈 결정
그런데 위에서 14바이트를 예상했지만
실제롤 16이 나옴 
메모리 액세스 패턴 때문에 컴파일러가 자동으로 패딩을 넣어서 그럼

클래스 Cat의 경우 8바이트
클래스의 경우 함수는 메모리 사이즈와 관련이 없음
*/