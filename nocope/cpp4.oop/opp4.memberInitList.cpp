class Cat
{
  public:
    Cat()
    {
      mAge = 1;
    }
    Cat(int age)
    {
      mAge = age;
    }
  private:
    int mAge;
};

class Zoo
{
  public:
    Zoo(int kittyAge)
    {
      mKitty = Cat(kittyAge);   // 여기서 객체 생성  mKitty.mAge = 5
    }
    Zoo(int kittyAge):mKitty(Cat(kittyAge)){}; // 이렇게 해주면 위처럼 객체생성 할 필요 없음
  private:
    Cat mKitty;               // 이미 있었던 객체 mKitty.mAge = 1 에 위의 객체 값 5가 들어오고 위의 객체는 소멸  
};    

int main()
{
  Zoo cppZoo(5);
  return 0;
}


/*
멤버변수를 초기화할때 아래와 같은 방법 사용

위에서 Zoo 의 생성자가 mKitty = Cat(kittyAge) 로 객체를 생성할 필요 없음

이를 없애는게 member initialize list 임
Zoo(int kittyAge):mKitty(Cat(kittyAge)){} 이와같이 하면 됨
*/