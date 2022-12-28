// 문제
// 세준이는 어떤 문자열을 팰린드롬으로 분할하려고 한다. 예를 들어, ABACABA를 팰린드롬으로 분할하면, 
// {A, B, A, C, A, B, A}, {A, BACAB, A}, {ABA, C, ABA}, {ABACABA}등이 있다.

// 분할의 개수의 최솟값을 출력하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 문자열이 주어진다. 이 문자열은 알파벳 대문자로만 이루어져 있고, 최대 길이는 2,500이다.

// 출력
// 첫째 줄에 팰린드롬 분할의 개수의 최솟값을 출력한다.


#include <bits/stdc++.h>
using namespace std;

int const INF = 987654321;
string s;
int dp[2504][2504], dp2[2504];


int go (int here) {
    if (here == s.size()) return 0;
    if (dp2[here]!=INF) return dp2[here];

    int &ret = dp2[here];
    for (int _s=1; _s<=s.size()-here; _s++) {               // 문제의 예시 중에 {A, BACAB, A} 이런 펠린드롬을 잡아내기 위해
        if (dp[here][_s]) ret = min(ret, go(here+_s)+1);    // 사이즈 _s만큼 건너뛰면서 재귀적으로 호출, dp[here][_s] 이 조건에 걸렸으면 펠린드롬이므로 +1
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for (int i=0; i<s.size(); i++) dp[i][1] = 1;
    for (int i=0; i<s.size()-1; i++) {
        if (s[i]==s[i+1]) dp[i][2] = 1;
    }
    for (int _s=3; _s<=s.size(); _s++) {
        for (int i=0; i<=s.size()-_s; i++) {
            if (s[i]==s[i+_s-1] && dp[i+1][_s-2]) dp[i][_s] = 1;        // 문제의 예시 중에 {A, BACAB, A} 이런 펠린드롬을 잡아내려면 i++ 해주면서 체크해야함
        }
    }

    cout << go(0) << "\n";
    return 0;
}



// 두개의 dp가 필요
// 펠린드롬 dp 와 카운트를 세는 dp2