#include <iostream>
#include <string>
#include <map>
using namespace std;


int main(int argc, char const *argv[])
{
  map<int, int> numsPairs;
  numsPairs.emplace(1,1);
  numsPairs.emplace(2,2);
  numsPairs.emplace(3,3);
  numsPairs.emplace(4,4);

  numsPairs.emplace(1,2); // 키값 중복으로 제거
  numsPairs[1] = 20; // (1,20) 으로 들어감
  cout << numsPairs[5]; // 없는 키 5를 넣으면 디폴트값 0으로 들어가기에 조심해야함 

  for(const auto & numPair: numsPairs)
  {
    cout << numPair.first << " " << numPair.second << endl;
  }

  map<string, int> nameList;            // 키, 밸류 데이터타입 다르게 지정
  nameList.emplace("oil0", 1);          // 키 값이 스트링이면 알파벳 순서로 정렬
  nameList.emplace("aoil1", 2);
  nameList.emplace("coil2", 3);
  nameList.emplace("boil3", 4);

  for (const auto & name : nameList)
  {
      cout << name.first << " " << name.second << endl;
  }

  return 0;
}







/*
map은 set의 binary search tree에 키:밸류 값이 들어간 것으로 보면 됨
키 값으로 정렬 

레드블랙트리 중의 (balanced) binary search tree로 설명
find, insert, remove 모두 O(n) 시간복잡도
여기서 insert, remove는 tree-rebuild, re-coloring 하는 과정 있음
*/