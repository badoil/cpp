#include <iostream>
#include <variant>
using namespace std;

int main()
{
  int i;                      // warning: variable 'i' is uninitialized when used here [-Wuninitialized]
  cout << "hi" <<  i << endl;

  return 0;
}






/*
main.cpp  cat.h   cat.cpp  요래 세 파일이 있다
메인파일에서 고양이 파일 가져와서 이런저런 연산을 하는 프로그램

빌드할때 가장 먼저 전처리기(pre-processor)가 #includ, #define 같은거 찾아서 치환
전처리기가 치환해서 하나의 translation-unit을 만듬
그후 컴파일러가 이 유닛들을 오브젝트 파일로 만듬, 이 오브젝트 파일에는 머신코드와 전역변수의 초기값이 데이터 형식으로 들어감
링커는 필요한 오브젝트 파일들을 모아서 실행파일 만들어냄, 실행파일은 코드, 데이터 그리고 실행시키기위한 추가 정보들이 있음
이 실행파일이 실행되면 os 안에서 프로세스 메모리에 올라가고 실행
이 모든 과정을 빌드 프로세스라 칭하고 컴파일러가 해줌 

위의 파일에 g++ build1.intro.cpp -o hi -Wall
-Wall 이라는 옵션을 주게 되면 문제가 실행시 문제가 될 만한 요소를 컴파일때 경고로 알랴줌
warning: variable 'i' is uninitialized when used here [-Wuninitialized]

g++ build1.intro.cpp -o hi -Wall -Werror
-Werror 옵션은 warning을 에러로 인식하게 만들어서 아예 컴파일이 안되게 함
-g 디버그 정보
-v 컴파일 과정 정보
-O optimization 레벨 -O0, -O2를 많이 씀
-march : machine architect  현재 컴퓨터의 cpu에 맞게 최적화  -march = CPU-TYPE    ex) -march=native
최적화는 이러한 컴파일레션 옵션에 의지하기보다 직접 프로파일을 찍으면서 해야함

g++ build1.intro.cpp -o hi -Wall -Werror -std=c++17
-std=c++17 옵션은 c++ 버전에 따른 새로운 피쳐를 반영할때 옵션 
*/