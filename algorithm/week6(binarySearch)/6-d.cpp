// 문제
// 심해에는 두 종류의 생명체 A와 B가 존재한다. A는 B를 먹는다. A는 자기보다 크기가 작은 먹이만 먹을 수 있다. 예를 들어, A의 크기가 {8, 1, 7, 3, 1}이고, 
// B의 크기가 {3, 6, 1}인 경우에 A가 B를 먹을 수 있는 쌍의 개수는 7가지가 있다. 8-3, 8-6, 8-1, 7-3, 7-6, 7-1, 3-1.

// 두 생명체 A와 B의 크기가 주어졌을 때, A의 크기가 B보다 큰 쌍이 몇 개나 있는지 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 
// 각 테스트 케이스의 첫째 줄에는 A의 수 N과 B의 수 M이 주어진다. 
// 둘째 줄에는 A의 크기가 모두 주어지며, 
// 셋째 줄에는 B의 크기가 모두 주어진다. 크기는 양의 정수이다. (1 ≤ N, M ≤ 20,000) 

// 출력
// 각 테스트 케이스마다, A가 B보다 큰 쌍의 개수를 출력한다.


#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        int ret = 0;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<m; i++) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i=0; i<n; i++) {
            auto pos = lower_bound(b.begin(), b.end(), a[i]);       // a[i] 보다 작은 수들 중에 제일 큰 수가 있는 위치 반환
            ret += (int)(pos - b.begin());                          // 인덱스 빼줘서 몇개 있는지 카운트
        }
        cout << ret << "\n";
    }

    return 0;
}


// 로워바운드 사용함
