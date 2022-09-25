// https://www.acmicpc.net/problem/17471
// 문제
// 백준시의 시장 최백준은 지난 몇 년간 게리맨더링을 통해서 자신의 당에게 유리하게 선거구를 획정했다. 견제할 권력이 없어진 최백준은 권력을 매우 부당하게 행사했고, 
// 심지어는 시의 이름도 백준시로 변경했다. 이번 선거에서는 최대한 공평하게 선거구를 획정하려고 한다.

// 백준시는 N개의 구역으로 나누어져 있고, 구역은 1번부터 N번까지 번호가 매겨져 있다. 구역을 두 개의 선거구로 나눠야 하고, 각 구역은 두 선거구 중 하나에 포함되어야 한다. 
// 선거구는 구역을 적어도 하나 포함해야 하고, 한 선거구에 포함되어 있는 구역은 모두 연결되어 있어야 한다. 구역 A에서 인접한 구역을 통해서 구역 B로 갈 수 있을 때, 두 구역은 연결되어 있다고 한다. 
// 중간에 통하는 인접한 구역은 0개 이상이어야 하고, 모두 같은 선거구에 포함된 구역이어야 한다.

// 각 선거구는 적어도 하나의 구역을 포함해야 한다.
// 공평하게 선거구를 나누기 위해 두 선거구에 포함된 인구의 차이를 최소로 하려고 한다. 백준시의 정보가 주어졌을 때, 인구 차이의 최솟값을 구해보자.

// 입력
// 첫째 줄에 구역의 개수 N이 주어진다. 둘째 줄에 구역의 인구가 1번 구역부터 N번 구역까지 순서대로 주어진다. 인구는 공백으로 구분되어져 있다.
// 셋째 줄부터 N개의 줄에 각 구역과 인접한 구역의 정보가 주어진다. 각 정보의 첫 번째 정수는 그 구역과 인접한 구역의 수이고, 이후 인접한 구역의 번호가 주어진다. 모든 값은 정수로 구분되어져 있다.
// 구역 A가 구역 B와 인접하면 구역 B도 구역 A와 인접하다. 인접한 구역이 없을 수도 있다.

// 출력
// 첫째 줄에 백준시를 두 선거구로 나누었을 때, 두 선거구의 인구 차이의 최솟값을 출력한다. 두 선거구로 나눌 수 없는 경우에는 -1을 출력한다.

// 제한
// 2 ≤ N ≤ 10
// 1 ≤ 구역의 인구 수 ≤ 100


#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, m, temp, a[11], comp[11], visited[11], ret=INF;
vector<int> adj[11];


pair<int, int> dfs(int here, int value) {
    visited[here] = 1;
    pair<int, int> ret = {1, a[here]};
    for(int there: adj[here]) {
        if (visited[there]) continue;
        if (comp[there] != value) continue;
        pair<int, int> _temp = dfs(there, value);
        ret.first += _temp.first;
        ret.second += _temp.second;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<=n; i++) {
        cin >> a[i];
    }

    for(int i=0; i<=n; i++) {
        cin >> m;
        for(int j=0; j<0; j++) {
            cin >> temp;
            adj[i].push_back(temp);
            adj[temp].push_back(i);
        }
    }

    for(int i=0; i<=(1<<n)-1; i++) {        // 모든 경우의 수를 비트마스킹으로 나타냄
        fill(comp, comp+11, 0);
        fill(visited, visited+11, 0);
        int idx1;
        int idx2;
        for(int j=0; j<=n; j++) {
            if (i & (1<<j)) {              // 조건을 만족하면 1로 값 할당
                comp[j+1] = 1;
                idx1 = j + 1;              // dfs 시작할 인덱스
            } else idx2 = j + 1;
        }
        pair<int, int> ret1 = dfs(idx1, 1);     // 인덱스와 밸류를 달리하면 dfs 두번 호출이 포인트        
        pair<int, int> ret2 = dfs(idx2, 0);
        
        if (ret1.first + ret2.first == n) ret = min(ret, abs(ret1.second - ret2.second));       // 여러가지 connected component 경우의 수를 만들텐데, 그중 딱 두개 만드는 경우 찾기
    }

    cout << (ret==INF? -1 : ret) << "\n";
    return 0;
}


// 이 문제는 결국 connected component 구하는 문제
// 지역구를 2개로 나누는 것이기 때문에 이를 2진법으로 생각할 수 있는것
// 2진법과 경우의수 ?? -> 비트마스킹
// 비트마스킹의 장점은 경우의 수를 쉽게 조작할 수 있다는것
// 즉 지역구를 1 또는 0으로 할당하는 모든 경우의 수를 탐색하면서 그 중 2개의 connected component를 만들면서
// 두 인구 수 차이가 최소인 값을 구하는것

// 인덱스와 밸류를 달리하면 dfs 두번 호출이 포인트 