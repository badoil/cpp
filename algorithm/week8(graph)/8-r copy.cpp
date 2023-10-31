// 문제
// N개의 숫자로 구분된 각각의 마을에 한 명의 학생이 살고 있다.
// 어느 날 이 N명의 학생이 X (1 ≤ X ≤ N)번 마을에 모여서 파티를 벌이기로 했다. 
// 이 마을 사이에는 총 M개의 단방향 도로들이 있고 i번째 길을 지나는데 Ti(1 ≤ Ti ≤ 100)의 시간을 소비한다.
// 각각의 학생들은 파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다. 하지만 이 학생들은 워낙 게을러서 최단 시간에 오고 가기를 원한다.
// 이 도로들은 단방향이기 때문에 아마 그들이 오고 가는 길이 다를지도 모른다. N명의 학생들 중 오고 가는데 가장 많은 시간을 소비하는 학생은 누구일지 구하여라.

// 입력
// 첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 10,000), X가 공백으로 구분되어 입력된다. 
// 두 번째 줄부터 M+1번째 줄까지 i번째 도로의 시작점, 끝점, 그리고 이 도로를 지나는데 필요한 소요시간 Ti가 들어온다. 
// 시작점과 끝점이 같은 도로는 없으며, 시작점과 한 도시 A에서 다른 도시 B로 가는 도로의 개수는 최대 1개이다.
// 모든 학생들은 집에서 X에 갈수 있고, X에서 집으로 돌아올 수 있는 데이터만 입력으로 주어진다.

// 출력
// 첫 번째 줄에 N명의 학생들 중 오고 가는데 가장 오래 걸리는 학생의 소요시간을 출력한다.

#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int n, m, x, s, e, t, dist1[1004], dist2[1004], ret;
vector<pair<int, int>> adj1[1004], adj2[1004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


void djkstra (int *dist, vector<pair<int, int>> *adj) {

    pq.push(make_pair(0, x));
    dist[x] = 0;
    while(pq.size()) {
        int here = pq.top().second;
        int dist_here = pq.top().first;
        pq.pop();
        if (dist[here] != dist_here) continue;
        for (pair<int, int> there: adj[here]) {
            int next = there.first;
            int dist_there = there.second;
            if (dist[next] > dist[here] + dist_there) {
                dist[next] = dist[here] + dist_there;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
}

int mainn() {
    scanf("%d %d %d", &n, &m, &x);
    fill(dist1, dist1 + 1004, INF);
    fill(dist2, dist2 + 1004, INF);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &s, &e, &t);
        adj1[s].push_back(make_pair(t, e));     // 각 도시로 가는 시간
        adj2[e].push_back(make_pair(t, s));     // 이 반대 시간 입력
    }

    djkstra(dist1, adj1);
    djkstra(dist2, adj2);
    
    for (int i=1; i<=n; i++) {
        if (i == x) continue;
        ret = max(ret, dist1[i] + dist2[i]);
    }

    printf("%d\n", ret);
    return 0;
}




// 다익스트라 문제
// 플로이드워셜 인가 싶기도 하겠지만 도시 갯수 1000개 -> 시간초과
// 이 문제는 다시 출발 도시로 돌아오는 시간의 최대값을 구하는 문제

// x -> a 이거는 다익스트라로 구하면됨, adj1[s].push_back(make_pair(t, e)) 주어진 입력값 그대로 이용
// a -> x 이거 구하는게 문제, adj2[e].push_back(make_pair(t, s)) 주어진 입력값 거꾸로 이용
