// 문제
// 세준이는 잘 모르겠지만, 세준이는 보석에 미쳐있다. 따라서, 숌 보석상에 있는 모든 보석을 다 훔치려고 한다. 하지만, 세준이는 보석을 다 가져올 수는 없다. 
// 그 이유는 가방의 개수에 제한이 있고, 한 가방마다 넣을 수 있는 보석의 개수가 제한이 있기 때문이다. 세준이는 M개의 가방을 가지고 있다. 그리고 각각의 가방은 C그램의 보석을 담을 수 있다.
// 숌 보석상에는 보석이 N개 있다. N개의 보석의 무게가 주어졌을 때, 세준이가 훔칠 수 있는 보석의 최대 개수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 보석의 개수 N, 가방의 개수 M, 가방의 최대 한도 C가 주어진다. 
// N은 1보다 크거나 같고, 13보다 작거나 같은 자연수이고, 
// M은 1보다 크거나 같고, 10보다 작거나 같은 자연수이다. 
// C는 1보다 크고, 20보다 작거나 같은 자연수이다. 둘째 줄에 보석의 무게가 하나씩 주어진다. 보석의 무게는 1보다 크거나 같고, 20보다 작거나 같은 자연수이다.

// 출력
// 첫째 줄에 세준이가 가져갈 수 있는 최대 보석의 개수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int n, m, c, a[14], dp[14][1<<17][24];


int go(int bagNumber, int diamondList, int capa) {
    if (bagNumber == m) return 0;
    int &ret = dp[bagNumber][diamondList][capa];
    if (ret) return ret;
    
    ret = max(ret, go(bagNumber+1, diamondList, capa));     // 현재 bagNumber에 다이아몬드를 안넣거나
    for (int i=0; i<n; i++) {                               // 현재 bagNumber에 다이아몬드를 넣거나
        bool isDiamond = (diamondList & (1<<i));
        if (!isDiamond && capa-a[i]>=0) {
            ret = max(ret, go(bagNumber, diamondList|(1<<i), capa-a[i])+1);
        } 
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> c;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    cout << go(0, 0, c) << "\n";
    return 0;
}


// 이 문제를 완탐의 관점에서 일단 바라보면
// bagNumber인 백에 다이아몬드를 넣거나 안넣거나임
// 이때 가방에 넣은 다이아몬드는 비트마스킹으로 체크

// 트리 분기로 생각해보면
// 현재가방에 다이아 안넣음 
// 또는
// 현재 가방에 1번 다이아 넣고 재귀함수 콜해서 분기, 현재 가방에 2번 다이아 넣고 재귀함수 콜해서 분기...
// 이를 반복문과 재귀로 반복해서
// 각 분기들 중에 제일 큰 애를 선택