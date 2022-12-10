// 문제
// 외판원 순회 문제는 영어로 Traveling Salesman problem (TSP) 라고 불리는 문제로 computer science 분야에서 가장 중요하게 취급되는 문제 중 하나이다. 
// 여러 가지 변종 문제가 있으나, 여기서는 가장 일반적인 형태의 문제를 살펴보자.
// 1번부터 N번까지 번호가 매겨져 있는 도시들이 있고, 도시들 사이에는 길이 있다. (길이 없을 수도 있다) 
// 이제 한 외판원이 어느 한 도시에서 출발해 N개의 도시를 모두 거쳐 다시 원래의 도시로 돌아오는 순회 여행 경로를 계획하려고 한다. 
// 단, 한 번 갔던 도시로는 다시 갈 수 없다. (맨 마지막에 여행을 출발했던 도시로 돌아오는 것은 예외) 이런 여행 경로는 여러 가지가 있을 수 있는데, 가장 적은 비용을 들이는 여행 계획을 세우고자 한다.

// 각 도시간에 이동하는데 드는 비용은 행렬 W[i][j]형태로 주어진다. W[i][j]는 도시 i에서 도시 j로 가기 위한 비용을 나타낸다. 비용은 대칭적이지 않다. 
// 즉, W[i][j] 는 W[j][i]와 다를 수 있다. 모든 도시간의 비용은 양의 정수이다. W[i][i]는 항상 0이다. 경우에 따라서 도시 i에서 도시 j로 갈 수 없는 경우도 있으며 이럴 경우 W[i][j]=0이라고 하자.
// N과 비용 행렬이 주어졌을 때, 가장 적은 비용을 들이는 외판원의 순회 여행 경로를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 도시의 수 N이 주어진다. (2 ≤ N ≤ 16) 다음 N개의 줄에는 비용 행렬이 주어진다. 
// 각 행렬의 성분은 1,000,000 이하의 양의 정수이며, 갈 수 없는 경우는 0이 주어진다. W[i][j]는 도시 i에서 j로 가기 위한 비용을 나타낸다.
// 항상 순회할 수 있는 경우만 입력으로 주어진다.

// 출력
// 첫째 줄에 외판원의 순회에 필요한 최소 비용을 출력한다.



#include <bits/stdc++.h>
using namespace std;

int INF = 987654321;
int n, a, dist[16][16], cost[16][1<<16];

int tsp(int here, int visited) {
    if (visited == (1<<n)-1) {  // 모든 도시를 다 방문했다면
        return dist[here][0] ? dist[here][0] : INF;
    }

    int &ret = cost[here][visited];     // 참조값으로 바로 cost[here][visited] 포인팅
    if (ret != -1) return ret;
    ret = INF;
    for (int i=0; i<n; i++) {                   // i번째부터 다음 도시로 가는 최소비용 구하는 포문, 이때 here에서 i로의 비용은 밑에서 더해줘야함
        if (visited & (1<<i)) continue;         // 방문한 도시는 넘기고
        if (dist[here][i] == 0) continue;       // 방문할 방법 없므면 넘김
        ret = min(ret, tsp(i, visited | (1<<i)) + dist[here][i]);   // tsp(다음 도시, 다음도시 방문했다고 가정) + dist[here][i](here에서 i로의 비용을 더해줘야함)
    }
    return ret;
 }

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a;
            dist[i][j] = a;
        }
    }

    memset(cost, -1, sizeof(cost));
    cout << tsp(0, 1) << "\n";

    return 0;
}





// [ 문제풀이 ]

// 1) 도시의 갯수가 주어졌을 때, 임의의 한 도시에서 시작해서 모든 도시를 거쳐서 다시 시작 도시로 돌아올 때 드는

//    최소비용을 구해야 하는 문제이다.

//    단순하게 완전탐색으로 문제에 접근하게 될 경우, 모든 도시를 줄을 세워서 최소비용을 구하는 방법이 있는데, 이 경우

//    최악의 경우 16! 만큼의 연산을 필요로 하기 때문에, 시간내에 문제를 해결할 수 없다.

//    따라서 본인은 메모이제이션과 비트마스크를 이용해서 구현하였다.

//    여기서 비트마스크를 이용한 이유는 '상태를 저장하기 위함' 이다. '상태'라는 것은 어느 도시를 거쳤는지를 나타내는

//    것이다. 예를 들어서 0번 ~ 4번 까지 총 5개의 도시가 있다고 가정해보자.

//    이 때, 0번 도시를 거쳤다 라는 것은 비트마스크로 00001 로 표현할 수가 있다.

//    이 후, 1번 도시를 거치게 된다면 이는 00011 로 표현할 수가 있다. 이 후에 예를 들어 4번 도시를 거쳤다 라고 가정하면

//    10011로 표현을 할 수가 있다. 이 처럼, "현재까지 어느 도시들을 거쳤는지 판단"을 비트마스크로 해 주었다.

//    결과적으로 모든 도시를 다 방문하게 되면 비트가 '11111'로 표현될 것이다.

//    이 값은 (1 << N) - 1 로 나타낼 수 있다. 위의 예시를 그대로 가져와서 설명해보면, 5개의 도시가 있고, 모든 도시를

//    다 방문하게 되면 '11111'로 나타낼 수 있다고 했다. '11111'은 십진수로 31인데, 이 값은 (1 << N = 32) - 1 한 값과

//    동일하기 때문에, 모든 도시를 다 방문했다 라는 것은 비트의 상태가 (1 << N) - 1 한 값과 동일하다는 것을 의미한다.



// 2) 본인은 이 문제를 DFS + DP로 구현해 보았는데, 이를 위해 사용한 변수가 있다.

//    바로, Cost[][] 라는 2차원 int형 배열이다. Cost[a][b] 에서, a = 현재 정점 을 의미하고, b = 현재의 상태 를

//    의미한다.

//    예를 들어서 Cost[1][00010] = c 라면, 이는 "현재 1번 정점이고, 현재 방문 상태는 1번 도시 한 개만 방문을 한 상태일 때,

//    지금까지 든 비용의 최소비용은 c원입니다" 를 의미한다.

//    즉, 각 정점에서 나올 수 있는 모든 상태의 비용들을 비교해가면서 가장 최소 비용을 찾는 것이다.

//    따라서, 본인은 DFS 함수의 매개변수에 ( 현재정점 , 현재 방문한 도시의 상태를 나타내는 비트 ) 이렇게 2개의 매개변수

//    를 호출해 주었다.

 

//    또한, DFS함수를 가장 초기에 호출할 때 ,모든 정점에서 호출할 필요가 없다. 단순히 0번 정점에서 한번만 호출을 하더라도

//    정답을 구할 수가 있다.

//    그 이유는 다음과 같은 상황을 보자.

//    예를 들어서 0 ~ 4번 총 5개의 도시가 존재하고, 이 도시를 순회하는 최소 비용이 드는 루트가

//    0 → 1 → 2 → 3 → 4 → 0 이라고 가정해보자. 이 때, 'A원' 이라는 비용이 들었다고 가정해보면,

//    2 → 3 → 4 → 0 → 1 → 2 의 최소비용은 얼마일까? 당연히 'A원' 일 것이다.

//    그럼, "0번 정점에서 시작한다고 하더라도, 만약 0번 정점으로 돌아올 수 있는 노드가 없다면 ?? 그럼 다른 노드부터

//    시작해야되는게 맞지 않을까?" 라고 생각할 수 있지만, 0번 정점으로 들어가는 노드가 없다면 아마 모든 도시를

//    순회할 수 없을 것이다. 왜냐하면 0번 노드로 갈 수 없기 때문이다.

//    즉 ! DFS를 모든 정점이 아닌, 하나의 정점에서만 호출하더라도 정답을 구할 수가 있다.