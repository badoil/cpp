#include <iostream>

int ga = 0;       // static(global) 메모리

int main()
{
  // int * ip = new int[250];   // 아래의 설명 참고


  int sa = 0;
  int sb = 1;

  std::cout << "&sa:  " << (long)&sa << std::endl;
  std::cout << "&sb:  " << (long)&sb << std::endl;

  int * hap = new int;
  int * hbp = new int;

  std::cout << "&hap: " << (long)&hap << std::endl;
  std::cout << "&hbp: " << (long)&hbp << std::endl;

  std::cout << "&ha:  " << (long)hap << std::endl;
  std::cout << "&hb:  " << (long)hbp << std::endl;

  delete hap;
  delete hbp;

  std::cout << "&ga:  " << (long)ga << std::endl;

 
  return 0;

}




/*
리눅스에서 보편적으로 쓰이는 메모리릭 관리 툴은 valgrind
메모리릭뿐만 아니라 메모리 관련된 바이올레이션들 체크

g++ -g mem6.memoryLeak.cpp
valgrind --leak-check=full ./a.out
이러면 파일의 어느 위치에서 메모리 릭이 일어나는지 알려줌

위 코드의 출력 결과
&sa:  140732734297128
&sb:  140732734297124
&hap: 140732734297112
&hbp: 140732734297104

&ha: 140280288271296
&hb: 140280288271312
&ga:  0

프로세스메모리로 생각하면 스택프레임은 위에서 아래로 쌓이고, 힙메모리는 밑에서 위로 쌓임
스택프레임의 순서와 힙메모리-스택메모리 간격은 컴파일러마다 다름
스택메모리와 힙메모리의 자리수가 다른것을 보면 그들 사이에 큰 공간이 있음을 의미 
힙메모리도 프로세스 메모리안에서 할당을 받음
여기서 스택 메모리 간에는 차이가 별로 없는 힙메모리 &ha(4바이트), &hb(4바이트) 이 둘 사이의 차는 16임
힙메모리는 메모리 얼로케이터 마음임

static(global) 메모리는 힙보다 더 아래에 있음
프로세스 실행과 동시에 할당
*/