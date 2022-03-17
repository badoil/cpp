#include <array>
#include <cstdint>
#include <iostream>

int main()
{

  uint64_t ui8;
  float f4;
  std::array<uint8_t, 5> uia5;

  uint64_t * ui64ptr = &ui8;       // ui8 의 포인터, 메모리 주소
  std::cout << sizeof(ui64ptr) << std::endl;        // 8
  std::cout << (uint64_t)ui64ptr << std::endl;      // 140732848894992


  return 0;
}


/*
fixed integer type

위에서 사이즈는 8이 나오고 
메모리 주소는 140732848894992
격자에서 메모리 주소가 140732848894992인 8칸 크기를 차지한다는 뜻 
이것은 &ui8의 메모리 주소, 즉 포인터 정보 이기 때문에 이 주소를 따라가면 ui8의 값이 있음

그런데 포인터의 경우 64비트 컴퓨터 환경에서 타입과 상관없이 항상 8bytes 의 사이즈를 갖는다

*/