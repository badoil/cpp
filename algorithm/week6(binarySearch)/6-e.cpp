// 문제
// 자연수를 원소로 갖는 공집합이 아닌 두 집합 A와 B가 있다. 이때, 두 집합의 대칭 차집합의 원소의 개수를 출력하는 프로그램을 작성하시오. 
// 두 집합 A와 B가 있을 때, (A-B)와 (B-A)의 합집합을 A와 B의 대칭 차집합이라고 한다.

// 예를 들어, A = { 1, 2, 4 } 이고, B = { 2, 3, 4, 5, 6 } 라고 할 때,  A-B = { 1 } 이고, B-A = { 3, 5, 6 } 이므로, 대칭 차집합의 원소의 개수는 1 + 3 = 4개이다.

// 입력
// 첫째 줄에 집합 A의 원소의 개수와 집합 B의 원소의 개수가 빈 칸을 사이에 두고 주어진다. 둘째 줄에는 집합 A의 모든 원소가, 
// 셋째 줄에는 집합 B의 모든 원소가 빈 칸을 사이에 두고 각각 주어진다. 각 집합의 원소의 개수는 200,000을 넘지 않으며, 모든 원소의 값은 100,000,000을 넘지 않는다.

// 출력
// 첫째 줄에 대칭 차집합의 원소의 개수를 출력한다.


#include <bits/stdc++.h>
using namespace std;

int a, b, ret, temp;
map<int, int> _map;

int main () {
    cin >> a >> b;
    for (int i=0; i<a; i++) {
        cin >> temp;
        _map[temp]++;
    }

    for (int i=0; i<b; i++) {
        cin >> temp;
        _map[temp]++;
    }

    for (auto c: _map) {
        if(c.second == 1) ret++;        // 1개인 애들이 교집합 아닌 애들
    }

    cout << ret << "\n";
    return 0;
}


// 두 집합의 교집합 제외한 원소의 갯수 구하는 문제
// 카운팅 하기 위해서 배열이나 맵을 써야함
// 여기서 100,000,000 즉 10억 이상 되기 때문에
// 배열을 쓸 수 없고 맵을 써야함