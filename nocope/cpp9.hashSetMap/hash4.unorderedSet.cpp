#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

int main ()
{
    unordered_set<string> unordSet;
    unordSet.emplace("abc");
    unordSet.emplace("def");
    unordSet.emplace("ghi");
    unordSet.emplace("jkl");

    for(const auto & str: unordSet)
    {
        cout << str << " ";
    }
    return 0;
}







/*
해시셋 사용하는 언오더드셋

Unordered set is an associative container that contains a set of unique objects of type Key. 
Search, insertion, and removal have average constant-time complexity.
Internally, the elements are not sorted in any particular order, but organized into buckets. 
Which bucket an element is placed into depends entirely on the hash of its value


*/