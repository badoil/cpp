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
    if (here == s.size()) return 0;                         // 결국 끝까지 와서 리턴하므로 go함수 호출하면 +1한 값을 가지고 올라가게됨
    if (dp2[here]!=INF) return dp2[here];

    int &ret = dp2[here];
    for (int _s=1; here + _s<=s.size(); _s++) {              // 현재문자열의 위치 here에서 문자열의 사이즈를 넘지않게 _s를 더한 수만큼만 반복문 돌림
        if (dp[here][_s]) ret = min(ret, go(here+_s)+1);    // 사이즈 _s만큼 건너뛰면서 재귀적으로 호출, dp[here][_s] 이 조건에 걸렸으면 펠린드롬이므로 +1
    }                                                       // 문제의 예시 중 {A, BACAB, A} 이런 펠린드롬을 생각해보라
    return ret;                                             // here로부터 size를 체크해서 가장 작은값, 즉 펠린드롬이 사이즈가 가장 큰 경우를 찾는것
}                                                           // here 위치를 옮기는 것은 go함수를 재귀호출하는 경우, here부터 size만큼 펠린드롬이면 here+size 다음 위치부터 체크하는 것

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for (int i=0; i<s.size(); i++) dp[i][1] = 1;                // 문자 하나는 펠린드롬
    for (int i=0; i<s.size()-1; i++) {
        if (s[i]==s[i+1]) dp[i][2] = 1;                         // 문자 두개가 같으면 펠린드롬
    }
    for (int _s=3; _s<=s.size(); _s++) {                        // _s는 문자열의 사이즈기때문에 문자열 사이즈 s.size()까지 순회
        for (int i=0; i<=s.size()-_s; i++) {                    // 위에서 전처리할때 i=0 부터 했기 때문에 여기서도 i=0에서 시작
            if (s[i]==s[i+_s-1] && dp[i+1][_s-2]) dp[i][_s] = 1;        // 문제의 예시 중에 {A, BACAB, A} 이런 펠린드롬을 잡아내려면 i++ 해주면서 체크해야함
        }                                                               // i+_s-1 해주는 이유는 _s는 사이즈라 인덱스에서 -1 해줌
    }

    fill(dp2, dp2+2504, INF);
    cout << go(0) << "\n";
    return 0;
}


// 이 문제는 어려운 dp 문제
// 두개의 dp가 필요
// 펠린드롬 dp 와 카운트를 세는 dp2

// dp[i][j] 에서 i는 문자열의 인덱스고 j는 문자열의 갯수,
// 즉 문자열의 i번째부터 j갯수(size)의 부분문자열이 펠린드롬인지 dp애 저장
// 이렇게 dp를 전처리 해줘야함

// 이제 어려운 부분이 go 함수
// 문자열에서 최대로 긴 펠린드롬을 만들어서
// 최소의 펠린드롬 분할갯수를 리턴해야함