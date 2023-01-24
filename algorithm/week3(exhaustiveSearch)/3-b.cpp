// 문제
// 보물섬 지도를 발견한 후크 선장은 보물을 찾아나섰다. 보물섬 지도는 아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 있다. 
// 각 칸은 육지(L)나 바다(W)로 표시되어 있다. 이 지도에서 이동은 상하좌우로 이웃한 육지로만 가능하며, 한 칸 이동하는데 한 시간이 걸린다. 
// 보물은 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다. 
// 육지를 나타내는 두 곳 사이를 최단 거리로 이동하려면 같은 곳을 두 번 이상 지나가거나, 멀리 돌아가서는 안 된다.

// 예를 들어 위와 같이 지도가 주어졌다면 보물은 아래 표시된 두 곳에 묻혀 있게 되고, 이 둘 사이의 최단 거리로 이동하는 시간은 8시간이 된다.

// 보물 지도가 주어질 때, 보물이 묻혀 있는 두 곳 간의 최단 거리로 이동하는 시간을 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에는 보물 지도의 세로의 크기와 가로의 크기가 빈칸을 사이에 두고 주어진다. 이어 L과 W로 표시된 보물 지도가 아래의 예와 같이 주어지며, 각 문자 사이에는 빈 칸이 없다. 보물 지도의 가로, 세로의 크기는 각각 50이하이다.

// 출력
// 첫째 줄에 보물이 묻혀 있는 두 곳 사이를 최단 거리로 이동하는 시간을 출력한다.

#include<bits/stdc++.h>
using namespace std;

int n, m, visited[54][54], mx;
int dy[4] = { -1, 0, 1, 0};
int dx[4] = { 0, 1, 0, -1};

char c[54][54];

void bfs(int y, int x) {
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();
        int ny, nx;
        for(int i=0; i<4; i++) {
            ny = dy[i] + y;
            nx = dx[i] + x;
            if (ny<0||nx<0||ny>=n||nx>=m) continue;
            if (visited[ny][nx] == 1) continue;
            if (c[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            mx = max(mx, visited[ny][nx]);
        }
    }
    return;
}

int main() {
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> c[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (c[i][j] == 'L') {
                bfs(i, j);
            }
        }
    }

    cout << mx-1 << "\n";
    return 0;
}




// 문제에서 최단거리 나오면 바로 bfs
// "보물은 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다" 라고 하는데
// 이 말은 보물이 가장 오랜시간이 걸리는 장소에 뭍혀있을때, 이때 두 장소를 최단거리로 이동하는데 그 시간을 구하라는 문제임