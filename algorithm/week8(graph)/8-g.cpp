// 문제
// 6개의 문자 ‘(’, ‘)’, ‘{’, ‘}’, ‘[’, ‘]’ 로 이루어진 올바른 괄호 문자열 W에 대하여 정수의 ‘괄호값’을 지정하는 함수 val(W)가 정의되어 있다. 먼저 올바른 괄호 문자열부터 정의해보자.
// 한 쌍의 괄호로 구성된 길이 2인 문자열, 즉 ‘()’, ‘[]’, ‘{}’은 모두 올바른 괄호 문자열이다. 이것을 단위 괄호라고 한다. 
// X, Y가 올바른 괄호 문자열인 경우, 아래와 같은 작업을 통하여 만들어지는 새로운 문자열은 모두 올바른 괄호 문자열이 된다.

// XY // 올바른 두 괄호 문자열의 접합(concatenation).
// (X), {X}, [X] // 올바른 괄호 문자열 전체를 다시 괄호로 감쌈.
// 올바른 괄호 문자열과 아닌 예가 다음에 있다. 단 괄호 문자 사이에 공백은 없다.

// 올바른 예: ({}{}[(())]), (()), {}[][(())]
// 올바르지 못한 예: {[(())], (([)])), {{{}}(), )]{}

// 이제 괄호값 val()의 계산 방법을 설명한다. 3 종류의 단위 괄호 (), {}, []의 괄호값은 각각 1, 2, 3으로 정의되어 있다. 
// 즉 문자열이 X=‘()’, Y=‘{}’, Z=‘[]’이면 val(X) = 1, val(Y) = 2, val(Z) = 3이다. 
// 만일 X, Y가 올바른 문자열이라고 할 때 이 둘을 순차적으로 연결한 문자열 Z=XY의 괄호값은 다음과 같이 계산된다.
// val(Z) = val(X) + val(Y)
// 만일 어떤 올바른 문자열 X가 A=‘(X)’, B=‘{X}’, C=‘[X]’와 같이 (), {}, []로 둘러싸여 있을 경우에 A, B, C의 괄호값은 다음과 같이 계산된다.
// val(A) = 2·val(X), val(B) = 3·val(X), val(C) = 5·val(X)
// 그런데 괄호값이 k인 문자열은 유일하지 않다. 예를 들어 ‘[]’, ‘{}()’, ‘()()()’ 모두는 괄호값이 3을 가지는 문자열이다. 

//다음 표는 올바른 괄호 문자열에 대응하는 괄호값 val(X)의 예를 보여준다.
// 올바른 괄호 문자열 X	    val(X)
// (()())	            2(1+1) = 4
// [[[]]]	            3×5×5 = 75
// [][][]{()}	        3+3+3+3(1) = 12
// ((())[{}])()	        2(2+5×2)+1 = 25

// 올바른 괄호 문자열 X를 숫자로도 표현할 수 있다. 괄호 문자열을 숫자로 바꾸는 방법은 각 괄호 문자에 대하여 아래 표와 같이 1에서 6까지의 숫자로 대치해 십진수로 읽은 값이다.

// 문자	    (	)	{	}	[	]
// 대치문자	 1	 2	 3	 4	 5	 6

// 괄호 문자열 X를 위에 설명한 방식으로 변환시킨 값을 dmap(X)로 표시한다. 몇몇 올바른 괄호 문자열 X에 대해서 dmap(X)을 나타낸 표가 아래에 있다.

// val(R)=3 문자열	    dmap(R)
// ()()()	          121212
// {}()	              3412
// (){}	              1234
// []	              56

// val(R)=4 문자열	   dmap(R)
// ({})	             1342
// ()()()()	         12121212
// ()[]	             1256
// {}{}	             3434

// 여러분은 주어진 정수 N에 대하여 val(X) = N을 만족하는 올바른 괄호 문자열 중에서 dmap(X) 값이 최소인 X를 찾아서 출력해야 한다. 출력 문자열은 공백 없이 괄호 문자로만 구성되어야 한다.

// 입력
// 첫 번째 줄에 테스트케이스의 개수 T가 주어진다. (1 ≤ T ≤ 100) 두 번째 줄부터 T+1번째 줄까지 한 줄에 하나씩 정수 N이 주어진다. (5 ≤ N ≤ 1,000)

// 출력
// 각 테스트케이스마다 val(X) = N을 만족하는 올바른 괄호 문자열 X 중에서 dmap(X)가 최소인 문자열을 찾아서 한 줄에 하나씩 공백 없이 출력한다.


#include <bits/stdc++.h>
using namespace std;

int t, n;
string dp[1004];
map<char, char> _map; 

bool check(string a, string b) {
    if (a == "" && b == "") return false; // 두 문자열 모두 빈 문자열인 경우
    if (a == "") return true;             // a 빈문자열이면 해당 dp에 b를 넣어줌
    if (a.size() > b.size()) return true;
    else if (a.size() < b.size()) return false;
    return a > b;
}

int main() {
    _map['1'] = '(';
    _map['2'] = ')';
    _map['3'] = '{'; 
	_map['4'] = '}'; 
	_map['5'] = '[';  
	_map['6'] = ']'; 
    
    dp[1] = '12';
    dp[2] = '34';
    dp[3] = '56';
    for (int i=1; i<=n; i++) {
        if (i%2 == 0 && check(dp[i], '1'+dp[i/2]+'2')) dp[i] = '1'+dp[i/2]+'2';     // 괄호를 한번 더 씌우기, '()' 씌우면 2를 곱해야 함,
        if (i%3 == 0 && check(dp[i], '3'+dp[i/3]+'4')) dp[i] = '3'+dp[i/3]+'4';     // 
        if (i%5 == 0 && check(dp[i], '5'+dp[i/5]+'6')) dp[i] = '5'+dp[i/5]+'6'; 
        for (int j=1; j<i; j++) {                                                   // 괄호 옆에 붙이기
            if (check(dp[i], dp[j]+dp[i-j])) dp[i] = dp[j]+dp[i-j];
        }
    }
    cin >> t;
    while(t--) {
        cin >> n;
        for(char c: dp[n]) cout << _map[c];
        cout << "\n";
    }
    return 0;
}


// 디피 문제
// 이런문제는 점화식을 직접 만들어봐야 함
// dp[n]은 val(x)=n을 만족하는 괄호문자열에 대응하는 숫자 문자열임
// 이미 알고 있는 세개의 값, dp[1] = '()', dp[2] = '{}', dp[3] = '[]'
// 으로부터 디피 완성

// 예를 들어 dp[4]를 생각해보자
// val(R)=4 문자열	   dmap(R)
// ({})	             1342           dp[4] = '1' + dp[2] + '2'
// ()()()()	         12121212       위의 식에서는 안나오는 괄호
// ()[]	             1256           dp[4] = dp[1] + dp[3]
// {}{}	             3434           dp[4] = dp[2] + dp[2]

// val(x)=n 을 만드는 방법은 두가지 뿐
// 괄호를 옆에 더하거나, '1'+dp[i/2]+'2'
// 괄호를 바깥에 씌우기, dp[j]+dp[i-j]
// 이 둘을 체크하면서 디피 완성

// 숫자로된 문자열 비교