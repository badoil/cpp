// 문제
// 세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.
// 말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다. 
// 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
// 좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.

// 입력
// 첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. (1 ≤ R,C ≤ 20) 둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀 있는 C개의 대문자 알파벳들이 빈칸 없이 주어진다.

// 출력
// 첫째 줄에 말이 지날 수 있는 최대의 칸 수를 출력한다.

#include<bits/stdc++.h>
using namespace std;

int r, c, ret, ny, nx;
char a[21][21];
int dy[4] = { -1, 0, 1, 0};
int dx[4] = { 0, 1, 0, -1};


void go (int y, int x, int num, int cnt) {
    ret = max(ret, cnt);

    for (int i=0; i<4; i++) {
        ny = y + dy[y];
        nx = x + dx[x];
        if (ny<0 || nx <0 || ny>=r || nx>=c) continue;
        int next = (1 << (int) (a[ny][nx] - 'A'));
        if (num & next == 0) {                               // 두 수의 and 연산이 0이란 뜻은 두 수가 겹치지 않는다는 뜻, 즉 next 가 새로운 수
            go(ny, nx, num | next, cnt+1);                   // num | next 합쳐서 넘기면 next 수도 저장되는것, 
        }

    }
    return;
}


int main() {
    cin >> r >> c;

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> a[i][j];
        }
    }

    go(0, 0, 1 << (int) (a[0][0] - 'A'), 1);        //  문자를 숫자로 변환
    
    cout << ret << "\n";

    return 0;
}


// go 함수의 num 매개변수가 포인트
// 비트연산자의 장점이 극대화