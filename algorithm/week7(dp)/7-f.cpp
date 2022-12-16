// 문제
// 정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

// X가 3으로 나누어 떨어지면, 3으로 나눈다.
// X가 2로 나누어 떨어지면, 2로 나눈다.
// 1을 뺀다.
// 정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

// 입력
// 첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 자연수 N이 주어진다.

// 출력
// 첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.
// 둘째 줄에는 N을 1로 만드는 방법에 포함되어 있는 수를 공백으로 구분해서 순서대로 출력한다. 정답이 여러 가지인 경우에는 아무거나 출력한다.


#include <bits/stdc++.h>
using namespace std;

int INF=987654321, n, dp[1000004];

void go(int here) {
    if (here == 0) return;
    printf("%d", here);
    if (here%3==0 && dp[here]==dp[here/3]+1) go(here/3);
    else if (here%2==0 && dp[here]==dp[here/2]+1) go(here/2);
    else if (here-1>=0 && dp[here]==dp[here-1]+1) go(here-1);
    return;
}

int main () {
    scanf("%d", &n);
    
    fill(dp, dp+1000004, INF);
    dp[1]=0;
    for (int i=1; i<=n; i++) {                      // 바텀업으로 dp 를 채워놓는다
        if (!(i%3)) dp[i] = min(dp[i/3]+1, dp[i]);
        if (!(i%2)) dp[i] = min(dp[i/2]+1, dp[i]);
        dp[i] = min(dp[i-1]+1, dp[i]);
    }

    printf("%d", dp[n]);    // 최소한의 횟수
    go(n);                  // trace
    return 0;
}



// 먼제 세가지 경우에 대하여 dp를 채운다
// dp[i] = count, i라는 수가 1이되기까지 행하는 연산의 횟수가 count
// dp[i] == dp[i/3]+1 이면, dp[i]가 최소의 값이 저장되어 있다는 뜻
// dp[n]을 구하고
// go 함수로 trace를 구한다