//https://www.acmicpc.net/source/share/fe8da028da1d44b59514bc4b8231fce8

// 문제
// 해커 김지민은 잘 알려진 어느 회사를 해킹하려고 한다. 이 회사는 N개의 컴퓨터로 이루어져 있다. 
// 김지민은 귀찮기 때문에, 한 번의 해킹으로 여러 개의 컴퓨터를 해킹 할 수 있는 컴퓨터를 해킹하려고 한다.
// 이 회사의 컴퓨터는 신뢰하는 관계와, 신뢰하지 않는 관계로 이루어져 있는데, A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다.
// 이 회사의 컴퓨터의 신뢰하는 관계가 주어졌을 때, 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에, N과 M이 들어온다. N은 10,000보다 작거나 같은 자연수, M은 100,000보다 작거나 같은 자연수이다. 
// 둘째 줄부터 M개의 줄에 신뢰하는 관계가 A B와 같은 형식으로 들어오며, 
// "A가 B를 신뢰한다"를 의미한다. 컴퓨터는 1번부터 N번까지 번호가 하나씩 매겨져 있다.

// 출력
// 첫째 줄에, 김지민이 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 오름차순으로 출력한다.

// 예제 입력 1      예제 출력 1
// 5 4              1 2
// 3 1
// 3 2
// 4 3
// 5 3


#include<bits/stdc++.h>
using namespace std;


int m, n, a, b, visited[10004], ret, dp[10004], mx;
vector<int> v[10004];


int dfs(int here) {
    visited[here] = 1;
    ret = 1;
    for(int there: v[here]) {
        if (visited[there] == 1) continue;
        ret += dfs(there);
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    while(m--) {
        cin >> a >> b;
        v[b].push_back(a);
        
    }

    for(int i=1; i<=n; i++) {                    // 1번 컴퓨터부터 dfs 로 체크
        memset(visited, 0, sizeof(visited));    // dfs를 이전에 한번 했다면 초기화
        dp[i] = dfs(i);
        mx = max(dp[i], mx);
        
    }

    for(int i=1; i<=n; i++) {           // 가장 많이 연결되어 있는 컴퓨터 i번 출력
        if (mx == dp[i]) {
            cout << i << "\n";
        }
    }
    return 0;
}


// 이 문제는 컴퓨터 사이의 연결이 가장 많이 되어 있는 컴퓨터 번호를 출력하는 문제
// dfs로 연결 갯수 체크 하면서 맥스값 최신화 해서 출력