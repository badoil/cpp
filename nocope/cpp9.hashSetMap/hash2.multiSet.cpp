#include <iostream>
#include <string>
#include <set>
using namespace std;

struct customFn           //     struct 구조체 내에서 정의한 이유: 직관적이기도 하고, 보통 function operator 를 일반적으로 struct내에 정의
{
    bool operator()(const int lhs, const int rhs) const
    {
        return (lhs%10) < (rhs%10);           // 나머지 값을 tree에 담는것이 아니라, 숫자 그대로 트리에 담습니다. 나머지는 비교를 위해서만 연산합니다
    }
};

class Cat
{
    public:
        Cat(string name, int age): mName{move(name)}, mAge{age}{};
        void speak() const
        {
            cout << mName << mAge << endl;
        }
        const string & name()
        {
            return mName;
        } 
        int age() const
        {
            return mAge;
        }
    private:
        string mName;
        int mAge;
};

bool operator< (const Cat& lhs, const Cat& rhs)
{
    return lhs.age() < rhs.age();
}


int main(int argc, char const *argv[])
{
  set<int, customFn> nums{1,2,3,4,5};       // customFn을 
  nums.emplace(11); // 1
  nums.emplace(21); // 1

  for(int const num: nums)
  {
    cout << num << " ";
  }
  cout << endl;

  set<Cat> cats;                    // 오퍼레이터 "<" 정의해줘야 셋의 객체에 대한 정렬기준이 생겨서 에러가 안생김 
  cats.emplace("kitty", 1);
  cats.emplace("navi", 2);

  for (const auto & cat: cats)
  {
      cat.speak();
  }

  multiset<int> multiNums{1,2,3,3,3,4,5};
  for (const auto & num : multiNums)
  {
      cout << num << " ";
  }
  cout << endl;

  return 0;
}


/*
1, 11, 21 을 customFn 에 의해서 같은 값으로 계산하고 중복값이라서
셋에 들어가지 않음 

셋과 멀티셋 모두 오퍼레이터 정의를 통해서 정렬이 된 순서로 이터레이션 가능 
*/