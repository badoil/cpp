// *
// 문제
// N×N크기의 땅이 있고, 땅은 1×1개의 칸으로 나누어져 있다. 각각의 땅에는 나라가 하나씩 존재하며, r행 c열에 있는 나라에는 A[r][c]명이 살고 있다.
// 인접한 나라 사이에는 국경선이 존재한다. 모든 나라는 1×1 크기이기 때문에, 모든 국경선은 정사각형 형태이다.
// 오늘부터 인구 이동이 시작되는 날이다.
// 인구 이동은 하루 동안 다음과 같이 진행되고, 더 이상 아래 방법에 의해 인구 이동이 없을 때까지 지속된다.

// 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
// 위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
// 국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
// 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
// 연합을 해체하고, 모든 국경선을 닫는다.
// 각 나라의 인구수가 주어졌을 때, 인구 이동이 며칠 동안 발생하는지 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N, L, R이 주어진다. (1 ≤ N ≤ 50, 1 ≤ L ≤ R ≤ 100)
// 둘째 줄부터 N개의 줄에 각 나라의 인구수가 주어진다. r행 c열에 주어지는 정수는 A[r][c]의 값이다. (0 ≤ A[r][c] ≤ 100)
// 인구 이동이 발생하는 일수가 2,000번 보다 작거나 같은 입력만 주어진다.

// 출력
// 인구 이동이 며칠 동안 발생하는지 첫째 줄에 출력한다.

// 예제 입력 3          예제 출력 3
// 2 20 50            1
// 50 30
// 30 40

// 3 5 10             2
// 10 15 20
// 20 30 25
// 40 22 10

#include <bits/stdc++.h>
using namespace std;

int n, l, r, a[54][54], visited[54][54], cnt, sum;
vector<pair<int, int>> v;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, vector<pair<int, int>> &v)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue;
        if (visited[ny][nx] == 1)
            continue;
        if (l <= abs(a[y][x] - a[ny][nx]) && abs(a[y][x] - a[ny][nx]) <= r)
        {
            visited[ny][nx] = 1;
            v.push_back({ny, nx});
            sum += a[ny][nx];
            dfs(ny, nx, v);
        }
    }
    return;
}

int main()
{
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    while (true)
    {
        bool flag = 0;
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0); // 포문 끝나면 visited 초기화해야함, 다시 dfs 처음부터 호출할거니깐
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] != 1)
                {
                    visited[i][i] = 1;
                    v.clear();
                    v.push_back({i, j});
                    sum = a[i][j];
                    if (v.size() == 1)
                        continue;
                    dfs(i, j, v);
                    for (pair<int, int> b : v)
                    { // dfs 한번 호출하면 connected component 찾아지고, 이 결과로 a를 수정, 즉 인구이동 시키고 결과를 a에 반영
                        a[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }
        }
        if (!flag)
            break;
        cnt++;
    }

    cout << cnt << "\n";
    return 0;
}

// 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라는 조건에 부합하는
// connected component 찾는 문제
// 바로 dfs 임을 직감해야 함
// dfs 한번 호출하면 connected component 찾아지고, 이 결과로 a를 수정, 즉 인구이동 시키고 결과를 a에 반영
// 더이상 조건에 부합하지 않을때까지 connected component 찾으러 dfs 호출하고
// 결국 dfs 호출한 횟수가 인구이동이 발생한 몇일인셈
