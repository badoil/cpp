// 문제
// 한수는 캠프를 마치고 집에 돌아가려 한다. 한수는 현재 왼쪽 아래점에 있고 집은 오른쪽 위에 있다. 그리고 한수는 집에 돌아가는 방법이 다양하다. 단, 한수는 똑똑하여 한번 지나친 곳을 다시 방문하지는 않는다.

//       cdef  ...f  ..ef  ..gh  cdeh  cdej  ...f 
//       bT..  .T.e  .Td.  .Tfe  bTfg  bTfi  .Tde 
//       a...  abcd  abc.  abcd  a...  a.gh  abc. 
// 거리 :  6     6     6     8     8    10    6
// 위 예제는 한수가 집에 돌아갈 수 있는 모든 경우를 나타낸 것이다. T로 표시된 부분은 가지 못하는 부분이다. 문제는 R x C 맵에 못가는 부분이 주어지고 거리 K가 주어지면 한수가 집까지도 도착하는 경우 중 거리가 K인 가짓수를 구하는 것이다.

// 입력
// 첫 줄에 정수 R(1 ≤ R ≤ 5), C(1 ≤ C ≤ 5), K(1 ≤ K ≤ R×C)가 공백으로 구분되어 주어진다. 두 번째부터 R+1번째 줄까지는 R×C 맵의 정보를 나타내는 '.'과 'T'로 구성된 길이가 C인 문자열이 주어진다.

// 출력
// 첫 줄에 거리가 K인 가짓수를 출력한다.


#include<bits/stdc++.h>
using namespace std;

int r, c, k, visited[10][10];
string s;
char a[10][10];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};


int go (int y, int x) {
    if (y==0 && x==c-1) {
        if (visited[y][x] == k) {       // 그 거리가 k 인 경우
            return 1;
        }
        return 0;
    }

    int ret = 0;
    for (int i=0; i<4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (a[ny][nx]=='T' || visited[ny][nx]) continue;
        if (y<0||nx<0||ny>=r||nx>=c) continue;
        visited[ny][nx] = visited[y][x] + 1;
        ret += go(ny, nx);                      // visited[y][x] == k 에 해당하는 경우들이 ret에 합쳐짐
        visited[ny][nx] = 0;                    // 이미 방문한 애들은 다시 원복
    }
    return ret;
}


int main() {
    cin >> r >> c >> k;

    for (int i=0; i<r; i++) {
        cin >> s;
        for (int j=0; j<c; j++) {
            a[i][j] = s[j];
        }
    }

    visited[r-1][0] = 1;
    cout << go(r-1, 0) << "\n";
    return 0;
}


// bfs 와 완전탐색이 합쳐진 문제
// 지나친 곳은 다시 가지 않으므로, visited에 거리를 기입하면서 진행
// 그 거리가 k 인 경우의 수를 출력