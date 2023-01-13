// 문제
// 성냥개비는 숫자를 나타내기에 아주 이상적인 도구이다. 보통 십진수를 성냥개비로 표현하는 방법은 다음과 같다.

// {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, 각 인덱스가 수이고 그 수를 만드는데 필요한 성냥개비 갯수
// 0은 6개 필요, 1은 2개 필요...

// 성냥개비의 개수가 주어졌을 때, 성냥개비를 모두 사용해서 만들 수 있는 가장 작은 수와 큰 수를 찾는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스는 최대 100개 이다. 각 테스트 케이스는 한 줄로 이루어져 있고, 성냥개비의 개수 n이 주어진다. (2 ≤ n ≤ 100)

// 출력
// 각 테스트 케이스에 대해서 입력으로 주어진 성냥개비를 모두 사용해서 만들 수 있는 가장 작은 수와 가장 큰 수를 출력한다. 두 숫자는 모두 양수이어야 하고, 숫자는 0으로 시작할 수 없다. 

#include <bits/stdc++.h>
using namespace std;

int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, t, n;
string dp[104], MAX_STR = "111111111111111111111111111111111111111111111111119";


string min_str(string a, string b) {
    if (a.size() == b.size()) return a < b ? a : b;
    if (a.size() < b.size()) return a;
    return b;
}

string max_str(int a) {
    string ret = "";
    while(a) {
        if (a%2 == 1) {
            ret += "7";
            a -= 3; 
        }
        ret += "1";
        a -= 2;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    fill(dp, dp+104, MAX_STR);
    cin >> t;

    dp[0] = "";
    for (int i=2; i<104; i++) {
        for (int j=0; j<10; j++) {
            if (i-a[j] < 0) continue;
            if (j == 0 && dp[i-a[j]] == "") continue;
            dp[i] = min_str(dp[i], dp[i-a[j]]+to_string(j));    // 점화식 이해 안감
        }
    }
    while(t--) {
        cin >> n;
        cout << max_str(n) << " " << dp[n] << "\n";
    }
    return 0;

}


// dp[i], i라는 성냥개비로 만들수 있는 최소의 수
// dp[i-a[j]] + to_string(j) 