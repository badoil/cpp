// 문제
// 평소 요리에 관심이 많은 승균이는 치킨집을 개업하였다. 승균이네 치킨집은 파닭이 주메뉴다. 승균이는 가게를 오픈하기 전에 남부시장에 들러서 길이가 일정하지 않은 파를 여러 개 구매하였다. 
// 승균이는 파닭의 일정한 맛을 유지하기 위해 각각의 파닭에 같은 양의 파를 넣는다. 또 파닭 맛은 파의 양에 따라 좌우된다고 생각하기 때문에 될 수 있는 한 파의 양을 최대한 많이 넣으려고 한다. 
// (하지만 하나의 파닭에는 하나 이상의 파가 들어가면 안 된다.) 힘든 하루를 마치고 승균이는 파닭을 만들고 남은 파를 라면에 넣어 먹으려고 한다. 이때 라면에 넣을 파의 양을 구하는 프로그램을 작성하시오. 
// 승균이네 치킨집 자는 정수만 표현되기 때문에 정수의 크기로만 자를 수 있다.

// 입력
// 첫째 줄에 승균이가 시장에서 사 온 파의 개수 S(1 ≤ S ≤ 1,000,000), 그리고 주문받은 파닭의 수 C(1 ≤ C ≤ 1,000,000)가 입력된다. 
// 파의 개수는 항상 파닭의 수를 넘지 않는다. (S ≤ C) 그 후, S 줄에 걸쳐 파의 길이 L(1 ≤ L ≤ 1,000,000,000)이 정수로 입력된다.

// 출력
// 승균이가 라면에 넣을 파의 양을 출력한다


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll s, c, a[1000004], ret, sum;

bool check(ll mid) {
    int cnt = 0;
    for (int i=0; i<s; i++) cnt += a[i]/mid;
    return cnt >= c;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> c;
    for (int i=0; i<s; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int lo=0, hi=1e9;
    while(lo<=hi) {
        ll mid = lo+hi/(1ll*2);
        if (check(mid)) {       // mid 가 너무 작아서 true를 리턴했으므로 
            lo = mid + 1;       // mid를 늘려줌
            ret = mid;
        } else hi = mid - 1;
    }

    cout << sum - (ret * c) << "\n";
    return 0;
}


// 파닭에 들어갈 파의 최대 길이를 구하는 문제
// 각 파의 길이를 mid로 나눈 값을 주문한 파닭의 갯수와 비교하면서 진행