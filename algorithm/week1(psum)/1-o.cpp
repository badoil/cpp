// https://www.acmicpc.net/source/share/75cf536d0f434f7eb1e532ff626ca019

// 문제
// 2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때, 1로만 이루어진 n의 배수를 찾는 프로그램을 작성하시오.

// 입력
// 입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, n이 주어진다.

// 출력
// 1로 이루어진 n의 배수 중 가장 작은 수의 자리수를 출력한다.

// 입출력 예

// 3    ->  3 (111)       1이 3자리
// 7    ->  6 (111111)     1이 6자리
// 9901  -> 12 (111111111111)   1이 12 자리

#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> n) {           // 입력은 여러 개의 테스트 케이스라고 할때 계속 입력을 받게 함.
        int cnt = 1, ret = 1;
        while(true) {
            if (ret % n == 0) {
                cout << cnt << "\n";
                break;
            }

            ret = (ret*10) + 1; // 11111, 요런 수를 한자리씩 더 만드는 식
            ret %= n;           // [(a mod n) * (b mod n)] mod n = (a*b) mod n
            cnt++;
            
        }
    }
}

// 입력은 여러 개의 테스트 케이스라고 할때 계속 입력을 받게 함
// 자리수 출력이라서 cnt 하나씩 올려주고 그게 맞으면 출력
// ret % n == 0 이거를 구해야하는데, 마지막에만 %를 하는게 아니라
// 수가 너무 커지기 전에 중간 중간 %를 계속 해줌. 즉 모듈라 연산