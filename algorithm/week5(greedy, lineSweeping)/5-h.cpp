// 문제
// 길이가 N인 수열이 주어질 때, 수열에서 연속한 1개 이상의 수를 뽑았을 때 같은 수가 여러 번 등장하지 않는 경우의 수를 구하는 프로그램을 작성하여라.

// 입력
// 첫 번째 줄에는 수열의 길이 N이 주어진다. (1 ≤ N ≤ 100,000)
// 두 번째 줄에는 수열을 나타내는 N개의 정수가 주어진다. 수열에 나타나는 수는 모두 1 이상 100,000 이하이다.

// 출력
// 조건을 만족하는 경우의 수를 출력한다.



#include<bits/stdc++.h>
using namespace std;

long long n, s, e, countt[100004], a[100004], ret;

int main() {
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    while(e<n) {
        if (!countt[a[e]]) {
            countt[a[e]]++;
            e++;
        } else {
            ret += (e-s);
            countt[a[s]]--;
            s++;
        }
    }

    ret += (long long)(e-s)*(e-s+1)/2;
    cout << ret << "\n";
    return 0;
    
}


// {1, 2, 3, 1, 2} 라는 예시로 생각해볼것
// 투포인터로 푸는 문제
// 이건 걍 동영상 보는게 이해가 쉬움