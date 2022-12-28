// 문제
// 명우는 홍준이와 함께 팰린드롬 놀이를 해보려고 한다.
// 먼저, 홍준이는 자연수 N개를 칠판에 적는다. 그 다음, 명우에게 질문을 총 M번 한다.
// 각 질문은 두 정수 S와 E(1 ≤ S ≤ E ≤ N)로 나타낼 수 있으며, S번째 수부터 E번째 까지 수가 팰린드롬을 이루는지를 물어보며, 명우는 각 질문에 대해 팰린드롬이다 또는 아니다를 말해야 한다.

// 예를 들어, 홍준이가 칠판에 적은 수가 1, 2, 1, 3, 1, 2, 1라고 하자.
// S = 1, E = 3인 경우 1, 2, 1은 팰린드롬이다.
// S = 2, E = 5인 경우 2, 1, 3, 1은 팰린드롬이 아니다.
// S = 3, E = 3인 경우 1은 팰린드롬이다.
// S = 5, E = 7인 경우 1, 2, 1은 팰린드롬이다.

// 자연수 N개와 질문 M개가 모두 주어졌을 때, 명우의 대답을 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 수열의 크기 N (1 ≤ N ≤ 2,000)이 주어진다.
// 둘째 줄에는 홍준이가 칠판에 적은 수 N개가 순서대로 주어진다. 칠판에 적은 수는 100,000보다 작거나 같은 자연수이다.
// 셋째 줄에는 홍준이가 한 질문의 개수 M (1 ≤ M ≤ 1,000,000)이 주어진다.
// 넷째 줄부터 M개의 줄에는 홍준이가 명우에게 한 질문 S와 E가 한 줄에 하나씩 주어진다.

// 출력
// 총 M개의 줄에 걸쳐 홍준이의 질문에 대한 명우의 답을 입력으로 주어진 순서에 따라서 출력한다. 팰린드롬인 경우에는 1, 아닌 경우에는 0을 출력한다.


#include <bits/stdc++.h>
using namespace std;

int n, a[2004], dp[2004][2004], m, s, e;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));
    for (int i=1; i<=n; i++) {          // 숫자가 한개일때는 펠린드롬
        dp[i][i] = 1;
    }

    for (int i=1; i<=n; i++) {                  // 숫자가 두개일때 두 숫자가 같으면 펠린드롬
        if (a[i] == a[i+1]) dp[i][i+1] = 1;
    }

    for (int s=2; s<=n; s++) {                  // 수열의 사이즈 정해서 사이즈 만큼 체크
        for (int i=1; i<=n-s; i++) {            
            if (a[i]==a[i+s] && dp[i+1][i+s-1]) dp[i][i+s] = 1;     // 수열의 양 끝이 같고, 양끝 제외한 부분수열이 펠린드롬일때 
        }
    }
    
    cin >> m;
    while(m--) {
        cin >> s >> e;
        cout << dp[s][e] << "\n";
        
    }
    return 0;
}



// 바텀업 dp 로 풀어야함
// dp[from][to], 수열 from부터 to까지가 펠린드롬인가
// 수가 한개일때는 무조건 펠린드롬
// 숫자가 두개일때 두 숫자가 같으면 펠린드롬
// 이 두 케이스부터 바텀업으로 dp 채움