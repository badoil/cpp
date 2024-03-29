// https://www.acmicpc.net/source/share/b711455b49744a7abf0d12f4de2d689f

// 문제
// 주몽은 철기군을 양성하기 위한 프로젝트에 나섰다. 그래서 야철대장을 통해 철기군이 입을 갑옷을 만들게 하였다. 
// 야철대장은 주몽의 명에 따르기 위하여 연구에 착수하던 중 아래와 같은 사실을 발견하게 되었다.
// 갑옷을 만드는 재료들은 각각 고유한 번호를 가지고 있다. 
// 갑옷은 두 개의 재료로 만드는데 두 재료의 고유한 번호를 합쳐서 M(1 ≤ M ≤ 10,000,000)이 되면 갑옷이 만들어 지게 된다. 
// 야철대장은 자신이 만들고 있는 재료를 가지고 갑옷을 몇 개나 만들 수 있는지 궁금해졌다. 
// 이러한 궁금증을 풀어 주기 위하여 N(1 ≤ N ≤ 15,000) 개의 재료와 M이 주어졌을 때 몇 개의 갑옷을 만들 수 있는지를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에는 재료의 개수 N(1 ≤ N ≤ 15,000)이 주어진다. 
// 그리고 두 번째 줄에는 갑옷을 만드는데 필요한 수 M(1 ≤ M ≤ 10,000,000) 주어진다. 
// 그리고 마지막으로 셋째 줄에는 N개의 재료들이 가진 고유한 번호들이 공백을 사이에 두고 주어진다. 
// 고유한 번호는 100,000보다 작거나 같은 자연수이다.

// 출력
// 첫째 줄에 갑옷을 만들 수 있는 개수를 출력한다.

// 입출력예제
// 6               
// 9               ->    2
// 2 7 4 1 5 3


#include<bits/stdc++.h>
using namespace std;

int n, m, a[15000], cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];

    if (m > 200000) cout << 0 << "\n";  // 예외상황
    else {
        for(int i=0; i<n; i++) {
            for(int k=0; k<n; k++) {
                if (a[i]+a[k] == m) cnt++;
            }
        }
        cout << cnt << "\n";    
    }
    
}

// 문제는 두 수를 합해서 원하는 수가 나오는 조합의 갯수를 구하는 단순한 문제
// 그러나 재료의 고유번호의 최대가 100,000이기에 두 번호를 합친 최대는 20만임
// 그래서 구하고자 하는 수 m 이 20만을 넘으면 답을 구할 수 없다
// 그 예외상황을 먼저 거른 것임