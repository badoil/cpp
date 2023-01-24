// 펜윅트리
// 문제
// 어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다. 
// 만약에 1,2,3,4,5 라는 수가 있고, 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 합을 구하라고 한다면 17을 출력하면 되는 것이다. 
// 그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지 합을 구하라고 한다면 12가 될 것이다.

// 입력
// 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 가 주어진다. 
// M은 수의 변경이 일어나는 횟수이고, K는 구간의 합을 구하는 횟수이다. 그리고 둘째 줄부터 N+1번째 줄까지 N개의 수가 주어진다. 
// 그리고 N+2번째 줄부터 N+M+K+1번째 줄까지 세 개의 정수 a, b, c가 주어지는데, a가 1인 경우 b(1 ≤ b ≤ N)번째 수를 c로 바꾸고 
// a가 2인 경우에는 b(1 ≤ b ≤ N)번째 수부터 c(b ≤ c ≤ N)번째 수까지의 합을 구하여 출력하면 된다.

// 입력으로 주어지는 모든 수는 -263보다 크거나 같고, 263-1보다 작거나 같은 정수이다.

// 출력
// 첫째 줄부터 K줄에 걸쳐 구한 구간의 합을 출력한다. 단, 정답은 -263보다 크거나 같고, 263-1보다 작거나 같은 정수이다.

#include <bits/stdc++.h>
using namespace std;

int n, m, k, t1, t2, t3;
long long t4;

long long sum(vector<long long> &tree, int idx) {
    long long ret;
    while(idx > 0) {
        ret += tree[idx];
        idx -= idx & -idx;
    }
    return ret;
}

void update(vector<long long> &tree, int idx, int diff) {
    while(idx < tree.size()) {
        tree[idx] += diff;
        idx += idx & -idx;
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    vector<long long> tree(n+1);
    vector<long long> a(n+1);
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        update(tree, i, a[i]);
    }

    m += k;
    while(m--) {
        scanf("%d", &t1);
        if (t1 == 1) {
            scanf("%d %lld", &t2, &t4);
            long long diff = t4 - a[t2];
            a[t2] = t4;
            update(tree, t2, diff);
        } else {
            int t3, t2;
            scanf("%d %d", &t2, &t3);
            printf("%lld\n", sum(tree, t3) - sum(tree, t2));
        }
    }

    return 0;
}



// 펜윅트리 
// 트리에 누적합을 적용
// 누적합이 적용되어 있는 트리에
// 구간합을 구하는 방식