// 문제
// 현우는 용돈을 효율적으로 활용하기 위해 계획을 짜기로 하였다. 현우는 앞으로 N일 동안 자신이 사용할 금액을 계산하였고, 
// 돈을 펑펑 쓰지 않기 위해 정확히 M번만 통장에서 돈을 빼서 쓰기로 하였다. 현우는 통장에서 K원을 인출하며, 통장에서 뺀 돈으로 하루를 보낼 수 있으면 그대로 사용하고, 
// 모자라게 되면 남은 금액은 통장에 집어넣고 다시 K원을 인출한다. 다만 현우는 M이라는 숫자를 좋아하기 때문에, 
// 정확히 M번을 맞추기 위해서 남은 금액이 그날 사용할 금액보다 많더라도 남은 금액은 통장에 집어넣고 다시 K원을 인출할 수 있다. 
// 현우는 돈을 아끼기 위해 인출 금액 K를 최소화하기로 하였다. 현우가 필요한 최소 금액 K를 계산하는 프로그램을 작성하시오.

// 입력
// 1번째 줄에는 N과 M이 공백으로 주어진다. (1 ≤ N ≤ 100,000, 1 ≤ M ≤ N)
// 2번째 줄부터 총 N개의 줄에는 현우가 i번째 날에 이용할 금액이 주어진다. (1 ≤ 금액 ≤ 10000)

// 출력
// 첫 번째 줄에 현우가 통장에서 인출해야 할 최소 금액 K를 출력한다.


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, a[100004], ret, mx;

bool check(ll mid) {

    ll temp = mid;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (mid >= a[i]) {
            mid -= a[i];
        } else {            
            mid = temp;         // 남은 돈이 쓸돈보다 적기에 통자에서 인출
            cnt++;
            if (a[i] > mid) {   // 인출 후에도 적으면 리턴
                return false;
            } else mid -= a[i];
        }
    }

    return m >= cnt;
}

int main () {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int lo = 0, hi = mx;
    while(lo <= hi) {
        ll mid = (lo+hi)/2;
        if (check(mid)) {
            hi = mid - 1;
            ret = mid;
        } else lo = mid + 1;
    }

    cout << ret << "n";
    return 0;
}


// 이분탐색 문제
// 문제가 헷갈릴수 있음
// 통장에 돈이 얼마 있다는 말은 없으므로 남은 금액을 다시 통장에 넣는다라는 말은 무시해라
// '정확히 M번을 맞추기 위해서 남은 금액이 그날 사용할 금액보다 많더라도 남은 금액은 통장에 집어넣고 다시 K원을 인출'
// 이런말도 무시해라
// 체크 함수의 return m >= cnt; 만 만족하는 mid 이면 됨