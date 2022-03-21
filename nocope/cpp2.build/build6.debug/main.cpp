#include <iostream>
#include <vector>
using namespace std;

int add(vector<int>& vIn)
{
  for(int & el : vIn)
  {
    ++el;
  }
  return 0;
}

int sub(vector<int>& vIn)
{
  for(int & el : vIn)
  {
    --el;
  }
  return 1;
}

int main()
{
  vector<int> v{1, 2, 3, 4, 5};
  int a = 10;
  if (a%2 == 0)
  {
    a = add(v);
  }
  else
  {
    a = sub(v);
  }
  cout << a << endl;
  return 0;
}



/*
-g 옵션은 디버그 옵션인데, 이때 디버그 정보가 추가로 들어가게됨
어디에 들어가냐면, 
바이너리 코드 - cpp 코드 사이를 연결해주는 정보들이 있는데 여기에 들어감

여기서는 GDB라는 툴 이나 VSC 자체 툴을 이용하면 아래와 같은 것들 확인 가능
1. variable
2. break point
3. call stack(back trace)

*/