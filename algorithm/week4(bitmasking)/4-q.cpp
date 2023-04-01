// 문제
// 오아시스의 재결합 공연에 N명이 한 줄로 서서 기다리고 있다.
// 이 역사적인 순간을 맞이하기 위해 줄에서서 기다리고 있던 백준이는 갑자기 자기가 볼 수 있는 사람의 수가 궁금해 졌다.
// 두 사람 A와 B가 서로 볼 수 있으려면, 두 사람 사이에 A 또는 B보다 키가 큰 사람이 없어야 한다.
// 줄에 서있는 사람의 키가 주어졌을 때, 서로 볼 수 있는 쌍의 수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 줄에서 기다리고 있는 사람의 수 N이 주어진다. (1 ≤ N ≤ 500,000)
// 둘째 줄부터 N개의 줄에는 각 사람의 키가 나노미터 단위로 주어진다. 모든 사람의 키는 231 나노미터 보다 작다.
// 사람들이 서 있는 순서대로 입력이 주어진다.

// 출력
// 서로 볼 수 있는 쌍의 수를 출력한다.


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  
ll n, ret, temp;
stack<pair<int, int>> stk;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> temp;
        int cnt = 1;
        while(stk.size() && stk.top().first <= temp) {
            ret += stk.top().second;
            if (stk.top().first == temp) cnt = stk.top().second + 1;
            else cnt = 1;
            stk.pop();
        }
        if (stk.size()) ret++;
        stk.push({temp, cnt});
    }

    cout << ret << "\n";
    return 0;
}



// 1. 오름차순 일때는 스택에서 팝
// 2. 내림차순은 팝할 필요도 없이 그냥 ret에 1씩 더해줌
// 3. 숫자는 long long 으로 해야함  -> n이 50만까지이므로 얘들이 모두 같은 수이면, 등차수열 n(n+1), 즉 대략 50만 * 50만 이므로 long long 으로 처리해야함
// 4. 키가 같은 애들이 연속으로 나올때 처리

// 짝의 수를 구하는 문제
// 짝하면 스택 생각해보기