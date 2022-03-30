#include <iostream>
#include <vector>
using namespace std;


int main()
{
  int * intPtr = new int[5];  // dynamic size arrays는 그냥 만들 수 있음
  for(int i=0; i<5; i++)
  {
    intPtr[i] = i;
  }
  delete[] intPtr;

  vector<int> nums{0,1,2,3,4};
  nums.emplace_back(5);

  for (auto itr = nums.begin(); itr != nums.end(); itr++)
  {
    cout << (*itr) << endl;
  }

  for (const int & num: nums)     // 이게 위에것 보다 좋음, 윗부분에 쓰여잇는 begin, end로 비교가 되는 코드와 같음을 보이기 위해서 ref로 for loop을 돌림
  {                               // 실제 코드에서는 int,float과 같은 primitive type들은 굳이 reference를 사용할 필요는 없음
    cout << num << endl;          // 하지만 그 size가 큰 object들은 value복사가 일어나기때문에 reference로 변수를 잡아야 함
  }

  return 0;
}





/*
cpp에서 가장 많이 쓰는 컨테이너 타입
vector is a sequence container that encapsulates dynamic size arrays.

dynamic size arrays는 그냥 만들 수 있음. 그런데 그것은 관리의 어려움이 있기때문에
이를 관리하기 위한 container를 제공하는데 이것이 벡터
벡터는 스택 위에 벡터 객체가 생성되고 힙 위에 생성되는 연속적인 메모리 공간을 가리킨다
*/