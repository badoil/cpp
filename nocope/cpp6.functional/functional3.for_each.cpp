#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main ()
{
  vector<int> nums = {1,2,3,4,5};
  auto plus10 = [](int &n)
  {
    return n += 10;
  };
  
  for_each(nums.begin(), nums.end(), plus10);

  // 아래왁 같이 이름없는 함수 그대로 넣을 수도 있음
  for_each(nums.begin(), nums.end(), [](int &n)  
  {
    return n += 10;
  });
  
  for(int num: nums)
  {
    cout << num << endl;
  }
  return 0;
}