// 문제
// 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
// 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

// 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

// 입력
// 첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

// 출력
// 첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
// 둘째 줄에 어떻게 이동해야 하는지 공백으로 구분해 출력한다.


#include<bits/stdc++.h>
using namespace std;
const int MAX = 200004;
int n, k, visited[MAX], _prev[MAX];
vector<int> ret;

int main() {
    cin >> n >> k;
    
    if (n == k) return 0;

    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        
        for(int next: { here-1, here+1, 2*here }) {
            if (0 <= next && next <= MAX) {
                if (!visited[next]) {
                    q.push(next);
                    _prev[next] = here;
                    visited[next] = visited[here] + 1;
                }
                   
            }
        }
    }

    for(int i=k; i!=n; i=_prev[i]) {      // 자취를 거꾸로 따라 가면서 포문 돈다
        ret.push_back(_prev[i]);
    }
    reverse(ret.begin(), ret.end());
    ret.push_back(k);

    cout << visited[k]-1 << "\n";
    for (int i=0; i<ret.size(); i++) {
        cout << ret[i] << " ";
    }

    return 0;
}



// 3-g 와 동일한 유형의 문제
// 지나온 발자취 trace 구하는 문제, 
// _prev[next] = here;
// 그리고 리버스 해주고 마지막 k 값 넣고 출력