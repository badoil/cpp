// 문제
// n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.
// 사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

// 입력
// 첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 
// 동전의 가치는 100,000보다 작거나 같은 자연수이다. 가치가 같은 동전이 여러 번 주어질 수도 있다.

// 출력
// 첫째 줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다.


#include <bits/stdc++.h>
using namespace std;

int n, k, dp[10004], temp;
const int INF=987654321;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    fill(dp, dp+10004, INF);
    dp[0] = 0;                  // 초기값 설정해줘야 바텀업으로 갈 수 있음
    for (int i=0; i<n; i++) {
        cin >> temp;
        for (int j=temp; j<=k; j++) {
            dp[j] = min(dp[j], dp[j-temp]+1);       // 이 규칙성을 발견해야함, +1 은 temp원 동전을 의미
        }
    }

    if (dp[k] == INF) cout << -1 << "\n";
    else cout << dp[k] << "\n";
    return 0;
}

// dp[i] = count, i원을 만들기 위한 최소한의 동전 개수
// 바텀업으로 dp를 채워가면서 최소 dp 값 구해나감