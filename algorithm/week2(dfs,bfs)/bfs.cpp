// bfs 예제

// 승원이는 당근을 좋아해서 당근마킷에 엔지니어로 취업했다. 당근을 매우좋아하기 때문에 차도 당근차를 샀다. 이 당근차는 한칸 움직일 때마다 당근을 내뿜으면서 간다. 
// 즉, "한칸" 움직일 때 "당근한개"가 소모된다는 것이다. 승원이는 오늘도 아침 9시에 일어나 당근마킷으로 출근하고자 한다. 
// 승원이는 최단거리로 당근마킷으로 향한다고 할 때 당근몇개를 소모해야 당근마킷에 갈 수 있는지 알아보자. 이 때 승원이는 육지로만 갈 수 있으며 바다로는 못간다. 
// 맵의 1은 육지며 0은 바다를 가리킨다. 승원이는 상하좌우로만 갈 수 있다. 

// 입력
// 맵의 세로길이 N과 가로길이 M 이 주어지고 이어서 N * M의 맵이 주어진다. 그 다음 줄에 승원이의 위치(y, x)와 당근마킷의 위치(y, x)가 주어진다. 

// 출력
// 당근을 몇개 소모해야 하는지 출력하라.

// 범위
// 1 <= N <= 100
// 1 <= M <= 100 


#include<bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int m, n, a[104][104], visited[104][104], ey, ex, my, mx, ny, nx, yy, xx;


int main() {
    cin >> m >> n;
    for (int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }

    cin >> ey >> ex;
    cin >> my >> mx;  

    queue<pair<int, int>> q;
    q.push({ey, ex});
    visited[ey][ex] = 1;
    while(q.size()) {
        tie(yy, xx) = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            ny = yy + dy[i];
            nx = xx + dx[i];
            if (ny<0 || ny>=m || nx<0 || nx>=n || a[ny][nx]==0 || visited[ny][nx]) continue;
            visited[ny][nx] = visited[yy][xx] + 1;
            q.push({ny, nx});
        }
    }
    cout << visited[my-1][mx-1] << "\n";

    // 디버깅
    for (int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

