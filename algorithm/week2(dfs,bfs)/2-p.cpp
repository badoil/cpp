// https://www.acmicpc.net/source/share/793d0205325c44949c3e504af42bcfdd


// 문제
// 인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 다행히 바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.
// 연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다. 연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다. 
// 일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다. 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.
// 예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자.

// 2 0 0 0 1 1 0
// 0 0 1 0 1 2 0
// 0 1 1 0 1 0 0
// 0 1 0 0 0 0 0
// 0 0 0 0 0 1 1
// 0 1 0 0 0 0 0
// 0 1 0 0 0 0 0
// 이때, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다. 아무런 벽을 세우지 않는다면, 바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.

// 2행 1열, 1행 2열, 4행 6열에 벽을 세운다면 지도의 모양은 아래와 같아지게 된다.

// 2 1 0 0 1 1 0
// 1 0 1 0 1 2 0
// 0 1 1 0 1 0 0
// 0 1 0 0 0 1 0
// 0 0 0 0 0 1 1
// 0 1 0 0 0 0 0
// 0 1 0 0 0 0 0
// 바이러스가 퍼진 뒤의 모습은 아래와 같아진다.

// 2 1 0 0 1 1 2
// 1 0 1 0 1 2 2
// 0 1 1 0 1 2 2
// 0 1 0 0 0 1 2
// 0 0 0 0 0 1 1
// 0 1 0 0 0 0 0
// 0 1 0 0 0 0 0
// 벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다. 위의 지도에서 안전 영역의 크기는 27이다.

// 연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)
// 둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.
// 빈 칸의 개수는 3개 이상이다.

// 출력
// 첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.


#include<bits/stdc++.h>
using namespace std;

int m, n, a[10][10], ny, nx;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool virus[10][10];
vector<pair<int,int>> v;


void dfs(int y, int x) {
    if (virus[y][x] || a[y][x]==1) return;
    virus[y][x] = 1;
    for(int i=0; i<4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny<0||ny>=m||nx<0||nx>=n) continue;
        dfs(ny, nx);
    }
}


int sol() {
    memset(virus, 0, sizeof(virus));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j] == 2) dfs(i, j);
        }
    }
    int count;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j] == 0 && !virus[i][j]) count++;
        }
    }
    return count;
}


int main() {
    cin >> m >> n;
    for (int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
            if (a[i][j]==0) v.push_back({i, j});       // 벽을 세울수 있는 a 맵의 위치를 페어로 벡터에 넣어둠
        }
    }

    assert(v.size() >= 3);  // 벽을 세울 수 있는 공간이 3개 이상은 되어야함
    int ans = 0;
    for (int i=0; i<v.size(); i++) {
        for(int j=0; j<i; j++) {        // 인덱스를 j<i,
            for(int k=0; k<j; k++) {    // k<j 이렇게 걸면 각 인덱스가 중복이 안됨
                a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1;   // 벽을 세울 수 있는 공간에 벽을 세움
                ans = max(ans, sol());
                a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0;   // 벽 세운거 없애고 다시 초기화
            }
        }
    }

    cout << ans;
    return 0;
}

// 3개의 벽  +  바이러스 퍼뜨리기 + 안전영역 카운팅
// 3개의 벽을 무작위로 삼중 포문으로 세우기(이때 세개의 인덱스 주목)
// 바이러스는 dfs 로 퍼뜨리기
// 그리고 카운팅

// 여기서 포인트는 virus[10][10] 카운팅하는 용도로 이중배열 만들어 놓기
// a[10][10] 원래 맵에다 할 수도 있지만 이를 다시 초기화 시키는게 어렵기에 바이러스 맵 하나 만듬

// 일단 문제를 만나면 완전탐색으로 풀 수 있을지 생각해보고
// 풀수 있으면 저렇게 삼중 포문 돌려버림
// 