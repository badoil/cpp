#include <iostream>
#include <deque>
 
int main()
{
    // Create a deque containing integers
    std::deque<int> d = {7, 5, 16, 8};
 
    // Add an integer to the beginning and end of the deque
    d.push_front(13);
    d.push_back(25);
    d.emplace_front(12);    // emplace_front, emplace_back 이 권장
    d.emplace_back(3);
 
    // Iterate and print values of deque
    for(int n : d) {
        std::cout << n << ' ';
    }
}





/*
deque
double ended queue

두번의 포인터 디레퍼런싱이 필요
d[5] 라고 하면, 데이터 덩어리들을 가리키는 포인터들을 가리키는 것임.
d[5]  -> 데이터 덩어리들을 가리키는 포인터들 -> 데어터 덩러리들

이 데이터 덩어리들이 벡터와 다르게 용량이 모자르면 이동하는 것이 아니라 다른 덩어리에
이어서 데이터를 저장
따라서 캐시 미스가 발생할 수 있는 단점 있음

실무에서 거의 안씀

*/