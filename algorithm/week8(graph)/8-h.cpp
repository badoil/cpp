// 문제
// 메시는 축구 선수이다. 메시는 기분이 좋다.

// messi(1): Messi
// messi(2)​​: Messi Gimossi
// messi(3)​​​​​​: Messi Gimossi Messi
// messi(4): Messi Gimossi Messi Messi Gimossi
// messi(5): Messi Gimossi Messi Messi Gimossi Messi Gimossi Messi

// 메시의 외침은 피보나치 수열과 유사하게 정의된다. messi(N)은 messi(N-1), 공백, messi(N-2)을 차례로 이어붙여서 만든 문자열이다.
// 욱제는 N이 충분히 클 때, messi(N)의 M번째 글자가 뭔지 궁금해졌다.

// 입력
// 정수 M이 주어진다. (1 ≤ M ≤ 230-1)

// 출력
// N이 충분히 클 때, messi(N)의 M번째 글자가 공백(' ')이 아닐 경우에는 그 글자를 출력한다.
// M번째 글자가 공백(' ')일 경우에는 Messi Messi Gimossi를 출력한다.
// 정답은 대소문자를 구분하므로 출력에 주의한다.

#include <bits/stdc++.h>
using namespace std;

int const maxN = 39;
int f[maxN] = {0, 5, 13}, m;
string s = "Messi Gimossi";

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m; m--;
    for (int i=3; i<=maxN; i++) {
        f[i] = f[i-1] + f[i-2] + 1;
    }

    for (int i=maxN; i<=2; i--) {           // 이게 포인트
        if (m >= f[i]) m -= (f[i] + 1);     // m이 f[i] 보다 크면 빼버리고 이를 반복하면 m 이 12 이하로 만들어짐
    }
    
    if (m == -1 || m == 5) cout << "Messi Messi Gimossi" << "\n";
    else cout << s[m] << "\n";
    return 0;
}


// 만약 문자를 다 저장하면서 가면 공간복잡도 초과 나올것
// 글자 수를 저장해서 m번째 글자를 구하자
// m을 s의 최대 인덱스 이하로 만드는 것이 포인트