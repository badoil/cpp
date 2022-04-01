#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


int main(int argc, char const *argv[])
{
  unordered_map<int, string> numsPairs;
  numsPairs.emplace(1,"cat1");
  numsPairs.emplace(2,"cat2");
  numsPairs.emplace(3,"cat3");
  numsPairs.emplace(4,"cat4");

  for(const auto& cat: numsPairs)
  {
      cout << cat.first << " " << cat.second << endl;
  }
  cout << endl;

  return 0;
}


/*
set, map: tree 구조로 정렬되어 있음 O(log(n)), 정렬되어야 하기 때문에 커스텀 클래스 쓸대, comparison operator "<" 정의해야함

unordered_set, unordered_map: 해시구조로 정렬 안되어 있음 O(1), 해시 사용하기 위해서 해시펑션과 "==" 오퍼레이터 정의해야함
리해싱 고려해서 reserve 써야함

모두 key에 대해서 정렬과 해시함수가 적용되고 중복을 허용하지 않음
멀티를 쓰면 중복 허용 
*/