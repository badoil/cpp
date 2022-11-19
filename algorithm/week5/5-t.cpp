// https://www.acmicpc.net/problem/17143
// 문제
// 낚시왕이 상어 낚시를 하는 곳은 크기가 R×C인 격자판으로 나타낼 수 있다. 격자판의 각 칸은 (r, c)로 나타낼 수 있다. r은 행, c는 열이고, 
// (R, C)는 아래 그림에서 가장 오른쪽 아래에 있는 칸이다. 칸에는 상어가 최대 한 마리 들어있을 수 있다. 상어는 크기와 속도를 가지고 있다.

// 낚시왕은 처음에 1번 열의 한 칸 왼쪽에 있다. 다음은 1초 동안 일어나는 일이며, 아래 적힌 순서대로 일어난다. 낚시왕은 가장 오른쪽 열의 오른쪽 칸에 이동하면 이동을 멈춘다.

// 낚시왕이 오른쪽으로 한 칸 이동한다.
// 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
// 상어가 이동한다.
// 상어는 입력으로 주어진 속도로 이동하고, 속도의 단위는 칸/초이다. 상어가 이동하려고 하는 칸이 격자판의 경계를 넘는 경우에는 방향을 반대로 바꿔서 속력을 유지한채로 이동한다.

// 왼쪽 그림의 상태에서 1초가 지나면 오른쪽 상태가 된다. 상어가 보고 있는 방향이 속도의 방향, 왼쪽 아래에 적힌 정수는 속력이다. 왼쪽 위에 상어를 구분하기 위해 문자를 적었다.
// 상어가 이동을 마친 후에 한 칸에 상어가 두 마리 이상 있을 수 있다. 이때는 크기가 가장 큰 상어가 나머지 상어를 모두 잡아먹는다.
// 낚시왕이 상어 낚시를 하는 격자판의 상태가 주어졌을 때, 낚시왕이 잡은 상어 크기의 합을 구해보자.

// 입력
// 첫째 줄에 격자판의 크기 R, C와 상어의 수 M이 주어진다. (2 ≤ R, C ≤ 100, 0 ≤ M ≤ R×C)
// 둘째 줄부터 M개의 줄에 상어의 정보가 주어진다. 상어의 정보는 다섯 정수 r, c, s, d, z (1 ≤ r ≤ R, 1 ≤ c ≤ C, 0 ≤ s ≤ 1000, 1 ≤ d ≤ 4, 1 ≤ z ≤ 10000) 로 이루어져 있다. 
// (r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기이다. d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.
// 두 상어가 같은 크기를 갖는 경우는 없고, 하나의 칸에 둘 이상의 상어가 있는 경우는 없다.

// 출력
// 낚시왕이 잡은 상어 크기의 합을 출력한다.


#include<bits/stdc++.h>
#define max_n 104
using namespace std;

struct Shark {
    int y, x, s, dir, z, death;
}a[max_n*max_n];

int r, c, m, shark[max_n][max_n], temp[max_n][max_n], ret;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> m;

    // 상어 초기화
    for(int i=0; i<m; i++) {
        cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z;

        a[i].y--, a[i].x--, a[i].dir--;
        
        if (a[i].dir <= 1) a[i].s %= (2*(r-1));
        else a[i].s %= (2*(c-1));

        shark[a[i].y][a[i].x] = i;
    }

    for (int t=0; t<c; t++) {
        for (int i=0; i<r; i++) {
            if (shark[i][t]) {
                ret += a[shark[i][t]].z;
                a[shark[i][t]].death = 1;
                shark[i][t] = 0;
            }
        }

        memset(temp, 0, sizeof(temp));
        // 상어 이동 시키기
        for (int i=0; i<m; i++) {
            if (a[i].death) continue;
            
            int dir = a[i].dir;
            int y = a[i].y;
            int x = a[i].x;
            int s = a[i].s;
            int ny;
            int nx;

            while (true) {
                ny = y + dy[dir];
                nx = x + dx[dir];

                if (dir <= 0){          // y 축으로 움직임
                    if (ny<0) {
                        s -= y;
                        y = 0;
                    } else {
                        s = r - 1 - y;
                        y = r - 1;
                    }
                    dir ^= 1;
                } else {                // x 축으로 움직임
                    if (nx<0) {
                        s -= x;
                        x = 0;
                    } else {
                        s -= c - 1 - x;
                        x = c - 1;
                    }
                    dir ^= 1;
                }
            }
            
            if (temp[ny][nx]) {
                if (a[temp[ny][nx]].z > a[i].z) {
                    a[i].death = 1;
                } else {
                    a[temp[ny][nx]].death = 1;
                    temp[ny][nx] = i;
                }
            } else {
                temp[ny][nx] = i;
            }

            a[i].y = ny;
            a[i].x = nx;
            a[i].dir = dir;
        }
        memcpy(shark, temp, sizeof(temp));
    } 

    cout << ret << "\n";
    return 0;
}