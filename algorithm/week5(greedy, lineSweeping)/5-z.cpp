// 문제
// 매우 큰 도화지에 자를 대고 선을 그으려고 한다. 선을 그을 때에는 자의 한 점에서 다른 한 점까지 긋게 된다. 
// 선을 그을 때에는 이미 선이 있는 위치에 겹쳐서 그릴 수도 있는데, 여러 번 그은 곳과 한 번 그은 곳의 차이를 구별할 수 없다고 하자.
// 이와 같은 식으로 선을 그었을 때, 그려진 선(들)의 총 길이를 구하는 프로그램을 작성하시오. 선이 여러 번 그려진 곳은 한 번씩만 계산한다.

// 입력
// 첫째 줄에 선을 그은 횟수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 다음 N개의 줄에는 선을 그을 때 선택한 두 점의 위치 x, y(-1,000,000,000 ≤ x < y ≤ 1,000,000,000)가 주어진다.

// 출력
// 첫째 줄에 그은 선의 총 길이를 출력한다.

#include<bits/stdc++.h>
using namespace std;

int n, x, y, l, r, ret;
pair<int, int> a[1000004];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> x >> y;
        a[i] = {x, y};
    }

    sort(a, a+n);
    l = a[0].first; r = a[0].second;

    for (int i=1; i<n; i++) {
        if (a[i].first > r) {
            ret += r - l;
            l = a[i].first;
            r = a[i].second;
        } else if(a[i].first <= r && a[i].second >= r) {
            r = a[i].second;
        }
    }

    ret += r - l;   // 마지막 인덱스 값 계산해주기

    cout << ret << "\n";
    return 0;
}


// 이 문제는 카운팅 배열 이용하려고 할 수도 있지만
// 공간 메모리가 x, y(-1,000,000,000 ≤ x < y ≤ 1,000,000,000) 이므로 불가능
// 따라서 라인 스위핑 써야함
