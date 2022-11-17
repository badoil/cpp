// 문제
// 세계적인 도둑 상덕이는 보석점을 털기로 결심했다.

// 상덕이가 털 보석점에는 보석이 총 N개 있다. 각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 상덕이는 가방을 K개 가지고 있고, 
// 각 가방에 담을 수 있는 최대 무게는 Ci이다. 가방에는 최대 한 개의 보석만 넣을 수 있다.
// 상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N과 K가 주어진다. (1 ≤ N, K ≤ 300,000)
// 다음 N개 줄에는 각 보석의 정보 Mi와 Vi가 주어진다. (0 ≤ Mi, Vi ≤ 1,000,000)
// 다음 K개 줄에는 가방에 담을 수 있는 최대 무게 Ci가 주어진다. (1 ≤ Ci ≤ 100,000,000)
// 모든 숫자는 양의 정수이다.

// 출력
// 첫째 줄에 상덕이가 훔칠 수 있는 보석 가격의 합의 최댓값을 출력한다.

// 예제 입력 1     예제 출력 1 
// 2 1            10
// 5 10
// 100 100
// 11


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k, m, ret;
vector<pair<ll, ll>> v;
vector<ll> vv;
priority_queue<ll> pq;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    for (int i=0; i<k; i++) {
        cin >> vv[i];
    }
    sort(vv.begin(), vv.begin());

    int j=0;
    for (int i=0; i<k; i++) {
        while (j<n && v[j].first<=vv[i]) pq.push(v[j++].second);
        if (pq.size()) {        // 이때 pq를 완전 비워야 하지 않나??
            ret += pq.top();
            pq.pop();
        }
    }

    cout << ret << "\n";
    return 0;
}


// 보석을 무게 기준으로 오름차순 정렬
// 가방을 무게 기준으로 오름차순 정렬
// 가방의 무게 기준으로 해당하는 보석의 각격을 우선순위큐에 집어넣고
// 이때 우선순위큐는 내림차순 정렬되어 있으므로
// 맨 위 값이 제일 큰 가격이고 이를 계속 더해주면 됨