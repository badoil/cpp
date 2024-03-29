// https://www.acmicpc.net/problem/17136

// 문제
// <그림 1>과 같이 정사각형 모양을 한 다섯 종류의 색종이가 있다. 색종이의 크기는 1×1, 2×2, 3×3, 4×4, 5×5로 총 다섯 종류가 있으며, 각 종류의 색종이는 5개씩 가지고 있다.

// <그림 1>

// 색종이를 크기가 10×10인 종이 위에 붙이려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 0 또는 1이 적혀 있다. 
// 1이 적힌 칸은 모두 색종이로 덮여져야 한다. 색종이를 붙일 때는 종이의 경계 밖으로 나가서는 안되고, 겹쳐도 안 된다. 
// 또, 칸의 경계와 일치하게 붙여야 한다. 0이 적힌 칸에는 색종이가 있으면 안 된다.
// 종이가 주어졌을 때, 1이 적힌 모든 칸을 붙이는데 필요한 색종이의 최소 개수를 구해보자.

// 입력
// 총 10개의 줄에 종이의 각 칸에 적힌 수가 주어진다.

// 출력
// 모든 1을 덮는데 필요한 색종이의 최소 개수를 출력한다. 1을 모두 덮는 것이 불가능한 경우에는 -1을 출력한다.


#include <bits/stdc++.h>
using namespace std;

const int INF=987654321;
int a[14][14], ret = INF, n=10;
map<int, int> _map;

bool check(int y, int x, int size) {
    if (y+size>n || x+size>n) return false;
    for (int i=y; i<y+size; i++) {              // 색종이 size 만큼 체크하기
        for (int j=x; j<x+size; j++) {
            if (a[i][j] == 0) return false;
        }
    }
    return true;
}

void draw(int x, int y, int size, int val) {        
    for (int i=y; i<y+size; i++) {              // size 만큼 체크하기
        for (int j=x; j<x+size; j++) {
            a[i][j] == val;
        }
    }
}

void dfs(int y, int x, int cnt) {
    if (cnt>=ret) return;           // 여러 가지 뻗어가는 중에 색종이 갯수인 cnt가 ret 보다 크다?? 그럼 색종이의 최소갯수가 아니기 때문에 더 볼것도 없이 진행할 필요 없음
    if (x==n) {
        dfs(y+1, x, cnt);           // 한 줄의 끝까지 왔으면 다음줄로 넘어가기에 y+1 해줌
        return;
    }
    if (y==n) {                     // 만약 주어진 색종이들로 1을 다 덮지 못하면 여기까지 오지도 못해서 ret는 INF로 남게됨
        ret = min(ret, cnt);
        return;
    }

    for (int i=5; i>=1; i--){       // 최소한의 색종이 수를 구해야하므로 큰 색종이인 사이즈5 부터 시작
        if (_map[i] == 5) continue; // 종류별로 5장씩 있기에, 더 사용할 색종이가 없으므로 다음으로 넘김
        if (check(y, x, i)) {       // 해당부분에 색종이 붙일 수 있는지 체크
            _map[i]++;
            draw(y, x, i, 0);
            dfs(y, x+i, cnt+1);     // 체크한 색종이 사이즈 그 다음부터 dfs 해야하므로 x+i
            draw(y, x, i, 1);       // 다음 반복문은 새로 시작하는 판이므로 되돌려놓는다, 즉 이는 두개의 경우의 수로 분기하는 효과를 가진다. 색종이를 붙이고 dfs 재귀호출(같은사이즈 색종이 또 붙일 수 있음) 또는 색종이 안붙이고 다음 반복문(다른 사이즈 색종이)
            _map[i]--;              // 마찬가지로 되돌려놓음
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }

    dfs(0,0,0);
    cout << (ret == INF? -1 : ret) << "\n";
    return 0;

}



// 이 문제는 완전탐색 같지만
// 큰 색종이부터 체크하면 되는 휴리스틱한 측면이 있어서
// 백 트래킹 문제에 가깝다