#include <algorithm>
#include <iostream>
#include <list>
 
int main()
{
    // Create a list containing integers
    std::list<int> l = { 7, 5, 16, 8 };
 
    // Add an integer to the front of the list
    l.emplace_front(25);
    // Add an integer to the back of the list
    l.emplace_back(13);
 
    // Insert an integer before 16 by searching
    auto it = std::find(l.begin(), l.end(), 16);
    if (it != l.end()) {
        l.insert(it, 42);
    }
 
    // Print out the list
    std::cout << "l = { ";
    for (int n : l) {
        std::cout << n << ", ";
    }
    std::cout << "};\n";
}



/*
list는 doubly linked list 로 구현
스택에 생기는 리스트 객체에 first pointer, last pointer, size 정보가 들어가고
이 두 포인터가 각각 힙에 있는 링크드 리스트의 처음과 끝을 가리킴
그래서 find 는 O(n)
찾은 후에 insert, delete 는 앞뒤로 리스트를 연결해주면 끝이기에 O(1)

forward_list는 singly linked list로 구현


vector vs list


         find       random access       insert/delete       insert(back)/delete(back)
vector   O(n)           O(1)                O(n)                        O(1)

list     O(n)           O(n)                O(1)                        O(1)


벡터와 리스트가 find에서 O(n)으로 같지만 실제로 메모리 구조상 벡터가 더 빠르다
벡터의 메모리 구조는 연속된 데이터 공간이라 하나의 캐시에 연속된 배열들이 들어와서 빠르게 검색 가능하지만
리스트는 메모리상에 불연속적으로 원소들이 흩어져있고 포인터로 연결되어 있을뿐임
그래서 캐시의 단위가 하나의 원소이고, 다음 원소로 넘어갈때 캐시미스가 생기고 포인터가 디레퍼런싱도 해야함
그래서 느림
*/