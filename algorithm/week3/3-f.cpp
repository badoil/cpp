// 완전탐색 문제

// 문제
// 길이가 N인 수식이 있다. 수식은 0보다 크거나 같고, 9보다 작거나 같은 정수와 연산자(+, -, ×)로 이루어져 있다. 
// 연산자 우선순위는 모두 동일하기 때문에, 수식을 계산할 때는 왼쪽에서부터 순서대로 계산해야 한다. 예를 들어, 3+8×7-9×2의 결과는 136이다.
// 수식에 괄호를 추가하면, 괄호 안에 들어있는 식은 먼저 계산해야 한다. 단, 괄호 안에는 연산자가 하나만 들어 있어야 한다.
//  예를 들어, 3+8×7-9×2에 괄호를 3+(8×7)-(9×2)와 같이 추가했으면, 식의 결과는 41이 된다. 하지만, 중첩된 괄호는 사용할 수 없다. 
// 즉, 3+((8×7)-9)×2, 3+((8×7)-(9×2))은 모두 괄호 안에 괄호가 있기 때문에, 올바른 식이 아니다.

// 수식이 주어졌을 때, 괄호를 적절히 추가해 만들 수 있는 식의 결과의 최댓값을 구하는 프로그램을 작성하시오. 추가하는 괄호 개수의 제한은 없으며, 추가하지 않아도 된다.

// 입력
// 첫째 줄에 수식의 길이 N(1 ≤ N ≤ 19)가 주어진다. 둘째 줄에는 수식이 주어진다. 수식에 포함된 정수는 모두 0보다 크거나 같고, 9보다 작거나 같다. 
// 문자열은 정수로 시작하고, 연산자와 정수가 번갈아가면서 나온다. 연산자는 +, -, * 중 하나이다. 여기서 *는 곱하기 연산을 나타내는 × 연산이다. 항상 올바른 수식만 주어지기 때문에, N은 홀수이다.

// 출력
// 첫째 줄에 괄호를 적절히 추가해서 얻을 수 있는 결과의 최댓값을 출력한다. 정답은 231보다 작고, -231보다 크다.


#include<bits/stdc++.h>
using namespace std;


int n;
int ret = -987654321;
vector<char> numList, operList;
string s;

int calcus(char c, int a, int b) {
    if (c == '+') return a+b;
    if (c == '-') return a-b;
    if (c == '*') return a*b;
    if (c == '/') return a/b;
}

void solve(int idx, int num) {      // 메인 함수에서 solve(0, numList[0]) 호출할때 첫번째 인자 0과 numList의 인덱스 0이 같은 값
    if (idx >= numList.size()) {
        ret = max(ret, num);        // 넘어온 누적값 num 과 ret 최대값, 수많은 재귀 값들이 ret을 최신화 하고 있음
        return;
    }
    
    solve(idx+1, calcus(operList[idx], num, numList[idx+1]));
    if(idx+2 < numList.size()){
        int temp = calcus(operList[idx+1], numList[idx+1], numList[idx+2]);
        solve(idx+2, calcus(operList[idx], numList[idx], temp));        // numList[idx] == num 
    }
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 
    cin >> n;
    cin >> s;
    
    for(int i=0; i<n; i++) {
        if(i%2==0) numList.push_back(s[i]);     // 숫자 리스트와, 연산자 리스트를 따로 나누는게 포인트
        else operList.push_back(s[i]);
    }

    solve(0, numList[0]);   // 메인 함수에서 solve(0, numList[0]) 호출할때 첫번째 인자 0과 numList의 인덱스 0이 같은 값
    cout << ret << "\n";
    return 0;
}



// 재귀함수의 매개변수가 인덱스와 누적값임
// 숫자 리스트와, 연산자 리스트를 따로 나누는게 포인트
// 괄호 중복을 허용하지 않으므로 앞에서 부터 괄호를 해나간다고 생각
// 그러면 두가지 경우의 수가 나옴
// 3, 5, 8 이런 순서라면  (3 op 5) op 8 과  3 op (5 op 8)
// 그 두가지 경우 나눠서 재귀함수 호출

// 재귀함수의 탈출조건에서 결과값 최신화
// 넘어온 누적값 num 과 ret 최대값, 수많은 재귀 값들이 ret을 최신화 하고 있음