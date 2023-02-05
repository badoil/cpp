// 문제
// 상근이는 영화 DVD 수집가이다. 상근이는 그의 DVD 콜렉션을 쌓아 보관한다.
// 보고 싶은 영화가 있을 때는, DVD의 위치를 찾은 다음 쌓아놓은 콜렉션이 무너지지 않게 조심스럽게 DVD를 뺀다. 영화를 다 본 이후에는 가장 위에 놓는다.
// 상근이는 DVD가 매우 많기 때문에, 영화의 위치를 찾는데 시간이 너무 오래 걸린다. 각 DVD의 위치는, 찾으려는 DVD의 위에 있는 영화의 개수만 알면 쉽게 구할 수 있다. 
// 각 영화는 DVD 표지에 붙어있는 숫자로 쉽게 구별할 수 있다.
// 각 영화의 위치를 기록하는 프로그램을 작성하시오. 상근이가 영화를 한 편 볼 때마다 그 DVD의 위에 몇 개의 DVD가 있었는지를 구해야 한다.

// 입력
// 첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스의 개수는 100개를 넘지 않는다.
// 각 테스트 케이스의 첫째 줄에는 상근이가 가지고 있는 영화의 수 n과 보려고 하는 영화의 수 m이 주어진다. (1 ≤ n, m ≤ 100,000) 
// 둘째 줄에는 보려고 하는 영화의 번호가 순서대로 주어진다.
// 영화의 번호는 1부터 n까지 이며, 가장 처음에 영화가 쌓여진 순서는 1부터 증가하는 순서이다. 가장 위에 있는 영화의 번호는 1이다. 

// 출력
// 각 테스트 케이스에 대해서 한 줄에 m개의 정수를 출력해야 한다. 
// i번째 출력하는 수는 i번째로 영화를 볼 때 그 영화의 위에 있었던 DVD의 개수이다. 
// 상근이는 매번 영화를 볼 때마다 본 영화 DVD를 가장 위에 놓는다.


#include <bits/stdc++.h>
using namespace std;
int n, m, t, tree[200004], temp;
map<int, int> mp;

int sum(int i) {
    int ret = 0;
    while (i) {
        ret += tree[i];
        i -= (i & -i);
    }
    return ret;
}

void update(int i, int value) {
    while(i <= 200004) {
        tree[i] += value;
        i += (i & -i);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        memset(tree, 0, sizeof(tree));
        mp.clear();
        int update_idx = 100001;
        for (int i=1; i<=n; i++) {
            update(i+update_idx, 1);
            mp[i] = i+update_idx;           // dvd가 꽂혀있는 번호와 그 실제 배열 위치를 map에 저장
        }

        for (int i=1; i<=m; i++) {
            cin >> temp;
            int idx = mp[temp];             // dvd의 실제 위치
            cout << sum(idx) - 1 << "\n";   // 1,2,3,4... 이런식으로 dvd 가 옆으로 꽂힐때 만약 4번 dvd 찾는다면 sum(4), 자기는 빼야하므로 -1 해줌
            update(idx, -1);                // 찾은 dvd 를 맨앞에 놓기 때문에, 원래 있던 자리는 -1 해서 0으로 만듬
            update(--update_idx, 1);        // 찾은 dvd 를 맨앞에 놓기 때문에, 맨앞 자리에 +1 해줌
            mp[temp] = update_idx;          // temp 번호 dvd 위치는 맨 앞자리로 엡데이트
        }
        cout << "\n";
    }
}

// 좋은 팬윅트리 문제
// 배열의 위치가 변하면서 
// 변한 위치 배열을 기반으로 dvd 위치 찾는 문제기 때문

// tree 에는 각 dvd 갯수 1 을 넣어주고
// sum 으로 자기 앞에 dvd가 몇개 있는지 체크
