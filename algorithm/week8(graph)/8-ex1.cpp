// 최단경로
// 문제
// 방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.

// 입력
// 첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1 ≤ V ≤ 20,000, 1 ≤ E ≤ 300,000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다. 
// 둘째 줄에는 시작 정점의 번호 K(1 ≤ K ≤ V)가 주어진다. 
// 셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다. 
// 이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. u와 v는 서로 다르며 w는 10 이하의 자연수이다. 
// 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.

// 출력
// 첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다. 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.

#include <bits/stdc++.h>
using namespace std;

int V, E, K, u, v, w;
const int INF = 987654321;
int dist[20004];
vector<pair<int, int>> adj[20001]; 
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main () {
    scanf("%d %d %d", &V, &E, &K);
    fill(dist, dist+20004, INF);
    for (int i=1; i<=E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(make_pair(w, v));
    }

    pq.push(make_pair(0, K));
    dist[K] = 0;
    while(pq.size()) {
        int here = pq.top().second;
        int here_dist = pq.top().first;
        pq.pop();

        if(dist[here] != here_dist) continue;   // 위에서 dist를 INF로 초기화시켰기에, 이 둘이 다르다는것은 아직 갱신 안됨을 의미함 그래서 continue
        for (pair<int, int> there: adj[here]) {
            int _there = there.second;
            int _there_dist = there.first;
            if (dist[_there] > dist[here] + _there_dist) {
                dist[_there] = dist[here] + _there_dist;
                pq.push(make_pair(dist[_there], _there));
            }
        }
    }

    for (int i=1; i<=V; i++) {
        if (dist[i] == INF) puts("INF");
        else printf("%d\n", dist[i]);
    }
    return 0;
}


// 위의 코드는 다익스트라의 정석 코드