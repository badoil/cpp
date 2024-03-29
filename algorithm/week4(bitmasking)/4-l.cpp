// 문제
// 선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다. AC는 정수 배열에 연산을 하기 위해 만든 언어이다.
// 이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.
// 함수 R은 배열에 있는 수의 순서를 뒤집는 함수이고, D는 첫 번째 수를 버리는 함수이다.
// 배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.
// 함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다.
// 예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 수를 버리는 함수이다.
// 배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 최대 100이다.
// 각 테스트 케이스의 첫째 줄에는 수행할 함수 p가 주어진다. p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.
// 다음 줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 ≤ n ≤ 100,000)
// 다음 줄에는 [x1,...,xn]과 같은 형태로 배열에 들어있는 정수가 주어진다. (1 ≤ xi ≤ 100)
// 전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.

// 출력
// 각 테스트 케이스에 대해서, 입력으로 주어진 정수 배열에 함수를 수행한 결과를 출력한다. 만약, 에러가 발생한 경우에는 error를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int t, p, n;
string fs, ns;

int main()
{
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        deque<int> d; // deque 자료구조
        cin >> ns >> fs >> n;
        n = 0;
        for (char c : ns)
        {
            if (c == '[' || c == ']')
                continue;
            if (c >= '0' && c <= '9')
                n = n * 10 + (c - '0'); // (1 ≤ c ≤ 100), 쉼표가 아니고 숫자인경우
            else
            { // 쉼표인 경우
                d.push_back(n);
                n = 0; // 초기화
            }
        }
        if (n > 0)
            d.push_back(n); // 마지막 수 넣어줌

        bool rev = false;
        bool error = false;
        for (char c : fs)
        {
            if (c == 'R')
                rev = !rev;
            else
            {
                if (d.size() == 0)
                {
                    error = true;
                    break;
                }
                if (rev)
                    d.pop_back(); // 덱 이용한 부분
                else
                    d.pop_front();
            }
        }
        if (error)
            cout << 'error' << '\n';
        else
        {
            if (rev)
                reverse(d.begin(), d.end());
            for (int i = 0; i < d.size(); i++)
            {
                if (i = 0)
                    cout << '[';
                cout << d[i];
                if (i < d.size() - 1)
                    cout << ',';
            }
            cout << ']\n';
        }

        return 0;
    }
}

// 이 문제는 입력 문자를 숫자 배열로 만든뒤 배열을 조작하는 문제
// 조작은 reverse와 숫자 배열의 맨앞 숫자를 삭제하는것
// 배열의 사이즈가 최대 십만개이므로 매번 리버스를 하는 것은 시간초과 날 수 있음
// 그래서 deque 자료구조와 flag 이용해서
// 배열이 리버스 상태면 맨 뒤를 삭제하고 아니면 앞을 삭제하는 식으로 진행
// 그리고 출력하기전 최종적으로 리버스면 리버스 실행하고 아님 그냥 출력