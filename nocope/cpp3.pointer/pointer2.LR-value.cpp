#include <string>
using namespace std;

void storeByValue(string s)        // "abc"가 힙에 복사되고, 함수 내부에서 b에 할당되므로 한번더 복사됨, 총 두번 복사되고 스택에 쌓임
{
  string b = s;
}

void storeByLValue(string & s)     // 이때 레퍼런스로 파라미터 넘기기에 복사는 안일어남, 하지만 함수 내부에서 힙의 "abc"복사되고 b가 이를 가리킴
{
  string b = s;
}

void storeByRValue(string && s)    // 그런데 함수가 콜 되면서 스택프레임이 올라가고 거기에 알밸류 레퍼런스(&& s)가 들어있음
{                                  // && s 가 힙의 "abc"를 가리키게 됨
  // string b = s;                 // 이때에는 b가 스택에 쌓이고 힙에 "abc"가 복사
  string b = move(s);              // move를 하게되면 알밸류로 바뀌고 복사는 일어나지 않고 b도 기존의 "abc"를 가리키게 됨, 복사가 결국 한번도 안일어남
}

int main()
{
  string a = "abc";     // 스택 a 쌓이고, 이것이 힙에 "abc" 가리킴
  storeByValue(a);      // "abc"가 힙에 복사되고, 함수 내부에서 b에 할당되므로 한번더 복사됨, 총 두번 복사되고 스택에 쌓임
  storeByLValue(a);     // 이때 레퍼런스로 파라미터 넘기기에 복사는 안일어남, 하지만 함수 내부에서 힙의 "abc"복사되고 b가 이를 가리킴
  
  storeByRValue("abc"); // std::move(a) 알밸류만 들어가야하기에
  // 이놈은 힙에 "abc"가 시작부터 있지만 스택에는 아직 이를 가리키는 게 없음.
  // 그런데 함수가 콜 되면서 스택프레임이 올라가고 거기에 알밸류 레퍼런스(&& s)가 들어있음 
  // && s 가 힙의 "abc"를 가리키게 됨
}




/*
int a = 0, 이때 'a' 가 l-value, 0이 r-value
int b = a, 둘 다 l-value
l-value는 다시 부를 수 있는 값
r-value는 다시 부르지 않는 값


*/