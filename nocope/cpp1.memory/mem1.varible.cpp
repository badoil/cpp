#include <iostream>

int main()
{
  int a = 0;
  int b = 3;
  int c = a + b;
  double d = 2.5;

  std::cout << "a:" << (long)&a << std::endl;
  std::cout << "b:" << (long)&a << std::endl;
  std::cout << "c:" << (long)&a << std::endl;
  std::cout << "d:" << (long)&a << std::endl;
  return 0;
}

// 변수가 stack 처럼 쌓임
// 메모리는 스택의 탑 위치에서 몇번째에 어떤 값이 있는지 기억하지 'a' 이런거를 기억하지 않음
// 그러나 실제로는 스택이 아니라 2차원 격자를 생각하면 조음. 그 변수의 값 사이즈 만큼 격자를 차지하고 있음
// 스택으로 볼거면, 메모리 위에서 아래로 쌓이는 구조로 봐야함
// 그래서 주소 번호가 큰수 -> 작은수 로 memory allocate가 이루어짐
// memory allocation은 컴파일러마다 다른데, g++ / clang 같은 컴파일러는 그러함
// 그렇다고 처음 변수의 메모리 주소가 가장 끝단은 아닌데, 그 이유는 environment 라는 프로그램 정보가 스택에  미리 쌓여있음