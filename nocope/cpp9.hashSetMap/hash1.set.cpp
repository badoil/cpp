#include <iostream>
#include <set>
using namespace std;


int main(int argc, char const *argv[])
{
  set<int> nums{1,2,3,4,5};
  nums.emplace(3);
  nums.emplace(3);

  for(int const num: nums)
  {
    cout << num << " ";
  }

  return 0;
}



/*
std::set is an associative container that contains a sorted set of unique objects of type Key. 
Sorting is done using the key comparison function Compare. Search, removal, and insertion operations have logarithmic complexity. 
Sets are usually implemented as red-black trees.

레드블랙트리 중의 (balanced) binary search tree로 설명
find, insert, remove 모두 O(n) 시간복잡도
여기서 insert, remove는 tree-rebuild, re-coloring 하는 과정 있음

중복제거, 내부정렬을 계속 유지함
여기서 배운 set은 unordered-set 인 것임


*/