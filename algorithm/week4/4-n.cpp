// 문제
// 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 A와 B가 주어진다. (0 < A,B < 1010000)

// 출력
// 첫째 줄에 A+B를 출력한다.

// 예제 입력 1 
// 9223372036854775807 9223372036854775808
// 예제 출력 1 
// 18446744073709551615


#include<bits/stdc++.h>
using namespace std;

int sum;
string a, b, ret;

string addStr(string a, string b) {

    sum = 0;
    while(a.size() || b.size() || sum) {
        if (a.size()) {
            sum += a.back() - '0';
            a.pop_back();
        }

        if (b.size()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        
        ret += (sum % 10) + '0';
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());        // ret는 더한 숫자-문자가 뒤에 붙기 때문에 리버스 해줘야함
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;

    cout << addStr(a, b) << "\n";
    return 0;
}

// int, long long 으로 해결안되는 커다란 숫자를 더하는 방법
// 자바를 쓰면 bigInt 를 쓰겠지만 여기서는 문자열 더하기 방법 사용
// 숫자로된 문자열 두개를 뒤에서부터 더해서 각 자리의 수를 
// 문자로 더해 문자을 ret를 만들어 이를 리버스 해줌