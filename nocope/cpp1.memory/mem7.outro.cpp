#include <array>
#include <vector>
#include <iostream>

class Cat
{
  public:
  private:
    int m_age;
};

void foo(int num)
{
  std::vector<Cat> cats(num);

  // do some computation over Cat
};

bool bar(int num)
{
  int maxCats = 1000;     
  if (num > maxCats)        // 큰 수가 들어오면 아예 수행하지 못하게 막음
  {
    return false;
  }
  std::array<Cat, 1000> cats; 
};

int main()
{
  std::array<int, 300> a; //1.2kb
  std::array<int, 500000> b; //2mb
  std::vector<int> c(500000);  // heap


  int count;            // 퍼포먼스가 필요한 경우 힙에 넣으면 느릴 수 있음, 이를 bar 함수에서 해결하는 방법 보여줌
  std::cin >> count;
  foo(count);

  return 0;
}




/*
언제 스택을 쓰고 언제 힙을 쓰나
힙은 스택에 비해서 메모리 할당곽 해제 속도가 느리다
스택은 탑에서 할당과 해제가 일어나기에 O(1)


반면 힙은 실행중에 메모리 할당이 가능, 다이내믹 얼로케이션
스택은 스택오버플로우 위험

int, double, float 이런 애들은 스택에
array, 수백 키로바이트, 메가바이트 이런 애들은 힙

자바는 작은 용량이라도 new 키워드로 힙에 생성하는데 c++은 용량 작으면 스택
이는 클래스도 마찬가지
*/