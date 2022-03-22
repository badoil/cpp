class Animal
{
  public:
    void sleep();
  private:
    int mWeight;
};

class Cat : public Animal     // Animal 상속받음
{
  public:
    void speak();
    void age(int age);    // age를 함수라는 인터페이스를 통해 접근
    int age() const;
  private:
    int mAge;
};


int main()
{
  Cat kitty;
  Cat navi;
  kitty.speak();
  navi.speak();
  kitty.sleep();

  return 0;
}




/*
cpp는 특이하게 퍼포먼스와 oop가 함께 잡아가는 언어임
oop의 개념만 이해하는 것이 중요한게 아니라 그 oop가 로우레벨, 즉 메모리 레벨에서
어떻게 데이터가 align 되는지 알아야함
oop가 cpp의 중심이지만 너무 oop 중심으로 짜다보면 퍼포먼스를 놓칠 수 있음

클래스는 definition, 객체는 메모리에 올라가 있는 데이터

oop
1. abstraction
  예를 들어 Cat 클래스에서 고양이의 몇가지 특징만으로 클래스르 만들었다면 이것이 바로 추상화를 통한 모델링

2. encaptulation
  데이터를 내부에 두고 외부에서 접근 불가하게 만듬
  private 키워드
  void age(int age) 처럼  age를 함수라는 인터페이스를 통해 접근

3. inheritance
  class Cat : public Animal  Animal 상속받아서 kitty.sleep() 도 가능

4. polymorphism 다형성
  - 함수 오버로딩 : 같은 함수명에 다른 매개변수
  - 함수 오버라이딩: 상속받은 함수에 새롭게 함수를 덮어씌움


easy to read, understand, modify 한 코드를 만들기 위헤 oop 사용하는 것이지 그 반대가 아님
여기에 퍼포먼스까지 잡으려고 cpp 쓰는 것임.
oop는 목적이 아니다

*/