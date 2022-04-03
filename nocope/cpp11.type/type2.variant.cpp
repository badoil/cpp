#include <iostream>
#include <variant>
#include <string>
#include <vector>
using namespace std;

struct S
{
    int i;
    double d;
    float f;
};

union U
{
    int i;
    double d;
    float f;
};

int main()
{
    variant<int, double, float> v;
    v=10.0;
    if (auto pVal = get_if<double>(&v))
    {
        cout << *pVal << endl;
    }
    else{
        cout << "not double" << endl;
    }

    variant<string, vector<int>> sv;
    sv = string("abc");
    cout << get<string>(sv) << endl;

    sv = vector{1,2,3};                 // destructor, constructor 호출할 필요 없이 자동으로 할당 

    return 0;  
}


/*
variant는 union 을 대체함
내부적으로 타입트랙킹 정보가 있지만 그 정도 무시할만하면 유니언보다 추천

*/