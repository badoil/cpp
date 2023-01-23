// 문제
// 세준이는 노트북을 누가 가져갈까봐 자물쇠로 잠가놓는다. 자물쇠는 동그란 디스크 N개로 구성되어 있다. 
// 각 디스크에는 숫자가 0부터 9까지 숫자가 표시되어 있다. 디스크는 원형이기 때문에, 0과 9는 인접해 있다.

// 세준이는 한 번 자물쇠를 돌릴 때, 최대 세 칸을 시계 방향 또는 반시계 방향으로 돌릴 수 있다. 또, 최대 세 개의 인접한 디스크를 한 번에 돌릴 수 있다.
// 현재 자물쇠의 상태와 세준이의 비밀번호가 주어질 때, 자물쇠를 최소 몇 번 돌려야 풀 수 있는지 구하는 프로그램을 작성하시오.
// 자물쇠의 상태가 555이고, 세준이의 비밀번호가 464인 경우에, 각 디스크를 따로 따로 돌리면 3번 돌려야 한다. 
// 하지만, 디스크 3개를 동시에 돌려서 444로 만들고, 2번째 디스크를 6으로 돌리면 2번만에 돌릴 수 있다.

// 입력
// 첫째 줄에 세준이의 비밀번호의 길이 (자물쇠의 크기) N이 주어진다. N은 100보다 작거나 같다. 둘째 줄에 현재 자물쇠의 상태가 주어지고, 셋째 줄에 세준이의 비밀번호가 주어진다.

// 출력
// 첫째 줄에 최소 몇 번을 돌려야 풀 수 있는지 구하는 프로그램을 작성하시오.

#include <bits/stdc++.h>
using namespace std;

int n, dp[104][10][10][10][2], a[104], b[104];
const int INF = 987654321;

int _mod(int x) {
    return x < 0 ? x + 10 : x % 10;
}

int go(int idx, int x, int y, int z, int flag) {
    if (idx == n) return 0;
    int &ret = dp[idx][x][y][z][flag];
    if (ret != -1) return ret;
    if (_mod(a[idx]+x) == _mod(b[idx])) return ret = min(go(idx+1, y, z, 0, 0), go(idx+1, y, z, 0, 1)); // 기존 x 자리에 y가, 기존 자리에 z, 기존 z에는 0
    // 즉 현재 디스크idx를 x 만큼 돌렸을때 비번과 맞는 것을 체크
    // 현재 디스크가 비번이 맞으면 다음 디스크로 이동 idx+1 해줌

    ret = INF;  // 최소값이므로 최대값 설정해 놓음
    int _flag = flag ? 1 : -1;
    for (int i=1; i<=3; i++) {  // 최대 3칸 이동 + 최대 세개의 디스크 변경 가능 
        ret = min(ret, go(idx, _mod(x+i*_flag), y, z, 1)+1);
        ret = min(ret, go(idx, _mod(x+i*_flag), _mod(y+i*_flag), z, 1)+1);
        ret = min(ret, go(idx, _mod(x+i*_flag), _mod(y+i*_flag), _mod(z+i*_flag), 1)+1);
    }
    return ret;
}

int main () {
    memset(dp, -1, sizeof(dp));
    scanf("%d\n", &n);
    for (int i=0; i<n; i++) scanf("%ld ", &a[i]);   // 각 자물쇠의 현 숫자를 배열에
    for (int i=0; i<n; i++) scanf("%ld ", &b[i]);   // 각 자물쇠의 비밀번호를 배열에

    printf("%d\n", min(go(0, 0, 0, 0, 0), go(0, 0, 0, 0, 1)));
    return 0;
}


// 디피 문제
// dp[idx][x][y][z][flag], 현재 디스크idx, 현재 디스크 x만큼 돌릴, 다음 디스크 y만큼 돌릴, 다음 디스크 z만큼 돌릴, 시계방향여부 flag
// 최대 3개의 디스크 돌릴 수 있기에 x, y, z