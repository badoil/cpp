#include <stack>
#include <queue>
#include <iostream>
using namespace std;

int main()
{
    stack<int> nums;
    nums.emplace(1);
    nums.emplace(2);
    nums.emplace(3);

    cout << nums.top() << endl;
    nums.pop();
    cout << nums.top() << endl;
    nums.pop();
    cout << nums.top() << endl;
    nums.pop();

    cout << "size: " << nums.size() << endl;

    queue<int> qNums;
    qNums.emplace(1);
    qNums.emplace(2);
    qNums.emplace(3);

    cout << qNums.front() << " " << qNums.back() << endl;
    qNums.pop();
    cout << qNums.front() << " " << qNums.back() << endl;
    qNums.pop();
    cout << qNums.front() << " " << qNums.back() << endl;
    qNums.pop();

    cout << "size: " << qNums .size() << endl;

    return 0;       
}



/*
stack: LIFO, last in first out
queue: FIFO, first in first out

출력결과
3
2
1
size: 0
1 3
2 3
3 3
size: 0

*/