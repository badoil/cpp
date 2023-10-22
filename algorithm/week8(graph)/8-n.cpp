// https://www.acmicpc.net/problem/5719
// 문제
// 요즘 많은 자동차에서는 GPS 네비게이션 장비가 설치되어 있다. 네비게이션은 사용자가 입력한 출발점과 도착점 사이의 최단 경로를 검색해 준다. 
// 하지만, 교통 상황을 고려하지 않고 최단 경로를 검색하는 경우에는 극심한 교통 정체를 경험할 수 있다.
// 상근이는 오직 자기 자신만 사용 가능한 네비게이션을 만들고 있다. 이 네비게이션은 절대로 최단 경로를 찾아주지 않는다. 항상 거의 최단 경로를 찾아준다.
// 거의 최단 경로란 최단 경로에 포함되지 않는 도로로만 이루어진 경로 중 가장 짧은 것을 말한다. 

// 예를 들어, 도로 지도가 아래와 같을 때를 생각해보자. 원은 장소를 의미하고, 선은 단방향 도로를 나타낸다. 
// 시작점은 S, 도착점은 D로 표시되어 있다. 굵은 선은 최단 경로를 나타낸다. (아래 그림에 최단 경로는 두 개가 있다)거의 최단 경로는 점선으로 표시된 경로이다. 
// 이 경로는 최단 경로에 포함되지 않은 도로로 이루어진 경로 중 가장 짧은 경로이다. 거의 최단 경로는 여러 개 존재할 수도 있다. 
// 예를 들어, 아래 그림의 길이가 3인 도로의 길이가 1이라면, 거의 최단 경로는 두 개가 된다. 또, 거의 최단 경로가 없는 경우도 있다.


// 입력
// 입력은 여러 개의 테스트 케이스로 이루어져 있다. 
// 각 테스트 케이스의 첫째 줄에는 장소의 수 N (2 ≤ N ≤ 500)과 도로의 수 M (1 ≤ M ≤ 104)가 주어진다. 장소는 0부터 N-1번까지 번호가 매겨져 있다. 
// 둘째 줄에는 시작점 S와 도착점 D가 주어진다. (S ≠ D; 0 ≤ S, D < N) 
// 다음 M개 줄에는 도로의 정보 U, V, P가 주어진다. (U ≠ V ; 0 ≤ U, V < N; 1 ≤ P ≤ 103) 이 뜻은 U에서 V로 가는 도로의 길이가 P라는 뜻이다. 
// U에서 V로 가는 도로는 최대 한 개이다. 또, U에서 V로 가는 도로와 V에서 U로 가는 도로는 다른 도로이다. 
// 입력의 마지막 줄에는 0이 두 개 주어진다.

// 출력
// 각 테스트 케이스에 대해서, 거의 최단 경로의 길이를 출력한다. 만약, 거의 최단 경로가 없는 경우에는 -1을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int n, m, s, d, u, v, p, a[504][504], dist[504];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
const int INF = 987654321; 

void djstra() {
    fill(dist, dist+504, INF);
    pq.push(make_pair(0, s));
    dist[s] = 0;
    while(pq.size()) {
        int dist_here = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist_here != dist[here]) continue;
        for (int i=0; i<n; i++) {
            if (a[here][i] == -1) continue;     // eraseEdges 한번 적용후 최단경로 제외
            if (dist[i] > a[here][i] + dist[here]) {    // 여기까지의 최단경로에서 다음 i까지 거리가, dist[i]보다 작으면 최신화 시켜줌
                dist[i] = a[here][i] + dist[here];
                pq.push(make_pair(dist[i], i));
        }
    }
}

void eraseEdges() {
    queue<int> q;
    q.push(d);      // 목적지 d를 넣어줌, 즉 목적지에서 시작점으로 거꾸로 가면서 최단경로를 -1로 표시해주기 위함
    while(q.size()) {
        int a = q.front();
        q.pop();
        for (int i=0; i<n; i++) {
            if (dist[a] == dist[i] + a[i][a] && a[i][a] != -1) {
                a[i][a] = -1;       // 최단경로 -1로 표시
                q.push(i);
            }
        }
    }
}

int main() {
    while(true) {
        scanf("%d%d", &n, &m);
        if (n==0 && m==0) break;
        scanf("%d%d", &s, &d);
        memset(a, -1, sizeof(a));
        for (int i=0; i<m; i++) {
            scanf("%d%d%d", &u, &v, &p);
            a[u][v] = p;
        }
        
        djstra();
        eraseEdges();
        djstra();

        printf("%d\n", dist[d] == INF ? -1 : dist[d]);
    }

    return 0;
}


// 가중치가 있는 최단경로, 다익스트라
// 최단경로를 제외한 경로중 최단거리를 구하는 문제
// 다익스트라 한번 적용하고 그 다음에 dist[a] == dist[i] + a[i][a] 경로를 제외
// 즉 최단경로를 제외하는 eraseEdges 한번 돌리고
// 다시 다익스트라 적용