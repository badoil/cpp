// *
// 문제
// 상근이는 선영이와 걸어가다가 사탕 가게를 지나가게 되었다. 갑자기 상근이는 선영이에게 사탕이 얼마나 건강에 안 좋은지 설명하기 시작했다. 
// 선영이는 매우 짜증이 났고, 상근이에게 누가 더 건강이 안 좋아질 수 있는지 내기를 하자고 했다. 상근이는 내기를 그 즉시 받아들였다.

// 두 사람은 같은 돈을 가지고 가게에 들어가서 사탕을 산다. 이때, 구매한 사탕의 칼로리가 더 큰 사람이 내기에서 이기게 된다.
// 상근이는 잠시 화장실에 갔다온다고 핑계를 댄 뒤에, 노트북을 열고 사탕 가게의 시스템을 해킹하기 시작했다. 
// 이 시스템에는 현재 사탕 가게에 있는 사탕의 가격과 칼로리가 모두 등재되어 있다. 
// 각 사탕의 개수는 매우 많기 때문에, 원하는 만큼 사탕을 구매할 수 있다. 또, 사탕은 쪼갤 수 없기 때문에, 일부만 구매할 수 없다.
// 사탕 가게에 있는 모든 사탕의 가격과 칼로리가 주어졌을 때, 어떻게 하면 칼로리의 합이 가장 크게 되는지를 구하는 프로그램을 작성하시오.

// 입력
// 각 테스트 케이스의 첫째 줄에는 가게에 있는 사탕 종류의 수 n과 상근이가 가지고 있는 돈의 양 m이 주어진다. (1 ≤ n ≤ 5,000, 0.01 ≤ m ≤ 100.00) m은 항상 소수점 둘째자리까지 주어진다.
// 다음 n개 줄에는 각 사탕의 칼로리 c와 가격 p가 주어진다. (1 ≤ c ≤ 5,000, 0.01 ≤ p ≤ 100.00) c는 항상 정수, p는 항상 소수점 둘째자리이다.
// 입력의 마지막 줄에는 '0 0.00'이 주어진다.

// 출력
// 각 테스트 케이스에 대해서, 상근이가 돈 m을 가지고 구매할 수 있는 가장 높은 칼로리를 출력한다.


#include <bits/stdc++.h>
using namespace std;

int n, m1, m2, dp[10004], c, p;

int main () {
    while (1) {
        int n, m1, m2;
        scanf("%d %d.%d", &n, &m1, &m2);    // 소수점 표현 방법, 입력을 0.0으로 받지만 실제는 두 정수를 받는것, 플롯이나 더블은 정수로 만들어라!
        if (n == 0) break;
        fill(dp, dp+10004, -1);
        int money = m1*100 + m2;            // 받은 두 정수를 하나의 정수로 합침
        for (int i=0; i<n; i++) {
            scanf("%d %d.%d", &c, &m1, &m2);
            p = m1*100 + m2;
            for (int j=p; j<=money; j++) {
                dp[j] = max(dp[j], dp[j-p]+c);      // 포인트
            }
        }
        printf("%d", dp[money]);
    }

    return 0;
}


// 바텀업
// dp[j] = cal, j원으로 살수 있는 사탕의 최대 칼로리
// dp[j] = max(dp[j], dp[j-p]+c) 둘 중 최대로 채워나감
// dp[j-p]+c , 이제 p원을 들여서 얻을 수 있는 c칼로리 라는 의미
