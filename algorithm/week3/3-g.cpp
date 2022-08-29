// 문제
// 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
// 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

// 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 그리고, 가장 빠른 시간으로 찾는 방법이 몇 가지 인지 구하는 프로그램을 작성하시오.

// 입력
// 첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

// 출력
// 첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
// 둘째 줄에는 가장 빠른 시간으로 수빈이가 동생을 찾는 방법의 수를 출력한다.

#include<bits/stdc++.h>
using namespace std;


const int MAX = 100004;
int n, k,  visited[MAX+4];
long long cnt[MAX+4];


int main() {
    cin >> n >> k;
    
    if (n == k) {
        cout << 0 << "\n";
        return;
    }

    queue<int> q;
    q.push(n);
    visited[n] = 1;
    cnt[n] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int next: { cur-1, cur+1, 2*cur }) {
            if (0<=next && next <= MAX) {
                if(!visited[next]) {
                    q.push(next);
                    visited[next] = visited[cur]+1;
                    cnt[next] += cnt[cur];
                } else if (visited[next] == visited[cur]+1) {
                    cnt[next] += cnt[cur];
                }
            }
        }
    }

    cout << visited[k] - 1 << "\n";     // 최초의 시간 visited[n] = 1 에 1을 넣어줬었기에 다시 1을 빼줌 
    cout << cnt[k] << "\n";             // 구하고자 하는 k 인덱스의 값을 출력
    
    return 0;
}


// 이 문제에서 최단 거리가 최단 시간인 셈, 이것을 visited 에 채워넣음
// 경우의 수는 각 노드가 처음에 0으로 되어 있음
// 어떤 경로는 cnt[n] = 1 최초 값으로부터 cnt[next] += cnt[n] 을 계속 더해주는 것임
// 이 경우 cnt[k] 까지 1로 입력될 것임
// 그런데 visited[next] == visited[cur]+1 인 경우, 이 뜻은 최단시간으로 visited[next]에 도달한 경우의 수가 이미 있다는 뜻
// 그러므로 이때, 이 시간의 cnt[next] 경우의 수에 cnt[cur]를 더해줌, 즉 지금의 새로운 경우의 수를 더해준 것임