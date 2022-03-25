#include <iostream>
#include <functional>
#include <vector>
using namespace std;

class FunctionObj
{
  public:
    void operator() (int i)
    {
      cout << "functionObj " << i << endl;
    }
};

void freeFunction(int i)
{
  cout << "freeFunction " << i << endl;
}

void runFunction(int i, void(* fnPtr)(int i))     // 넘어온 정수와 함수를 실행시키는 함수
{
  (*fnPtr)(i);
}

void runFunction2(int i, const function<void(int)>& fn)     // std function template,  사용해서 함수, 오브젝트, 람다함수  레퍼런스 넘기기
{
  fn(i);
}

void runFunctions(vector<function<void(int)>> functions)
{
  int i=0;
  for(const auto & fn: functions)
  {
    fn(++i);
  }
}

int main ()
{
  freeFunction(10);
  void (* fnPtr)(int);      // 함수포인터를 만들고
  fnPtr = freeFunction;     // 함수포인터에 함수를 할당
  (*fnPtr)(10);             // 함수포인터를 defeferencing 해주고 인자 값 넣어줌
  runFunction2(10, fnPtr);

  FunctionObj functionObj;
  functionObj(10);
  runFunction2(10, functionObj);

  auto lambdaFn = [](int i)
  {
    cout << "lambdaFn " << i << endl;
  };
  lambdaFn(10);
  runFunction2(10, lambdaFn);

  vector<function<void(int)>> functions;
  functions.emplace_back(freeFunction);
  functions.emplace_back(functionObj);
  functions.emplace_back(lambdaFn);
  runFunctions(functions);

  return 0;
}





/*
위의 freeFunction 함수, FunctionObj 객체, lambdaFn 함수
중에 freeFunction은 호출만 할 수 있지만 변수처럼 가리키는 것은 불가능
함수포인터를 사용해야함


*/