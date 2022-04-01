#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;


class Cat
{
    public:
        Cat(string name, int age): mName{move(name)}, mAge{age} {};
        void speak() const
        {
            cout << "meow " << mName << mAge << endl;
        }
        int age() const
        {
            return mAge;
        }
        const string& name() const
        {
            return mName;
        }
    private:
        string mName;
        int mAge;
};

// struct CatHash
// {
//     std::size_t operator()(Cat const& c) const noexcept
//     {
//         std::size_t h1 = std::hash<int>{}(c.age());
//         std::size_t h2 = std::hash<std::string>{}(c.name());
//         return h1 ^ h2; // or use boost::hash_combine
//     }
// };

// custom specialization of std::hash can be injected in namespace std
template<>
struct std::hash<Cat>       // namespace std 로 해시를 정의하면 CatHash 주입 안해도 됨
{
    std::size_t operator()(Cat const& c) const noexcept
    {
        std::size_t h1 = std::hash<int>{}(c.age());
        std::size_t h2 = std::hash<std::string>{}(c.name());
        return h1 ^ h2; // or use boost::hash_combine
    }
};


bool operator==(const Cat & lhs, const Cat & rhs)                   // 한 버킷안에 두 객체가 다르다는 것을 이 "==" 오퍼레이터 덕에 알 수 있음 
{
    return (lhs.age() == rhs.age()) && (lhs.name() == rhs.name());
}


int main()
{
    unordered_set<Cat> cats;       // unordered_set은 해시가 필요하기 때문에 커스텀 클래스를 쓸 경우 CatHash 정의해서 넣어주고, std로 정의했으면 불필요
    Cat kitty{"kitty", 1};
    Cat navi{"navi", 2};
    
    cats.emplace(kitty);
    cats.emplace(navi);

    for (const auto & cat: cats)
    {
        cat.speak();
    }

    return 0;
}


/*
해시 정의하는 두 가지 방법": struct, std

*/