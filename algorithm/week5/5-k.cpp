// https://www.acmicpc.net/problem/17144

// 문제
// 미세먼지를 제거하기 위해 구사과는 공기청정기를 설치하려고 한다. 공기청정기의 성능을 테스트하기 위해 구사과는 집을 크기가 R×C인 격자판으로 나타냈고, 
// 1×1 크기의 칸으로 나눴다. 구사과는 뛰어난 코딩 실력을 이용해 각 칸 (r, c)에 있는 미세먼지의 양을 실시간으로 모니터링하는 시스템을 개발했다. (r, c)는 r행 c열을 의미한다.



// 공기청정기는 항상 1번 열에 설치되어 있고, 크기는 두 행을 차지한다. 공기청정기가 설치되어 있지 않은 칸에는 미세먼지가 있고, (r, c)에 있는 미세먼지의 양은 Ar,c이다.

// 1초 동안 아래 적힌 일이 순서대로 일어난다.

// 미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
// (r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
// 인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
// 확산되는 양은 Ar,c/5이고 소수점은 버린다.
// (r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수) 이다.
// 공기청정기가 작동한다.
// 공기청정기에서는 바람이 나온다.
// 위쪽 공기청정기의 바람은 반시계방향으로 순환하고, 아래쪽 공기청정기의 바람은 시계방향으로 순환한다.
// 바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동한다.
// 공기청정기에서 부는 바람은 미세먼지가 없는 바람이고, 공기청정기로 들어간 미세먼지는 모두 정화된다.
// 다음은 확산의 예시이다.



// 왼쪽과 오른쪽에 칸이 없기 때문에, 두 방향으로만 확산이 일어났다.



// 인접한 네 방향으로 모두 확산이 일어난다.



// 공기청정기가 있는 칸으로는 확산이 일어나지 않는다.

// 공기청정기의 바람은 다음과 같은 방향으로 순환한다.



// 방의 정보가 주어졌을 때, T초가 지난 후 구사과의 방에 남아있는 미세먼지의 양을 구해보자.

// 입력
// 첫째 줄에 R, C, T (6 ≤ R, C ≤ 50, 1 ≤ T ≤ 1,000) 가 주어진다.
// 둘째 줄부터 R개의 줄에 Ar,c (-1 ≤ Ar,c ≤ 1,000)가 주어진다. 공기청정기가 설치된 곳은 Ar,c가 -1이고, 나머지 값은 미세먼지의 양이다. 
// -1은 2번 위아래로 붙어져 있고, 가장 윗 행, 아랫 행과 두 칸이상 떨어져 있다.

// 출력
// 첫째 줄에 T초가 지난 후 구사과 방에 남아있는 미세먼지의 양을 출력한다.

#include<bits/stdc++.h>
using namespace std;

int r, c, t, a[54][54], tmp[54][54], ret;
int dy1[4] = {0, -1, 0, 0};
int dx1[4] = {1, 0, -1, 0};
int dy2[4] = {0, 1, 0, -1};
int dx2[4] = {1, 0, -1, 0};

vector<pair<int, int>> v1;
vector<pair<int, int>> v2;



vector<pair<int, int>> chung(int y, int x, int dy[4], int dx[4]) {
    vector<pair<int, int>> v;
    int cnt = 0;
    int sy = y;
    int sx = x;
    while(true) {
        int ny = y + dy[cnt];
        int nx = x + dx[cnt];
        if (ny==y && nx==x) break;
        if (ny<0 || ny>=r || nx<0 || nx>=c) {
            cnt++;
            ny = y + dy[cnt];
            nx = x + dx[cnt];
        }
        if (sy==y && sx==x) break;
        sy = ny;
        sx = nx;
        v.push_back({ny, nx});
    }
    return v;
}

void misego(int dy[4], int dx[4]) {
    fill(&tmp[0][0], &tmp[0][0]+54*54, 0);
    queue<pair<int, int>> q;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if (a[i][j] != -1) q.push({i, j});
        }
    }
    
    while(q.size()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        int spread = a[y][x]/5;
        for(int i=0; i<4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (ny<0  || ny>=r || nx<0 || nx>=c || a[ny][nx]==-1) continue;
            tmp[ny][nx] += spread;
            a[y][x] -= spread;
        }
    }

    for(int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            a[i][j] += tmp[i][j];
        }
    }

    return;
}

void go(vector<pair<int, int>> &v) {
    for(int i=v.size()-1; i>=0; i--) {
        if (i=0) a[v[0].first][v[0].second] = 0;
        a[v[i].first][v[i].second] = a[v[i-1].first][v[i-1].second];
    }
}

int main () {
    cin >> r >> c >> t;

    int flag = 0;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> a[i][j];

            if (a[i][j]==-1 && !flag) {
                v1 = chung(i, j, dy1, dx1);
                flag = 1;
            } else {
                v2 = chung(i, j, dy2, dx2);
            }
        }
    }
    
    while (t--)
    {
        misego(dy1, dx1);
        go(v1);
        go(v2);        
    }
    
    for(int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            ret += a[i][j];
        }
    }
    
    return 0;
}


// 구현문제
// 1. 공기청정기가 움직이는 좌표를 수집
// 2. 맵상에서 시간에 따라 미세먼지 움직이게 하기
// 3. 공기청정기 작동하면서 미세먼지 움직이게 하기
// 그에따른 자료구조 중요, 체크할것