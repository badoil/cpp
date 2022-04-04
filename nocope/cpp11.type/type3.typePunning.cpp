#include <iostream>
#include <cstdint>
#include <bit>
#include <cstring>
using namespace std;

bool isNeg(float x)
{
    unsigned int tmp;
    memcpy(&tmp, &x, sizeof(x));


    return tmp & 0x80000000;

    // return bit_cast<uint32_t>(x) & 0x80000000;       // c++20 부터 memcpy 안쓰고 비트캐스트로 가능
}


int main(int argc, const char *argv[])
{
    cout << isNeg(-0.1f) << endl;
    cout << isNeg(0.1f) << endl;
    return 0;
}

/*
어떤 타입을 나타내는 메모리 공간을 다른 타입으로 읽어서 조작한다
위의 예제는 float으로 써놓고 unsigned int 로 읽음

*/