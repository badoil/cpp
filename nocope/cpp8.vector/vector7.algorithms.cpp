#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
struct Employee
{
    int age;
    std::string name;  // Does not participate in comparisons
};
 
bool operator<(const Employee & lhs, const Employee & rhs)
{
    return lhs.age < rhs.age;
}
 
int main()
{
    std::vector<Employee> v =
    { 
        {108, "Zaphod"},
        {32, "Arthur"},
        {108, "Ford"},
    };  
 
    std::stable_sort(v.begin(), v.end());
 
    for (const Employee & e : v)
        std::cout << e.age << ", " << e.name << '\n';


    const vector<int> nums{0,3,5,2,7,4,9};
    const auto resultItr = find(nums.begin(), nums.end(), 2);
    // const auto end = nums.end();
    // cout << "nums.end: " << end << endl;

    if (resultItr != nums.end())
    {
        cout << "idx: " << distance(nums.begin(), resultItr) << endl;
    }
    else
    {
        cout << "not found element" << endl;
    }


    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
    int sum = std::accumulate(v.begin(), v.end(), 0);
 
    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());

     std::cout << "sum: " << sum << '\n'
              << "product: " << product << '\n';

    return 0;
}





/*
sort, find, min/max, reduce

1. sort
stable_sort : 정렬기준에 맞춰서 정렬하고, 그 외에는 변하지 않는것
    32, Arthur
    108, Zaphod
    108, Ford

2. find 위 코드 참고
3. reduce(accumulate)
    리턴값이 하나의 값인 경우 리듀스 알고리즘 사용    

*/