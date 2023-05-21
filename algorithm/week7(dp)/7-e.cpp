// 문제
// 70세 박종수 할아버지는 매일 매일 약 반알을 먹는다. 손녀 선영이는 종수 할아버지에게 약이 N개 담긴 병을 선물로 주었다.
// 첫째 날에 종수는 병에서 약 하나를 꺼낸다. 그 다음, 그 약을 반으로 쪼개서 한 조각은 먹고, 다른 조각은 다시 병에 넣는다.

// 다음 날부터 종수는 병에서 약을 하나 꺼낸다. (약은 한 조각 전체 일 수도 있고, 쪼갠 반 조각 일 수도 있다) 반 조각이라면 그 약을 먹고, 
// 아니라면 반을 쪼개서 한 조각을 먹고, 다른 조각은 다시 병에 넣는다.
// 종수는 손녀에게 한 조각을 꺼낸 날에는 W를, 반 조각을 꺼낸 날에는 H 보낸다. 손녀는 할아버지에게 받은 문자를 종이에 기록해 놓는다. 
// 총 2N일이 지나면 길이가 2N인 문자열이 만들어지게 된다. 이때, 가능한 서로 다른 문자열의 개수는 총 몇 개일까?

// 입력
// 입력은 최대 1000개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄이며, 병에 들어있는 약의 개수 N ≤ 30 가 주어진다.
// 입력의 마지막 줄에는 0이 하나 주어진다.

// 출력
// 각 테스트 케이스에 대해서 가능한 문자열의 개수를 출력한다.


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[34][34], n;

ll go(int whole, int half) {
    if (whole==0 && half==0) return 1;                  // 노드의 끝에 왔으니, 이 가지를 한 가지의 경우로 보고 1을 리턴
    if (dp[whole][half] != 0) return dp[whole][half];   // 메모이제이션
    ll &ret = dp[whole][half];
    if (whole > 0) ret += go(whole-1, half+1);  // 온전한 한알을 꺼내 먹는 경우, 1개짜리는 줄고 1개를 쪼개서 반만먹고 다시 넣으니 반개짜리는 하나 증가
    if (half > 0) ret += go(whole, half-1);     // 반알을 꺼낸 경우
    return ret;       // 노드의 최 상단에서 모든 경우의 수가 종합될 것
}

int main() {
    while(true) {
        cin >> n;
        if (n==0) break;
        cout << go(n, 0) << "\n";
    }
    return 0;
}


// 두가지 경우의 수, 병에서 온전한 한알을 꺼낼 경우와 반쪽짜리 약을 꺼낼경우
