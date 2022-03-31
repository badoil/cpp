#include <array>
#include <vector>
using namespace std;

void arrayFn()
{
    array<int, 100> nums;         // 어레이는 컴파일때 사이즈 결정되므로 fixed size
}

void vectorFn()
{
    vector<int> nums(100);

    nums.resize(1000000); // 벡테는 런타임에 사이즈가 결정되므로 이러한 리사이징이 가능  flexible size
}

int main()
{
    arrayFn();
    vectorFn();

    return 0;
}








/*
벡터와 어레이의 차이점
벡터는 힙에 연속된 공간에 allocation 되고, 어레이는 스택의 연속된 공간에 allocation 
stack : complile 때, stack-frame 안에서 메모리 할당, 메모리 할당시간 빠름
heap : run-time 때   , 힙에서 메모리 할당시간 소요


어레이는 arrayFn() 스택프레임 안에 연속된 공간으로 할당되고
벡터는 vectorFn() 스택프레임 안에 포인터와 사이즈 캐파시티가 생기고, 힙에 연속된 공간의 배열이 할당됨. 이때 포인터가 힙에 있는 이놈을 가리킴

그런데 둘 다 모두 sequential memory,  random access 지원한다는 것은 공통점 
*/