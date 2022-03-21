#include <dlfcn.h>
#include <iostream>
using namespace std;

int main()
{
  void * handle = dlopen("./libfoo.so", RTLD_LAZY);   // 라이브러리 오픈, 실행과정, run time에서 라이브러리 지연 로딩
  if(!handle)
  {
    cout << "no library" << endl;
    return 1;
  }

  void (*fooPtr)();   // fooPtr 라는 함수 포인터 만들어줌
  fooPtr = (void(*)())dlsym(handle, "_Z3foov");    // 심볼로딩, "_Z3foov" 이놈이 라이브러리의 심볼임, 라이브러리에서 직접 가져오기 때문에  함수 선언 필요 없음
  const char* dlsym_error = dlerror();
  if (dlsym_error)
  {
    cout << "error" << endl;
    return 1;
  }

  (*fooPtr)();      // 런타임에서 함수 실행
  dlclose(handle);
  return 0;
}



/*
- run time에 바인딩 방법
g++ mainRun.cpp -ldl   : dl 쓰는 코드  때문에 옵션 걸어주기
그 다음에 생성된 실행파일 실행해보면 libfoo.so 라이브러리에서 foo 함수 호출함

라이브러리 지연 로딩하고
라이브러리에서 직접 가져오기 때문에  함수 선언 필요 없음

*/