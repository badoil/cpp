
// 문제
// 두 마리의 백조가 호수에서 살고 있었다. 그렇지만 두 마리는 호수를 덮고 있는 빙판으로 만나지 못한다.
// 호수는 행이 R개, 열이 C개인 직사각형 모양이다. 어떤 칸은 얼음으로 덮여있다.
// 호수는 차례로 녹는데, 매일 물 공간과 접촉한 모든 빙판 공간은 녹는다. 두 개의 공간이 접촉하려면 가로나 세로로 닿아 있는 것만 (대각선은 고려하지 않는다) 생각한다.
// 아래에는 세 가지 예가 있다.

// ...XXXXXX..XX.XXX ....XXXX.......XX .....XX.......... 
// ....XXXXXXXXX.XXX .....XXXX..X..... ......X.......... 
// ...XXXXXXXXXXXX.. ....XXX..XXXX.... .....X.....X..... 
// ..XXXXX..XXXXXX.. ...XXX....XXXX... ....X......XX.... 
// .XXXXXX..XXXXXX.. ..XXXX....XXXX... ...XX......XX.... 
// XXXXXXX...XXXX... ..XXXX.....XX.... ....X............ 
// ..XXXXX...XXX.... ....XX.....X..... ................. 
// ....XXXXX.XXX.... .....XX....X..... ................. 
//       처음               첫째 날             둘째 날


// 백조는 오직 물 공간에서 세로나 가로로만(대각선은 제외한다) 움직일 수 있다.
// 며칠이 지나야 백조들이 만날 수 있는 지 계산하는 프로그램을 작성하시오.

// 입력
// 입력의 첫째 줄에는 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1500.
// 다음 R개의 줄에는 각각 길이 C의 문자열이 하나씩 주어진다. '.'은 물 공간, 'X'는 빙판 공간, 'L'은 백조가 있는 공간으로 나타낸다.

// 출력
// 첫째 줄에 문제에서 주어진 걸리는 날을 출력한다.

#include<bits/stdc++.h>
using namespace std;

char _map[1504][1504];
int r, c, visited[1504][1504], swanVisited[1504][1504], swanY, swanX;
int day;
string s;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
bool ret;

queue<pair<int, int>> waterQ, water_tempQ, swanQ, swan_tempQ;
void qClear(queue<pair<int, int>> &q) {
    queue<pair<int, int>> empty;
    swap(q, empty);
}

void meltWater() {
    while(waterQ.size()) {
        pair<int, int> wq = waterQ.front();
        waterQ.pop();
        int y = wq.first;
        int x = wq.second;

        for(int i=0; i<4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if(ny<0||nx<0||ny>=r||nx>=c||visited[ny][nx]) continue;
            if(_map[ny][nx] == 'X') {           // 얼음을 만나면 거기서부터 다음 턴에 시작해야하므로
                water_tempQ.push({ny, nx});     // 그 위치를 water_tempQ에 넣어주고
                visited[ny][nx] = 1;            // 물 방문 체크
                _map[ny][nx] == '.';            // 그 얼음 녹여서 물로 만듬
            }  
        }
    }
}

void moveSwan() {
    while(swanQ.size()) {
        pair<int, int> sq = swanQ.front();
        swanQ.pop();
        int y = sq.first;
        int x = sq.second;

        for(int i=0; i<4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if(ny<0||nx<0||ny>=r||nx>=c||swanVisited[ny][nx]) continue;
            if(_map[ny][nx] == 'L') {ret=true; return;}                     // 다른 백조 만나면 true 만들고 리턴
            else if(_map[ny][nx] == 'X') swan_tempQ.push({ny, nx});         // 얼음 만나면 다음에 거기서부터 움직여야 하므로 swan_tempQ에 넣어둠(이 얼음은 meltWater 함수로 다음 턴에는 물이 됨)
            else if(_map[ny][nx] == '.') swanQ.push({ny, nx});              // 물을 만나면 움직여야 하므로 swanQ에 넣어줌
            swanVisited[ny][nx] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for(int i=0; i<r; i++) {
        cin >> s;
        for(int j=0; j<c; j++) {
            _map[i][j] = s[j];
            if (_map[i][j] == 'L') swanY = i; swanX = j;
            if (_map[i][j] == '.' || _map[i][j] == 'L') {       // 물과 백조가 있는 위치는 물임
                visited[i][j] = 1;                              // 물 방문 visited 체크
                waterQ.push({i, j});                            // 물큐에 넣어줌
            }
        }
    }

    swanQ.push({swanY, swanY});
    swanVisited[swanY][swanX]=1;
    while(!ret) {
        moveSwan();                     // 일단 백조를 움직이고
        if (ret) break;                 // 움직였는데 다른 백조를 만나면 브레이크
        meltWater();                    // 백조 움직였는데 다른 백조 안만났으면 이제 얼음 녹임
        swanQ = swan_tempQ;             // 다음 턴 시작할 백조의 위치 큐에 넣어줌
        waterQ = water_tempQ;           // 다음 턴 시작할 물의 위치 큐에 넣음
        qClear(swan_tempQ);             // 임시큐들 비워버림
        qClear(water_tempQ);
        day++;                          // 한번 돌았으면 하루 더해줌
    }

    cout << day << "\n";
    return 0;
    
}