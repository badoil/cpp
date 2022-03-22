#include <iostream>
using namespace std;

class Cat     // 32바이트 할당
{
  public:
    void speak()
    {
      static int count = 0;       // 여기에 카운트를 두면 아무데서나 접근 못하면서 이전과 동일한 기능 가능
      count += 1;
      cout << "meow" << count << endl;
    }
    static void staticSpeak()   //static function
    {
      cout << "static" << endl;
      // cout << mAge << endl  스태틱 함수에서는 멤버변수 못 부름. 멤버변수는 this로 부르는데 이 this와 바인딩 되어있지 않기 때문에
      // speak()        스태틱 함수에서는 멤버함수도 못 부름. 멤버함수도  this로 부르는데 이 this와 바인딩 되어있지 않기 때문에
    }
    // static int count;   // 스태틱 멤버변수는 프로그램 실행전에 초기화 필요

  private:
    int mAge;

};

// int Cat::count = 0;   // 스태틱 멤버변수는 프로그램 실행전에 초기화 필요 


int main()
{
  Cat kitty;
  kitty.speak();
  // Cat::staticSpeak();     // 오브젝트 안만들고 바로 함수 콜
  // kitty.staticSpeak();    // 스태틱 함수도 멤버 함수니까 객체로 콜 할 수 있음

  Cat navi;
  navi.speak();

  return 0;
}




/*
1. static variable
  kitty.speak(),  navi.speak() 이 둘을 콜하면 카운트가 1, 2 로 올라감
  즉  다른 객체 둘이 count 라는 변수를 공유함,
  이는 메모리에 오브젝트와 함께 올라가는 것이 아니라 힙 메모리보다 더 밑에 스태틱 메모리 공간에 올라가서
  이를 공유하는 것


2. static function
  static void staticSpeak()
  Cat::staticSpeak();  
  오브젝트 안만들고 바로 함수 콜
  이는 static이 오브젝트와 연관이 없기 때문
  클래스의 this는 object address를 가리키는데
  static function은 이 this와 바인딩 되어 있지 않음
  그래서 오브젝트를 생성하지 않아도 콜이 될 수 있음

3. static variable in a function
  void speak() 스피크 함수 안에 static 선언되어도
  메모리 공간은 동일하게 힙 메모리보다 더 밑에 스태틱 메모리 공간에 올라가서 공유
  그러나 초기화 시점은 다름
  프로세스 실행시 vs 스피크 함수 콜할때
  이 스태틱 사용해서 싱글톤 패턴 만들 수 있음
  뒤에 디자인 패턴에서 다룸

*/