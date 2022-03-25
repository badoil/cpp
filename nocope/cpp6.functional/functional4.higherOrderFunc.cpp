#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


int main ()
{
  vector<int> nums = {1,2,3,4,5};
  auto odds = [](int n)
  {
    return n % 2 == 1; 
  };
  
  // nums.erase(remove_if(nums.begin(), nums.end(), odds), nums.end()); // 홀수 제외

  sort(nums.begin(), nums.end(), [](int a, int b)
  {
    return a<b;
  });

  
  int sum = reduce(nums.begin(), nums.end(), 0, [](int a, int b)
  {
    return a+b;
  });
  cout << sum << endl;
  
  
  for(int num: nums)
  {
    cout << num << endl;
  }
  return 0;
}



/*
higher order function
함수를 argument로 받거나 결과로 내놓는 함수
예를 들어 for_each(nums.begin(), nums.end(), plus10)는 plus10이라는 함수도 인수로 들어갔기에 고차함수


*/