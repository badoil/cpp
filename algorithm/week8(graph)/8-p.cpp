// *
// 문제
// 오민식은 세일즈맨이다. 오민식의 회사 사장님은 오민식에게 물건을 최대한 많이 팔아서 최대 이윤을 남기라고 했다.
// 오민식은 고민에 빠졌다. 어떻게 하면 최대 이윤을 낼 수 있을까?

// 이 나라에는 N개의 도시가 있다. 도시는 0번부터 N-1번까지 번호 매겨져 있다. 오민식의 여행은 A도시에서 시작해서 B도시에서 끝난다.
// 오민식이 이용할 수 있는 교통수단은 여러 가지가 있다. 오민식은 모든 교통수단의 출발 도시와 도착 도시를 알고 있고, 비용도 알고 있다. 
// 게다가, 오민식은 각각의 도시를 방문할 때마다 벌 수 있는 돈을 알고있다. 이 값은 도시마다 다르며, 액수는 고정되어있다. 또, 도시를 방문할 때마다 그 돈을 벌게 된다.
// 오민식은 도착 도시에 도착할 때, 가지고 있는 돈의 액수를 최대로 하려고 한다. 이 최댓값을 구하는 프로그램을 작성하시오.

// 오민식이 버는 돈보다 쓰는 돈이 많다면, 도착 도시에 도착할 때 가지고 있는 돈의 액수가 음수가 될 수도 있다. 
// 또, 같은 도시를 여러 번 방문할 수 있으며, 그 도시를 방문할 때마다 돈을 벌게 된다. 모든 교통 수단은 입력으로 주어진 방향으로만 이용할 수 있으며, 여러 번 이용할 수도 있다.

// 입력
// 첫째 줄에 도시의 수 N과 시작 도시, 도착 도시 그리고 교통 수단의 개수 M이 주어진다. 
// 둘째 줄부터 M개의 줄에는 교통 수단의 정보가 주어진다. 교통 수단의 정보는 “시작 끝 가격”과 같은 형식이다. 
// 마지막 줄에는 오민식이 각 도시에서 벌 수 있는 돈의 최댓값이 0번 도시부터 차례대로 주어진다.
// N과 M은 50보다 작거나 같고, 돈의 최댓값과 교통 수단의 가격은 1,000,000보다 작거나 같은 음이 아닌 정수이다.

// 출력
// 첫째 줄에 도착 도시에 도착할 때, 가지고 있는 돈의 액수의 최댓값을 출력한다. 
// 만약 오민식이 도착 도시에 도착하는 것이 불가능할 때는 "gg"를 출력한다. 
// 그리고, 오민식이 도착 도시에 도착했을 때 돈을 무한히 많이 가지고 있을 수 있다면 "Gee"를 출력한다.


#include <bits/stdc++.h>
using namespace std;

int n, s, e, m, a, b, c, ok;
long long dist[104], cost[104], visited[104];
vector<pair<int, int>> adj[104];
queue<int> q;
const long long INF = 1LL << 60;

int main() {
    scanf("%d %d %d %d", &n, &s, &e, &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back(make_pair(b, c));
    }
    for (int i=0; i<n; i++) scanf("%lld", &cost[i]);

    fill(dist, dist+104, -INF);
    dist[s] = cost[s];                  // 도시를 이동하면서 누적된 비용을 dist로 놓음
    for (int i=0; i<n; i++) {
        for (int here=0; here<n; here++) {
            for (pair<int, int> there: adj[here]) {
                int _there = adj[here].first;
                int _cost = adj[here].second;       // 교통비
                if (dist[_there]] != -INF && dist[here] + cost[_there] - _cost > dist[_there]) {
                    dist[_there] = dist[here] + cost[_there] - _cost;
                    if (i == n-1) q.push(here);     // 마지막 인덱스에서 완화가 일어났다면 그 지점을 q에 넣어서 기억
                }
            }
            
        }
    }

    while(q.size()) {           // 싸이클 있는 부분에서 도착지점까지 갈 수 있는지 판별
        int here = q.top();
        q.pop();
        for (int there: adj[here]) {
            if (there.first == e) {
                ok = 1;
                break;
            }
            if (!visited[there]) {
                visited[there] = 1;
                q.push(there);
            }
        }
        if (ok) break;
    }

    if (ok == 1) puts("Gee");               // 싸이클이 있고 도착도시까지 간 경우 무한대 벌 수 잇음
    else if(dist[e] == -INF) puts("gg");
    else printf("%lld\n", dist[e]);
}



// 벨만포드
// 음수가중치가 있는 그래프에서 사용하는 최단거리 알고리즘입니다.  시간복잡도는 O(VE)입니다
// 여기서 음수가중치는 교통수단을 이용할때 비용
// 도시방문할때 버는 돈은 양수

// 벨만포드 알고리즘은 2중 for문으로 모든 간선을 확인해서 최단거리를 갱신하는데 보통은 V - 1까지만 돌리면 모든 거리가 완화가 일어나지만 
// V - 1 번째 이상에서 또 다시 완화가 일어났다면  그것은 음의 사이클이 있다는 것을 의미합니다

