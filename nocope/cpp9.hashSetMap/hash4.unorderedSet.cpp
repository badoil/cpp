#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

int main ()
{
    unordered_set<string> unordSet;
    unordSet.reserve(100);      // 메모리 공간 미리 확보

    unordSet.emplace("abc");
    unordSet.emplace("def");
    unordSet.emplace("ghi");
    unordSet.emplace("jkl");

    cout << "abc: " << hash<string>{}("abc") << "abc bucket: " << unordSet.bucket("abc") << endl;
    cout << "def: " << hash<string>{}("def") << "def bucket: " << unordSet.bucket("def") << endl;
    cout << "ghi: " << hash<string>{}("ghi") << "ghi bucket: " << unordSet.bucket("ghi") << endl;
    cout << "jkl: " << hash<string>{}("jkl") << "jkl bucket: " << unordSet.bucket("jkl") << endl;
    cout << unordSet.bucket_count() << endl;

    for(const auto & str: unordSet)
    {
        cout << str << " ";
    }
    cout << endl;

    unordSet.find("abc");   // O(1)
    unordSet.erase("abc");   // O(1)

    return 0;
}







/*
해시셋 사용하는 언오더드셋

Unordered set is an associative container that contains a set of unique objects of type Key. 
Search, insertion, and removal have average constant-time complexity.
Internally, the elements are not sorted in any particular order, but organized into buckets. 
Which bucket an element is placed into depends entirely on the hash of its value

unordered_set은 위의 해시값을 이용해서 컨테이너에 저장하는 것
스택에 unordered_set의 객체가 생기고 힙에 있는 unordered_set 데이터를 가리킨다
이 unordered_set 데이터에는 버킷들이 있음. 
각 키값에 대응하는 해시값에 의하여 버킷 카운트 넘버가 결정되고 이 넘버에 맞게 문자열이 링크드 리스트 형태로 버킷에 연결되게 됨
즉 해시값에 해당하는 버킷 넘버에 해당하는 문자열이 링크드 리스트 형태로 묶여 있는 것 

해시값을 이용하기 때문에 O(1) 시간복잡도가 걸리는 것 
문제는 unordered_set에 들어가는 엘레먼트들이 많아지면 버킷 자체가 늘어나고 rehashing이 발생해서 연결되는 버킷들이 달라짐
리해싱의 O(n)이므로, 이를 방지하기 위해 미리 메모리 공간을 확보하는 것이 좋음, 바로 reserve
또한 버킷당 몇개의 엘레먼트가 들어갈지 사용자가 결정해줄수도 있음, 바로 max_load_factor
*/
