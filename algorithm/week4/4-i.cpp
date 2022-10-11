// 문제
// 비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

// add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
// remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
// check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
// toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
// all: S를 {1, 2, ..., 20} 으로 바꾼다.
// empty: S를 공집합으로 바꾼다. 

// 입력
// 첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.
// 둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.

// 출력
// check 연산이 주어질때마다, 결과를 출력한다.

/*

예제 입력 1             예제 출력 1 
26
add 1
add 2
check 1               1
check 2               1
check 3               0
remove 2
check 1               1
check 2               0
toggle 3
check 1               1
check 2               0
check 3               1
check 4               0
all
check 10              1
check 20              1
toggle 10
remove 20
check 10              0
check 20              0
empty
check 1               0
toggle 1
check 1               1
toggle 1
check 1               0

*/


#include<bits/stdc++.h>
using namespace std;


int m, n, x;
string s;

int main() {
    scanf(" %d", &m);

    for (int i=0; i<m; i++) {
        scanf(" %s %d", &s, &x);
        if (s[0] == 'a' && s[1] == 'd') n |= (1<<x);
        else if (s[0] == 'r') n &= ~(1<<x);         // 주어진 x 자리 0으로 만들기
        else if (s[0] == 'c') printf("%d\n", (n & (1<<x)) == 0 ? 0 : 1);
        else if (s[0] == 't') n ^= (1<<x);      // xor
        else if (s[0] == 'a' && s[1] == 'l') n = (1<<21)-1;
        else n = 0;
    }
}