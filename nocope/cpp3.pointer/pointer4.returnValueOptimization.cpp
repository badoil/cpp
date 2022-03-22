#include <string>
using namespace std;

string getString()
{
  string s = "nocode";
  return s;
}

int main()
{
  string a = getString();
  return 0;
}






/*
RVO: return value optimization
메인 함수가 실행되면서 아직 가리키는것이 없는 a가 스택에 쌓이고 
함수 콜을 하면서 로컬변수 s가 스택에 올라가고 이것이 "nocode"를 가리킴
이때 리턴할때 카피가 일어나며 "nocode"가 하나더 복사되면서 a가 이를 가리킴    ->  이거 사실 잘못된 설명임, 리턴할때 카피는 안일어남, 밑에서 설명
이후 s가 포함된 스택프레임 해제되고 처음 힙에 있는 "nocode"도 해제
복사된 "nocode"와 이를 가리키는 a가 남음

여기서 "nocode" 복사도 일어나지 않게 하기 위해 move(s)해주려 할 수 있는데
이는 불필요함
RVO 때문임

실제 일어아는 일은 다음과 같음
메인 함수가 실행되면서 아직 가리키는것이 없는 a가 스택에 쌓이고
함수 콜을 하면서 스택프레임이 올라가는데, 이 속에는 로컬변수, 매개변수, 리턴밸류 주소가 들어감
여기서 컴파일러는 리턴밸류 주소가 a로 갈것을 미리 알고 a를 가리키고 있음
실제 리턴값은 힙에 있는 "nocode"이기 때문에 
a가 바로 이 "nocode"를 가리키게됨
이때 로컬스트링 s는 처음부터 존재하지도 않음
카피도 없고 소유권의 이동조차 불필요, move(s) 필요없음
즉 리턴할때 카피가 일어나지 않음

이에 대해 더 자세한 정보는
"cppreference copy elistion" 구글링 

*/