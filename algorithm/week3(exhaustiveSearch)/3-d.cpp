// 문제
// 지훈이는 미로에서 일을 한다. 지훈이를 미로에서 탈출하도록 도와주자!
// 미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 탈출할 수 있는지의 여부, 그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다.
// 지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다)  이동한다. 
// 불은 각 지점에서 네 방향으로 확산된다. 
// 지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다. 
// 지훈이와 불은 벽이 있는 공간은 통과하지 못한다.

// 입력
// 입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1000 이다. R은 미로 행의 개수, C는 열의 개수이다.
// 다음 입력으로 R줄동안 각각의 미로 행이 주어진다.

//  각각의 문자들은 다음을 뜻한다.
// #: 벽
// .: 지나갈 수 있는 공간
// J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
// F: 불이 난 공간
// J는 입력에서 하나만 주어진다.

// 출력
// 지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는 경우 IMPOSSIBLE 을 출력한다.
// 지훈이가 미로를 탈출할 수 있는 경우에는 가장 빠른 탈출시간을 출력한다. 

#include<bits/stdc++.h>
using namespace std;

int r, c, a[1004][1004], py, px, ret;
const int INF = 987654321;
bool fireCheck[1004][1004], personCheck[1004][1004];
int dy[4] = { -1, 0, 1, 0};
int dx[4] = { 0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> r >> c;
    queue<pair<int, int>> q;
    fill(&fireCheck[0][0], &fireCheck[0][0] + 1004 * 1004, INF);
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> a[i][j];
            if(a[i][j]=='F') {
                fireCheck[i][j] = 1;
                q.push(make_pair(i, j));
            } else if (a[i][j] == 'J') {
                py = i;
                px = j;
            }
        }
    }

    while(q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (ny<0||nx<0||ny>=r||nx>=c) continue;
            if (fireCheck[ny][nx] != INF) continue;
            if (a[ny][nx] == '#') continue;
            fireCheck[ny][nx] = fireCheck[y][x]+1;
            q.push({ny, nx});
        }
    }    
    
    personCheck[py][px] = 1;
    q.push({py, px});
    while (q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (y==r-1||x==c-1||y==0||x==0) {
            ret = personCheck[y][x];
            break;
        }
        for(int i=0; i<4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (ny<0||nx<0||ny>=r||nx>=c) continue;
            if (!personCheck) continue;
            if (a[ny][nx] == '#') continue;
            if (fireCheck[ny][nx] <= personCheck[ny][nx] + 1) continue;
            personCheck[ny][nx] = personCheck[y][x]+1;
            q.push({ny, nx});
        }
    }

    if (ret != 0 ) cout << ret << "\n";
    else cout << "impossible" << "\n";
    return 0;
}


// bfs를 두번 하는 문제
// 이 문제는 불을 먼저 bfs 로 채우고
// 그 다음에 지훈이를 bfs 해서 같은 좌표를 비교하는 것임
// if (fireCheck[ny][nx] <= personCheck[ny][nx] + 1) continue; 이 조건이 중요함
// fireCheck[ny][nx] > personCheck[ny][nx] + 1 이어야함
// 지훈이가 적어도 불 나기 1초 전에 있었어야 그 좌표를 지날 수 잇음

// 반례는 불이 아예 없는 경우
// 그래서 INF 를 넣어둠
// 반례가 있을지 한번쯤 생각해야함