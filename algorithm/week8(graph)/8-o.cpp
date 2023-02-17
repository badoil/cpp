// 문제
// 관악산 기슭에는 보름달을 기다리는 달빛 여우가 한 마리 살고 있다. 달빛 여우가 보름달의 달빛을 받으면 아름다운 구미호로 변신할 수 있다. 

// 하지만 보름달을 기다리는 건 달빛 여우뿐만이 아니다. 달빛을 받아서 멋진 늑대인간이 되고 싶어 하는 달빛 늑대도 한 마리 살고 있다.
// 관악산에는 1번부터 N번까지의 번호가 붙은 N개의 나무 그루터기가 있고, 그루터기들 사이에는 M개의 오솔길이 나 있다. 
// 오솔길은 어떤 방향으로든 지나갈 수 있으며, 어떤 두 그루터기 사이에 두 개 이상의 오솔길이 나 있는 경우는 없다. 달빛 여우와 달빛 늑대는 1번 나무 그루터기에서 살고 있다.
// 보름달이 뜨면 나무 그루터기들 중 하나가 달빛을 받아 밝게 빛나게 된다. 그러면 달빛 여우와 달빛 늑대는 먼저 달빛을 독차지하기 위해 최대한 빨리 오솔길을 따라서 그 그루터기로 달려가야 한다. 
// 이때 달빛 여우는 늘 일정한 속도로 달려가는 반면, 달빛 늑대는 달빛 여우보다 더 빠르게 달릴 수 있지만 체력이 부족하기 때문에 다른 전략을 사용한다. 
// 달빛 늑대는 출발할 때 오솔길 하나를 달빛 여우의 두 배의 속도로 달려가고, 
// 그 뒤로는 오솔길 하나를 달빛 여우의 절반의 속도로 걸어가며 체력을 회복하고 나서 다음 오솔길을 다시 달빛 여우의 두 배의 속도로 달려가는 것을 반복한다. 
// 달빛 여우와 달빛 늑대는 각자 가장 빠르게 달빛이 비치는 그루터기까지 다다를 수 있는 경로로 이동한다. 따라서 둘의 이동 경로가 서로 다를 수도 있다.

// 출제자는 관악산의 모든 동물을 사랑하지만, 이번에는 달빛 여우를 조금 더 사랑해 주기로 했다. 그래서 달빛 여우가 달빛 늑대보다 먼저 도착할 수 있는 그루터기에 달빛을 비춰 주려고 한다. 
// 이런 그루터기가 몇 개나 있는지 알아보자.

// 입력
// 첫 줄에 나무 그루터기의 개수와 오솔길의 개수를 의미하는 정수 N, M(2 ≤ N ≤ 4,000, 1 ≤ M ≤ 100,000)이 주어진다.
// 두 번째 줄부터 M개의 줄에 걸쳐 각 줄에 세 개의 정수 a, b, d(1 ≤ a, b ≤ N, a ≠ b, 1 ≤ d ≤ 100,000)가 주어진다. 
// 이는 a번 그루터기와 b번 그루터기 사이에 길이가 d인 오솔길이 나 있음을 의미한다.

// 출력
// 첫 줄에 달빛 여우가 달빛 늑대보다 먼저 도착할 수 있는 나무 그루터기의 개수를 출력한다.

#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
typedef pair<int, int> PI
typedef tuple<int, int, bool> TI
int n, m, a, b, d, ret, dist_fox[4004], dist_wolf[4004][2];
vector<PI> adj[4004];

void djkstra () {
    fill(dist_foxt, dist_foxt + 4004, INF);
    priority_queue<PI, vector<PI>, greater<PI>> pq;

    dist_foxt[1] = 0;
    pq.push(make_pair(0, 1));
    while(pq.size()) {
        int d = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist_foxt[here] != d) continue;
        for(PI there: adj[here]) {
            int dist_there = there.first;
            int next = there.second;
            if (dist_foxt[next] > dist_foxt[here] + dist_there) {
                dist_foxt[next] = dist_foxt[here] + dist_there;     // 최단경로 갱신 
                pq.push(make_pair(dist_foxt[next], next));
            }
        }
    }
}

void djkstra2 () {
    fill(dist_wolf[0][0], dist_wolf[0][0]+4004*2, INF);
    priority_queue<TI, vector<TI>, greater<TI>> pq;
    
    dist_wolf[1][0] = 0;
    pq.push(make_tuple(0, 1, 0));
    while(pq.size()) {
        int d, here, cnt;
        tie(d, here, cnt) = pq.top();
        pq.pop();
        if (dist_wolf[here][cnt] != d) continue;
        for (TI there: adj[here]) {
            int dist_there = !cnt ? there.first / 2 : there.first * 2;         // cnt로 2배로 빠르게 가거나 2배로 느리게 가는 것을 구분
            int next = there.second;
            if (dist_wolf[next][!cnt] > dist_wolf[here][cnt] + dist_there) {
                dist_wolf[next][!cnt] = dist_wolf[here][cnt] + dist_there;      // 최단경로 갱신
                pq.push(make_tuple(dist_wolf[next][!cnt], next, !cnt));
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &a, &b, &d);
        adj[a].push_back(make_pair(d*2, b));        // 나눠서 정수로 떨어지게 하기 위해 2 곱해줌
        adj[b].push_back(make_pair(d*2, a));
    }

    djkstra();
    djkstra2();
    
    for(int i=2; i<=n; i++) {
        int dw = min(dist_wolf[i][0], dist_wolf[i][1]);     // 실제 늑대가 지나간 경로 구함, 안간쪽은 INF
        if (dw > dist_fox[i]) ret++;                        // 여우가 더 빨리 왔으면 카운팅
    }

    printf("%d\n", ret);
}


// 다익스트라 문제
// dist_fox[4004], dist_wolf[4004][2]
// 두개의 다익스트라 알고리즘 필요
// 여우와 늑대의 최단경로 구한뒤
// 여우가 먼저 도착하는 나무그루터기 구하기