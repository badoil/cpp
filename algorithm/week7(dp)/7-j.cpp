// 문제
// 이 문제는 아주 평범한 배낭에 관한 문제이다.
// 한 달 후면 국가의 부름을 받게 되는 준서는 여행을 가려고 한다. 세상과의 단절을 슬퍼하며 최대한 즐기기 위한 여행이기 때문에, 가지고 다닐 배낭 또한 최대한 가치 있게 싸려고 한다.
// 준서가 여행에 필요하다고 생각하는 N개의 물건이 있다. 각 물건은 무게 W와 가치 V를 가지는데, 해당 물건을 배낭에 넣어서 가면 준서가 V만큼 즐길 수 있다. 
// 아직 행군을 해본 적이 없는 준서는 최대 K만큼의 무게만을 넣을 수 있는 배낭만 들고 다닐 수 있다. 준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 알려주자.

// 입력
// 첫 줄에 물품의 수 N(1 ≤ N ≤ 100)과 준서가 버틸 수 있는 무게 K(1 ≤ K ≤ 100,000)가 주어진다. 
// 두 번째 줄부터 N개의 줄에 거쳐 각 물건의 무게 W(1 ≤ W ≤ 100,000)와 해당 물건의 가치 V(0 ≤ V ≤ 1,000)가 주어진다.
// 입력으로 주어지는 모든 수는 정수이다.

// 출력
// 한 줄에 배낭에 넣을 수 있는 물건들의 가치합의 최댓값을 출력한다.


#include <bits/stdc++.h>
using namespace std;

int n, k, dp[100004], w, v;

int main () {
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &w, &v);
        for (int j=k; j>=w; j--) {          // dp 누적이 이제까지와 다르게 오른쪽에서부터 시작됨, 이유는 물건이 무한대갯수가 아니라 하나뿐이기 때문, 7-g 참고
            dp[j] = max(dp[j], dp[j-w]+v);
        }
    }

    printf("%d\n", dp[k]);
    return 0;
}


// 탑다운
// dp가 이제까지와 다르게 오른쪽에서부터 시작됨
// 그러면 누적이 되지 않고 그대로 오게됨
// 아이템(여기서는 물건)을 무한하게 쓸 수 있으면 dp가 왼쪽부터 진행해야하고
// 한번만 쓸 수 있으면 오른쪽부터 진행해야함