#include "cat.h"

int main ()
{
  Cat kitty;
  kitty.speak();

  return 0;
}




/*
library

1. header only library
#include "header" 로 라이브러리 사용했으면 이거임

2. static library
라이브러리 파일(.lib 이나 .a 로 끝나는 라이브러 파일) 가지고 와서 빌드 프로세스에서 링크를 시키는 것 

링커가 오브젝트 파일들을 모아서 하나의 실행파일을 만들기 전에, 오브젝트 파일을 모아서 하나의 파일로 만들고
이 파일 이름을 libxxx.a 라고 하면 이것이 하나의 static library 가 됨
그후 링커가 이 라이브러리 파일에서 코드와 데이터를 가져와서 relocation, optimization 시켜서 실행 파일 만듬
결론적으로 스태틱 라이브러리는 오브젝트 파일을 모은 하나의 파일에 불과
그래서 링크해주는 빌드 프로세스와 크게 다르지 않음

static library 만드는 과정
g++ cat.cpp -c -O2 -Wall -Werror  : cat.cpp의 오브젝트 파일 만들기

ar -rs libcat.a cat.o   : 만들어진 cat.o 파일로 라이브러리 파일 만들기
이때 ar 은 archive를 만들때 사용하는 리눅스 명령어, r은 파일을 아카이브에 넣는 명령, s는 오브젝트 파일의 인덱스를 아카이브 파일에 써줌
결국 오브젝트 파일의 인덱스와 내용들을 하나의 아카이브 파일로 만드는것

g++ main.cpp -lcat : -l 라이브러리 찾는명령, 하지만 이러면 캣라이브러리 파일 못찾음
g++ main.cpp -L. -lcat : -L. 라이브러리르 찾기 위한 디렉토리를 알려주는 옵션, 현재 디렉토리에 라이브러리 파일 있음을 알리고 실행파일 생성


3. dynamic library
라이브러리 파일(.dll 이나 .so)
load time: 프로그램이 실행될때 로더가 프로세스를 실행시킬때 라이브러리를 가지고 와서 바인딩
run time: 프로세스가 실행과정 중간에 라이브러리를 가지고 와서 바인딩
*/