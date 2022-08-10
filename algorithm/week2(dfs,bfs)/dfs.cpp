// connected component
// 가장 기본적인 깊이우선 탐색 예제

// 종화는 21세기 유명한 방구쟁이다. 종화는 방구를 낄 때 "이러다... 다 죽어!!" 를 외치며 방구를 뀌는데 
// 이렇게 방귀를 뀌었을 때  방귀는 상하좌우 네방향으로 뻗어나가며 종화와 연결된 "육지"는 모두 다 오염된다. 
// "바다"로는 방구가 갈 수 없다. 맵이 주어졌을 때 종화가 "이러다... 다 죽어!!"를 "최소한" 몇 번외쳐야 모든 맵을 오염시킬 수 있는지 말해보자. 1은 육지며 0은 바다를 가리킨다. 

// 범위
// 1 <= N <= 100
// 1 <= M <= 100 


#include<bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int m, n, a[104][104], ret, ny, nx;
bool visited[104][104];

void dfs(int y, int x) {
    visited[y][x] = true;

    for (int i=0; i<4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if (visited[y][x]) continue;
        if (a[ny][nx] == 1) dfs(ny, nx);
    }
    return;
}

int main () {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    for (int i=0; i<m; i++) {
        for (int k=0; k<n; k++) {
            cin >> a[i][k];
        }
    }

    for (int i=0; i<m; i++) {
        for (int k=0; k<n; k++) {
            if (a[i][k]==1 && !visited[i][k]) {
                dfs(i, k);
                ret++;
            }
        }
    }
    cout << ret << "\n";
}
