// 문제
// 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
// 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

// 입력
// 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
// 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

// 출력
// 첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
// 둘째 줄에는 가장 긴 증가하는 부분 수열을 출력한다. 그러한 수열이 여러가지인 경우 아무거나 출력한다.

#include <bits/stdc++.h>
using namespace std;


int n, a[1004], ret=1, cnt[1004], prevList[1004], idx;


void go(int idx) {
    if (idx == -1) return;
    printf("%d ", a[idx]);
    go(prevList[idx]);
    return;
}


int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    fill(prevList, prevList+1004, -1);
    fill(cnt ,cnt+1004, 1);

    for (int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if (a[j]<a[i] && cnt[i]<cnt[j]+1) {     // 뒤에 오는 a[i]의 값이 더 크면 최장기수열에 해당하는 인덱스로 보는것
                cnt[i] = cnt[j] + 1;                // 이를 j 인덱스를 늘려가면서 계속 갱신
                prevList[i] = j;
                if (ret < cnt[i]) {
                    ret = cnt[i];
                    idx = i;
                }
            }
        }
    }

    printf("%d\n", ret);
    go(idx);

    return 0;
}


// 이 풀이법은 주어진 a[i] 수열에서 
// 최장기수열에 해당하는 인덱스만 뽑아내는 것