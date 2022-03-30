#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Cat
{
  public:
    Cat(string name, int age): mName{move(name)}, mAge{age}{}
    void speak()
    {
      cout << "meow " << mName << mAge << endl;
    }
  private:
    string mName;
    int mAge;
};

int main()
{
  vector<int> nums(10000, 1);
  nums.emplace_back(2);         // insert at end, O(1)
  nums.pop_back();              // remove at end, O(1)

  nums.emplace(nums.begin(), 3);  // O(n)   처음 자리에 3을 넣어서, 다음 수들이 모두 한칸씩 밀려남
  nums.erase(nums.begin());       // O(n)   처음 자리가 지워지고, 다음 수들이 모두 한칸씩 땡겨짐

  vector<Cat> cats;
  // cats.emplace_back(Cat{"cat0", 0})  // 요래 객체로 넘기면 메모리상에 임시 객체를 만들고 이 임시객체가 새로운 배열값을 가리키다가 move를 통해 이 임시객체가 백터의 마지막 공간으로 옮겨지게 됨
  cats.emplace_back("cat0", 0);     // 객체를 만들어서 넘기는게 아니라 바로 넘김, c++17 부터 최적화됨
  cats.emplace_back("cat1", 1);
  cats.emplace_back("cat2", 2);

  Cat navi{"navi", 2};
  cats.emplace_back(move(navi)); // R-value 로 넘겨야 카피가 안일어남

  for (auto& cat: cats)
  {
    cat.speak();
  }

  return 0;
}



/*
O(n) 걸리는 애들은 사용하지 말것


cats.emplace_back(Cat{"cat0", 0})  // 요래 객체로 넘기면 메모리상에 임시 객체를 만들고 이 임시객체가 새로운 배열값을 가리키다가 move를 통해 이 임시객체가 백터의 마지막 공간으로 옮겨지게 됨
이를 없애기 위해 객체를 만들어서 넘기는게 아니라 바로 넘김, c++17 부터 최적화됨

이렇게 할 수 이는게 cats.push_bck() 과 cats.emplace_back()의 차이
*/