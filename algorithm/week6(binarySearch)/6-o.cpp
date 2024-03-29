// *
//https://www.acmicpc.net/problem/2565

// 문제
// 두 전봇대 A와 B 사이에 하나 둘씩 전깃줄을 추가하다 보니 전깃줄이 서로 교차하는 경우가 발생하였다. 
// 합선의 위험이 있어 이들 중 몇 개의 전깃줄을 없애 전깃줄이 교차하지 않도록 만들려고 한다.
// 예를 들어, < 그림 1 >과 같이 전깃줄이 연결되어 있는 경우 A의 1번 위치와 B의 8번 위치를 잇는 전깃줄, A의 3번 위치와 B의 9번 위치를 잇는 전깃줄, 
// A의 4번 위치와 B의 1번 위치를 잇는 전깃줄을 없애면 남아있는 모든 전깃줄이 서로 교차하지 않게 된다.


// 전깃줄이 전봇대에 연결되는 위치는 전봇대 위에서부터 차례대로 번호가 매겨진다. 전깃줄의 개수와 전깃줄들이 두 전봇대에 연결되는 위치의 번호가 주어질 때, 
// 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에는 두 전봇대 사이의 전깃줄의 개수가 주어진다. 전깃줄의 개수는 100 이하의 자연수이다. 
// 둘째 줄부터 한 줄에 하나씩 전깃줄이 A전봇대와 연결되는 위치의 번호와 B전봇대와 연결되는 위치의 번호가 차례로 주어진다. 
// 위치의 번호는 500 이하의 자연수이고, 같은 위치에 두 개 이상의 전깃줄이 연결될 수 없다.

// 출력
// 첫째 줄에 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 출력한다.


#include <bits/stdc++.h>
using namespace std;

int n, a, b, resultList[504], len;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());   // first 기준으로 오름차순 정렬
    for (int i=0; i<n; i++) {
        auto lower_pos = lower_bound(resultList, resultList+len, v[i].second);
        if (*lower_pos==0) len++;
        *lower_pos = v[i].second;
    }

    cout << n - len << "\n";
    return 0;
}


// 이 문제가 최장증가수열임을 파악하는 것이 중요
// 결국 줄이 겹치지 않게 하려면 
// 나중 A번호에서 B로 가는 선의 번호가 그 전 A번호에서 B로 가는 선의 번호보다 작으면 안됨
// 작으면 증가수열이 아니기 때문에 이 놈들을 카운트 해주면 됨
// 즉 B번호들의 죄장증가수열의 갯수를 구하고
// 전체 n 에서 죄장증가수열의 갯수를 빼주면 답