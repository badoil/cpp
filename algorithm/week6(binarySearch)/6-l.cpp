// 문제
// N개의 실수가 있을 때, 한 개 이상의 연속된 수들의 곱이 최대가 되는 부분을 찾아, 그 곱을 출력하는 프로그램을 작성하시오. 
// 예를 들어 아래와 같이 8개의 양의 실수가 주어진다면,

// 1.1  0.7  [1.3  0.9  1.4]  0.8  0.7  1.4
// 괄호 부분의 곱이 최대가 되며, 그 값은 1.638이다.

// 입력
// 첫째 줄은 나열된 양의 실수들의 개수 N이 주어지고, 그 다음 줄부터 N개의 수가 한 줄에 하나씩 들어 있다. N은 10,000 이하의 자연수이다. 
// 실수는 소수점 첫째자리까지 주어지며, 0.0보다 크거나 같고, 9.9보다 작거나 같다.

// 출력
// 계산된 최댓값을 소수점 이하 넷째 자리에서 반올림하여 소수점 이하 셋째 자리까지 출력한다.

#include <bits/stdc++.h>
using namespace std;

int n;
double ret, a[10004];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    double b = a[0];
    for (int i=1; i<n; i++) {
        if (b*a[i] < a[i]) b = a[i];    // 기존 b에 a[i]를 곱해서 더 크면 곱하고 아니면 b에 a[i] 대입
        else b *= a[i];
        ret = max(ret, b);              // 최대값 갱신
    }

    printf("%.3lf", ret + 0.00001);     // .3lf: %는 형식 지정자의 시작을 나타내는 기호입니다. .은 소수점 이하 자릿수를 지정하기 위한 점입니다. 
                                        // 3은 소수점 이하 자릿수를 3으로 설정하라는 의미입니다. lf는 부동 소수점 숫자(double)를 나타내는 형식 지정자입니다.
    return 0;
}



// 부분누적곱의 최대 값을 구하는 문제
// 더블이기 때문에 곱하면 더 작아질 수 있음
// 코드를 보라