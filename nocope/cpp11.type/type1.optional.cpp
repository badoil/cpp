#include <iostream>
#include <optional>
using namespace std;

optional<int> devide(int a, int b)      // 리턴타입이 옵셔널
{
    if (b==0)
    {
        return nullopt;                 // 리턴이 null 값
    }
    else{
        return a/b;
    }
}

class Cat
{
    private:
        int n;

    public:
        void speak()
        {
            cout << "meow " << n << endl;
        }
};


int main ()
{
    int a;
    int b;
    cin >> a;
    cin >> b;

    auto result = devide(a, b);
    if (result)
    {
        cout << result.value() << endl;
    }
    else
    {
        cout << "no value" << endl;
    }

    optional<Cat> cat;      // 아직 고양이 객체가 만들어지지 않음,
    if (!cat)
    {
        cout << "cat is not yet" << endl;
    }
    else
    {
        cout << "cat is ready" << endl;
    }

    return 0;
}


/*
optional은 데이터타입에 추가로 그 데이터의 valid 여부 적힌 메모리 공간이 필요할 뿐
성능 저하 걱정이 없음

*/
