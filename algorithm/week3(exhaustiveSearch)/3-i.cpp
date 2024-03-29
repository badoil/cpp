// 문제
// 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 500,000)에 있고, 동생은 점 K(0 ≤ K ≤ 500,000)에 있다. 
// 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
// 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다. 동생은 항상 걷기만 한다. 동생은 항상 매 초마다 이동을 하며, 이동은 가속이 붙는다. 
// 동생이 이동하는 거리는 이전에 이동한 거리보다 1을 더한 만큼 이동한다. 
// 즉, 동생의 처음 위치는 K, 1초가 지난 후 위치는 K+1, 2초가 지난 후 위치는 K+1+2, 3초가 지난 후의 위치는 K+1+2+3이다.

// 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오. 
// 동생을 찾는 위치는 정수 좌표이어야 하고, 수빈이가 0보다 작은 좌표로, 50만보다 큰 좌표로 이동하는 것은 불가능하다.

// 입력
// 첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

// 출력
// 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다. 수빈이가 동생을 찾을 수 없거나, 찾는 위치가 500,000을 넘는 경우에는 -1을 출력한다.



#include<bits/stdc++.h>
using namespace std;

const int MAX = 500000;
int n, k, visited[2][MAX+4], turn;
bool ok;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    queue<int> q;
    visited[0][n] = 1;
    q.push(n);
    while(q.size()) {
        k += turn;                  // 동생의 위치는 시간만큼 가속이 붙음 
        if (n == k) return 0;
        if (k > MAX) break;
        if (visited[turn%2][k]) {   // 수빈이가 지나갔던 위치에 동생이 오면 거기서 기다리면 되니깐 만나는것
            ok = 1;
            break;
        }
        int qSize = q.size();
        for(int i=0; i<qSize; i++) {
            int here = q.front();
            q.pop();
            for (int next: {here-1, here+1, 2*here}) {
                if (next<0 || next > MAX || visited[turn%2][next]) {
                    continue;
                }
                visited[turn%2][next] = visited[(turn+1)%2][here] + 1;
                if (k == next) {
                    ok = 1; 
                    break;
                }
                q.push(next);
            }
        }
        if(ok) break;
        turn++;                 // 시감 체크
    }
    if (ok) cout << turn << "\n";
    else cout << -1 << "\n";
    return 0;
}


// 이문제의 핵심은 수빈이가 동생이 올 위치에 먼저 올 경우, 그 turn 즉 시간의 홀짝도 맞을경우
// 수빈이가 -1, +1을 하면서 동생이 그 위치에 올때까지 기다려서 그 위치에서 만날 수 있다는 점
// 그리고 같은 turn, 즉 시간일때 만나는 경우가 있음