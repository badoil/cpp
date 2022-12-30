// 문제
// 세준이는 N개의 물건을 가지고 있고, 최대 C만큼의 무게를 넣을 수 있는 가방을 하나 가지고 있다.
// N개의 물건을 가방에 넣는 방법의 수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N과 C가 주어진다. N은 30보다 작거나 같은 자연수, C는 109보다 작거나 같은 음이 아닌 정수이다. 
// 둘째 줄에 물건의 무게가 주어진다. 무게도 109보다 작거나 같은 자연수이다.

// 출력
// 첫째 줄에 가방에 넣는 방법의 수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, c, a[34], ret;
vector<int> v1, v2;

void go (int begin, int end, vector<int> &v, int sum) {
    if (sum>c) return;      // 배낭 무게 넘어가면 리턴
    if (begin>end) {        // 배열 길이 넘어가면, 즉 다 순회했으면 무게를 배열에 넣어줌
        v.push_back(sum);
        return;
    }
    
    go(begin+1, end, v, sum+a[begin]);  // 현재 a[begin] 물건을 넣는 경우
    go(begin+1, end, v, sum);           // 현재 a[begin] 물건을 안넣는 경우
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    go(0, n/2-1, v1, 0);        // v1 배열 완성
    go(n/2, n-1, v2, 0);        // v2 배열 완성
    sort(v1.begin(), v1.end()); 
	sort(v2.begin(), v2.end());
    for (int a: v1) {
        if (c-a > 0) ret += ((int)(upper_bound(v2.begin(), v2.end(), c-a) - v2.begin()));   // 한 배열의 각 원소에 대해, 그 원소와 다른 배열의 원소를 합쳐서 sum을 넘지않는 가지수를 더해줌
    }

    cout << ret << "\n";
    return 0;    
}



// 이 문제는 한 배열을 반으로 나누어서
// 각 배열을 완성시킴
// 이때 배열은 물건을 넣거나 안넣거나 두가지에 대한 모든 경우의 수를 탐색한 후
// 배낭 무게를 넘지 않는 경우들의 무게를 넣어둠

// 그 후 두 배열을 소팅하고
// 한 배열의 각 원소에 대해, 그 원소와 다른 배열의 원소를 합쳐서 sum을 넘지않는 가지수를 더해줌