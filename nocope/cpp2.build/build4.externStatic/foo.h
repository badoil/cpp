#pragma once

extern "C" int foo2(double a);
extern "C" double bar2(int a);

// 아래와 동일

// extern "C"
// {
//   int foofoo(double a);
//   int barbar(int a);
// }


/*
함수 오버로딩 때문에 c++ 에서는 name mangling을 사용한다
그런데 c 언어와 호환할때 extern "C" 라는 키워드로 네임 맹글링 기능을 없앰
즉 c interface 를 가진 binary code를 제공할 때 이것이 필요함
왜냐하면 c는 함수 오버로딩 불가하기 때문임
네임 맹글링 안되고 그냥 함수명 그대로 오브젝트 파일에 생성

extern "C"
*/