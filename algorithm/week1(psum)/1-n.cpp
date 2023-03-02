// *
// https://www.acmicpc.net/source/share/99fefc62907d4df7bdb601f8c44fc615

// 문제
// 자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.

// 출력
// 첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c;

ll go(ll a, ll b) {
   if (b == 1) return a % c;    // 기저사례

   ll ret = go(a, b/2);         // A를 B번 곱한 수는 A를 B/2번 곱한것을 두번 곱한 것과 같음
   ret = (ret * ret) % c;       // // (ret * ret) % c, 이 값은 (ret%c* ret%c) % c 와 같음

   if (b%2) ret = (ret * a) % c;   // b가 홀수면 한번 더 곱하는게 남으니까
   return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;

    cout << go(a, b) << "\n";
    return 0;
}


// 이 문제는 재귀를 이용해서 푼다
// A를 B번 곱한 수는 A를 B/2번 곱한것을 두번 곱한 것과 같음
// (ret * ret) % c, 이 값은 (ret%c* ret%c) % c 와 같음
// 알고리즘교안 63p, 3.[(a mod n)*(b mod n)]mod n=(a*b)mod n