
void foo();
int main()
{
  foo();
  return 0;
}


/*
library

1. header only library
#include "header" 로 라이브러리 사용했으면 이거임

2. static library
라이브러리 파일(.lib 이나 .a 로 끝나는 라이브러 파일) 가지고 와서 빌드 프로세스에서 링크를 시키는 것 

3. dynamic library
라이브러리 파일(.dll 이나 .so)
load time: 프로그램이 실행될때 로더가 프로세스를 실행시킬때 라이브러리를 가지고 와서 바인딩
run time: 프로세스가 실행과정 중간에 라이브러리를 가지고 와서 바인딩

- load time에 바인딩 방법
오브젝트 파일을 만들때 -fPIC 옵션을 걸고 오브젝트 파일을 만들어야함. 그리고 libxxx.so 라이브러리를 만들면 됨. 다이내믹 라이브러리 생성 옵션임 position independence code
후에 링커는 이들로부터 심볼 정보만 실행 파일에 넣어주고, 로드할때 이 libxxx.so 를 바인딩 함
g++ foo.cpp -c   : 오브젝트 파일 만들고
g++ -shared foo.o -o libfoo.so  : 이 오브젝트 파일을 libfoo.so 라이브러리 파일로 만듬
이때 에러가 뜨는데 libfoo.so 라이브러 내의 주소들이 절대경로이기 때문임. 이 라이브러리가 여러 어플리케이션에서 
사용되기 위해서는 상대경로로 설정해주어야 하는데 이것이 -fPIC 옵션임

g++ foo.cpp -fPIC -c : 상대경로 오브젝트 파일 만들고
g++ -shared foo.o -o libfoo.so

g++ main.cpp -c
g++ main.o -L. -lfoo -Wl,-rpath=.    : 셰어드 라이브러리가 현재 디렉토리에 있음을 알리고 실행파일 생성
바로 이때 링크를 할때가 로드타임임.
아무래도 로드타임때 문제를 발견할 수 있기때문에 런타임 다이나믹 라이브러리보다 
로드타임 다이나믹 라이브러리가 선호됨

전체적으로 봤을때 스태틱이 다이나믹보다 선호됨
컴퓨터 성능이 좋아졌기 때문에 빌드할때 라이브러리 바인딩 해도 문제 없음
다만 실행파일을 빌드해놓고 라이브러리만 바꿔야하는 상황이라면 다이나믹 라이브러리만
수정해주면 되기에 이럴때 장점임
 

*/