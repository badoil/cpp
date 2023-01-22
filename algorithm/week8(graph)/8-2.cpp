// 문제
// 준규는 새 RPG 게임을 시작했다. 이 게임에서 캐릭터는 2가지 스탯을 가지고 있다. 하나는 힘(STR)이고, 다른 하나는 지력(INT)이다. 캐릭터를 생성했을 때, 두 스탯은 모두 1이다.

// 게임에는 총 N개의 퀘스트가 있다. i번째 퀘스트를 깨려면 캐릭터의 힘이 STR[i]보다 크거나 같거나, 지력이 INT[i]보다 크거나 같아야 한다. 
// 이 퀘스트를 깨면, 스탯을 올릴 수 있는 포인트를 PNT[i]개 만큼 얻게 된다.

// 모든 퀘스트는 단 한 번만 깰 수 있으며, 퀘스트를 깨는 순서는 준규가 마음대로 정할 수 있다. 또, 퀘스트 보상으로 얻게되는 포인트로 준규 마음대로 스탯을 올릴 수 있다.
// 준규가 깰 수 있는 퀘스트 개수의 최댓값을 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 퀘스트의 개수 N이 주어진다. N은 50보다 작거나 같은 자연수이다.
// 둘째 줄부터 N개의 줄에 STR[i], INT[i], PNT[i]가 주어진다. 이 숫자는 모두 1,000보다 작거나 같은 자연수이다.

// 출력
// 첫째 줄에 준규가 깰 수 있는 퀘스트 개수의 최댓값을 출력한다.

#include <bits/stdc++.h>
using namespace std;

struct que{
    int x, y, c;
    que(int x, int y, int c) :x(x), y(y), c(c){}
};
vector<que> a;
int n, dp[1004][1004];
bool visited[1004];

int rpg(int STR, int INT) {
    int &ret = dp[STR][INT];
    if (ret != -1) return ret;
    
    ret = 0;
    int ptr = 0;
    vector<int> Q;
    for (int i=0; i<n; i++) {
        if (a[i].x <= STR || a[i].y <= INT) {
            ret++;     // 퀘스트 깨는 갯수
            if (!visited[i]) {
                visited[i] = true;      // 방문처리
                ptr += a[i].c;
                Q.push_back(i);
            }            
        }   
    }

    for (int p=1; p<=ptr; p++) {            // 포인트 분배
        int nextSTR = min(1000, STR+p);
        int nextINT = min(1000, INT+ptr-p);
        ret = max(ret, rpg(nextSTR, nextINT));  // 나눈 포인트의 모든 경우에 대해서 rpg 재귀호출
    }
    for (int q : Q) visited[q] = false;     // 방문처리 되돌림
    return ret;
}

int main () {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int STR, INT, PNT;
        scanf("%d %d %d", &STR, &INT, &PNT);
        a.push_back(que(STR, INT, PNT));
    }

    memset(dp, -1, sizeof(dp));
    printf("%d", rpg(1,1));
    return 0;
}


// dp + 완탐 문제