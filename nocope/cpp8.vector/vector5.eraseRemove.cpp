#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;


class Cat
{
    public:
        Cat(string name, int age):mName{move(name)}, mAge{age}{};
        void speak() const
        {
            cout << mName << " " << mAge << endl;
        }
        int age() const
        {
            return mAge;
        }
    private:
        string mName;
        int mAge;
};


int main()
{
    vector<int> nums{0,1,0,1,0,1,0};
    // nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());  이것이 아래와 동일 

    auto itr = remove(nums.begin(), nums.end(), 0);     // 1 1 1 1 0 1 0  이 값을 리턴함, 이때 인덱스 3의 값도 리턴(거기서부터 지워야함 )
    for(int num: nums)
    {
        cout << num << " ";
    }
    cout << endl;
    nums.erase(itr, nums.end());                // 리턴된 인덱스 3부터 지워주는 것 
    for(int num: nums)
    {
        cout << num << " ";
    }
    cout << endl;


    vector<Cat> cats;
    cats.reserve(4);

    cats.emplace_back("cat0", 0);  
    cats.emplace_back("cat1", 1);
    cats.emplace_back("cat2", 2);
    cats.emplace_back("cat3", 3);

    cats.erase(remove_if(cats.begin(), cats.end(), [](const Cat & cat){
        if (cat.age()%2 == 0)
        {
            return true;
        }
        return false;
    }), cats.end());
    for(const Cat & cat: cats)
    {
        cat.speak();
    }
}





/*
remove, erase는 인터뷰에서도 종종 나오는 질문

[0,1,0,1,0,1,0] 여기서 1만을 앞에 이동시켜서  -> [1,1,1,   1,0,1,0]  이렇게 만듬 
시간복잡도 O(n)
*/