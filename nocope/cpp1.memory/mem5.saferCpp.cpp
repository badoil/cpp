#include <stdlib.h>
#include <iostream>
#include <memory>
#include <vector>


class Cat
{
  public:
    Cat()
    {
      std::cout << "meow" << std::endl;
    }
    ~Cat()
    {
      std::cout << "bye" << std::endl;
    }
  private:
    int mAge;
};

int main ()
{
  // c style heap Cat
  // Cat * catp = (Cat *)malloc(sizeof(Cat));      // 컴파일하고 실행시켜도 생성자와 파괴자가 동작안합, 씨 스타일로 객체를 할당하면 안된다는 뜻
  // free(catp);

  // c++ style heap Cat
  // Cat * catp = new Cat;         // 이렇게 c++ style로 해야함
  // delete catp;
  
  // safer c++ style heap Cat
  // std::unique_ptr<Cat> catp = std::make_unique<Cat>;         // 이렇게 c++ style로 해야함


  // c style heap Cats(cat array)
  // Cat * catap = (Cat *)malloc(sizeof(Cat)*5);
  // free(catap);

  // c++ style heap Cats(cat array)
  // Cat * catap = new Cat[5];
  // delete [] catap;

  // safer c++ style heap Cats(cat array)
  // std::vector<Cat> cats(5);


  //  c style heap int
  // int * ip = (int *)malloc(sizeof(int));
  // *ip = 100;
  // free(ip);

  //  c++ style heap int
  // int * ip = new int;
  // *ip = 100;
  // delete ip;

  // safer c++ style heap int
  // std::unique_ptr<int> ip = std::make_unique<int>();
  // *ip = 100;


  // c style heap arry
  // int * iap = (int *)malloc(sizeof(int)*5);   // 4bytes 5개 즉 20바이트 할당된 어레이
  // iap[0] = 100;   // 그 어레이의 첫 인덱스에 100
  // free(iap);

  // c++ style heap array
  // int * iap = new int[5];   // 4bytes 5개 즉 20바이트 할당된 어레이
  // iap[0] = 100;   // 그 어레이의 첫 인덱스에 100
  // delete [] iap;

  // safer c++ style heap array
  // std::vector<int> ints(5);
  // ints[0] = 100;

  std::cout << "how many cats do u need?" << std::endl;
  int count;
  std::cin >> count;

  std::vector<Cat> cats(count);     // 이와같이 컴파일때 벡터라는 오브젝트를 스택에 힙메모리와 연결된 포인터를 올려놓고, 실행시에 힙메모리에 dynamic allocate 한다 


  return 0;
}





/*
c++ style 메모리 할당을 사용해도 delete를 빼먹으면 memmory leak 이 발생
그래서 위와 같이 safer c++ 메모리 할당 방식을 쓰는거임
바로 스마트 포인터와 벡터

*/