// 문제
// 1번부터 N번까지 번호가 매겨져 있는 N개의 나무가 있다. i번 나무는 좌표 X[i]에 심어질 것이다.
// 동호는 나무를 1번 나무부터 차례대로 좌표 X[i]에 심으려고 한다. 1번 나무를 심는 비용은 없고, 각각의 나무를 심는데 드는 비용은 현재 심어져있는 모든 나무 까지 거리의 합이다. 
// 만약 3번 나무를 심는다면, 1번 나무와의 거리 + 2번 나무와의 거리가 3번 나무를 심는데 드는 비용이다.
// 2번 나무부터 N번 나무까지를 심는 비용의 곱을 출력하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 나무의 개수 N (2 ≤ N ≤ 200,000)이 주어진다. 둘째 줄부터 N개의 줄에 1번 나무의 좌표부터 차례대로 주어진다. 각각의 좌표는 200,000보다 작은 자연수 또는 0이다.

// 출력
// 문제의 정답을 1,000,000,007로 나눈 나머지를 출력한다.

#include <bits/stdc++.h>
using namespace std;
#define maxN 200004
#define ll long long
int n, value;
ll ret = 1, mod = 1e9 + 7;
vector<ll> treeCnt(maxN, 0), treeSum(maxN, 0);

ll _sum(vector<ll> &tree, int a) {
    int sum = 0;
    int i = a;
    while (i) {
        sum += tree[i];
        i -= (i & -i);
    }
    return sum;
}

ll sum(vector<ll> &tree, int a, int b) {
    if (a < b) return 0;
    return (_sum(tree, a) - _sum(tree, b-1));
}

void update(vector<ll> &tree, int idx, ll diff) {
    int i = idx;
    while(i <= maxN) {
        tree[i] += diff;
        i += (i & -i);
    }
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=1; i<=n; i++) {
        if (i != 1) {
            cin >> value; value++;
            int left = sum(treeCnt, value-1, 1) * value - sum(treeSum, value-1, 1);         // 나무를 왼쪽 -> 오른쪽으로 심기
            int right = sum(treeSum, value+1, maxN) - sum(treeCnt, value+1, maxN) * value;  // 나무를 다시 왼쪽으로 가서 심을때 있기에
            ret *= (left+right) % mod;
            ret %= mod;
        }
        update(treeCnt, value, 1);
        update(treeSum, value, value);      // value가 tree[i]의 인덱스와 값, 두 역할 다 함
    }
    cout << ret << "\n";
}

// 펜윅트리
// int left = sum(treeCnt, value-1, 1) * value - sum(treeSum, value-1, 1)
// 현재나무의 value에 현재나무 전까지 심은 나무의 갯수를 곱하고
// 현재나무 전까지 심은 나무들의 value 들의 합을 빼면 
// 현재 나무에서 이전 각 나무들과의 거리를 더한 값, 즉 현재 나무를 심는 비용이 나옴