// https://www.acmicpc.net/source/share/ce4d012c085a44918188cb28f01032b0


// 문제
// 트리에서 리프 노드란, 자식의 개수가 0인 노드를 말한다.
// 트리가 주어졌을 때, 노드 하나를 지울 것이다. 그 때, 남은 트리에서 리프 노드의 개수를 구하는 프로그램을 작성하시오. 노드를 지우면 그 노드와 노드의 모든 자손이 트리에서 제거된다.

// 입력
// 첫째 줄에 트리의 노드의 개수 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄에는 0번 노드부터 N-1번 노드까지, 각 노드의 부모가 주어진다. 만약 부모가 없다면 (루트) -1이 주어진다. 셋째 줄에는 지울 노드의 번호가 주어진다.

// 출력
// 첫째 줄에 입력으로 주어진 트리에서 입력으로 주어진 노드를 지웠을 때, 리프 노드의 개수를 출력한다


#include<bits/stdc++.h>
using namespace std;

int n, m, root, r, ret;
vector<int> v[50];


int dfs(int here) {
    
    int c = 0;
    for (int there: v[here]) {      // 리프노드는 이 포문 안돌고, c++ 안하므로 c=0
        if (there == r) continue;
        ret += dfs(there);          // 리프노드 갯수가 위에서 다 모여서 계산
        c++;                        // here->there 로 가는것은 차일드가 있다는 것임, 그걸 카운팅
    }
    if (c==0) return 1;     // 리프 노드 갯수 리턴
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) {       // 인덱스 i는 i번 노드라는 뜻
        cin >> m;
        if (m == -1) root = i;
        v[m].push_back(i);          // {{1,2}, {3,4}} 이런식의 자료구조
    }

    cin >> r;                      // 삭제할 노드 번호
    if (r==root) {                  // 루트노드를 삭제하면 0임
        cout << 0 << "\n";
        return 0;
    }
    
    cout << dfs(root) << "\n";
    return 0;
}


// vector<int> v[50]와 같이 {{1,2}, {3,4}} 이런꼴로 트리 자료형 구성
// 즉 0번 노드는 1,2번 자식노드, 1번노드는 3,4번 자식노드
// 3, 4번 노드는 자식노드가 없는 리프노드
// 이때 dfs에서 리프노드 카운팅하면서 재귀함수 호출