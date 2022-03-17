#include <array>
#include <cstdint>
#include <iostream>

int main()
{
  int a[10];
  std::array<int, 5> ia;

  std::cout << sizeof(a) << std::endl;
  std::cout << sizeof(ia) << std::endl;

  return 0;
}

 
/*
타입에 맞는 메모리 공간을 차지

1 bytes = 8 bits
sizeof(int) 는 4bytes, 격자로 생각하면 4칸 차지
그런데 다른 컴파일러에서 2bytes 인 경우도 있음

static_assert(sizeof(int) == 4, "int is 4bytes")  요놈을 써서 사이즈 체크 해줄 수 있음

아니면 fixed integer type 을 사용하면 됨
*/