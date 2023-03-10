// *
// 문제

// 수빈이는 강호와 함께 스타크래프트 게임을 하고 있다. 수빈이는 뮤탈리스크 1개가 남아있고, 강호는 SCV N개가 남아있다.
// 각각의 SCV는 남아있는 체력이 주어져있으며, 뮤탈리스크를 공격할 수는 없다. 즉, 이 게임은 수빈이가 이겼다는 것이다.
// 뮤탈리스크가 공격을 할 때, 한 번에 세 개의 SCV를 공격할 수 있다.

// 첫 번째로 공격받는 SCV는 체력 9를 잃는다.
// 두 번째로 공격받는 SCV는 체력 3을 잃는다.
// 세 번째로 공격받는 SCV는 체력 1을 잃는다.

// SCV의 체력이 0 또는 그 이하가 되어버리면, SCV는 그 즉시 파괴된다. 한 번의 공격에서 같은 SCV를 여러 번 공격할 수는 없다.
// 남아있는 SCV의 체력이 주어졌을 때, 모든 SCV를 파괴하기 위해 공격해야 하는 횟수의 최솟값을 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 SCV의 수 N (1 ≤ N ≤ 3)이 주어진다. 둘째 줄에는 SCV N개의 체력이 주어진다. 체력은 60보다 작거나 같은 자연수이다.

// 출력
// 첫째 줄에 모든 SCV를 파괴하기 위한 공격 횟수의 최솟값을 출력한다.

// 힌트
// 1, 3, 2 순서대로 공격을 하면, 남은 체력은 (12-9, 10-1, 4-3) = (3, 9, 1)이다. 2, 1, 3 순서대로 공격을 하면, 남은 체력은 (0, 0, 0)이다.

#include<bits/stdc++.h>
using namespace std;

int n, a[3], visited[1004][1004][1004];
int attack[6][3] = {
    {9, 3, 1}, 
	{9, 1, 3}, 
	{3, 1, 9}, 
	{3, 9, 1}, 
	{1, 3, 9}, 
	{1, 9, 3}
};
struct A {
    int a, b, c;
};

queue<A> q;
int bfs(int x, int y, int z) {
    visited[x][y][z] = 1;
    q.push({x, y, z});
    while(q.size()) {
        int dx = q.front().a;
        int dy = q.front().b;
        int dz = q.front().c;
        q.pop();
        if (visited[0][0][0]) break;
        for(int i=0; i<6; i++) {
            int nx = max(0, dx-attack[i][0]);       // 배열의 인덱스는 음수가 될 수 없으므로, 음수가 나오면 0으로 할당
            int ny = max(0, dy-attack[i][1]);
            int nz = max(0, dz-attack[i][2]);
            visited[nx][ny][nz] = visited[dx][dy][dz] + 1;
            q.push({nx, ny, nz});
        }
    }
    return visited[0][0][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    cout << bfs(a[0], a[1], a[2])-1 << "\n";
    return 0;
}




// bfs 문제는 결국 노드와 간선으로 나타낸 그래프는 어디든 적용되는것
// 2차원 배열도 한 좌표노드에서 4개의(상,하,좌,우)좌표 노드로 이어지는 간선이 있는 그래프
// 이 문제에서는 scv 체력이 {0, 0, 0} 이 제일 빨리 되는 경우의 수를 찾는 문제
// 즉 bfs 문제임
// 이때 attack[6][3] 요놈이 이차원배열의 상하좌우 움직이는 dx, dy 역할임
// {9, 3, 1} 로 줄어드는 공격의 순열이 6개
// visited[0][0][0], 즉 scv 3개의 체력이 0이 되는 순간의 값에서 1을 빼준 값이
// 모든 SCV를 파괴하기 위한 공격 횟수의 최솟값
// visited[0][0][0] - 1, 해주는 이유는 최조의  visited[x][y][z] = 1 해주기때문임