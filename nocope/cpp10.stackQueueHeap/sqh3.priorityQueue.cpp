#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> nums;
    nums.emplace(1);
    nums.emplace(3);
    nums.emplace(5);
    nums.emplace(7);
    nums.emplace(9);

    cout << nums.top() << endl;

    nums.pop();
    nums.pop();
    nums.pop();

    cout << nums.top() << endl;

    return 0;
}






/*
queue: FIFO, first in first out
priority queue
- insertion, pop: O(log(n))
  O(log(n)) 이라면 바이너리  트리구조 라는 뜻, priority queue 트리구조는 부모노드가 자식노드보다 크다. 끝
  트리구조를 벡터로 구현하려면 위에서 아래로, 왼쪽에서 오른쪽으로 인덱스를 잡아서 배열에 넣어줌
  현재노드의 parentNodeIndex = (idx-1)/2
  현재노드의 leftChildNodeIndex = 2*idx + 1
  현재노드의 rightChildNodeIndex = 2*idx + 2

- top: O(1)
  벡테의 v[0] 이 제일 큰 수가 항상 있는 곳이므로 

*/