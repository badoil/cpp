// 문제
// n개의 서로 다른 양의 정수 a1, a2, ..., an으로 이루어진 수열이 있다. ai의 값은 1보다 크거나 같고, 1000000보다 작거나 같은 자연수이다. 
// 자연수 x가 주어졌을 때, ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 수열의 크기 n이 주어진다. 다음 줄에는 수열에 포함되는 수가 주어진다. 셋째 줄에는 x가 주어진다. (1 ≤ n ≤ 100000, 1 ≤ x ≤ 2000000)

// 출력
// 문제의 조건을 만족하는 쌍의 개수를 출력한다.

#include<bits/stdc++.h>
using namespace std;


int n, x, ret, l, r;
vector<int> v;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    cin >> x;

    l = 0;
    r = n-1;
    while(l<r) {
        if (v[l]+v[r]==x) r--, ret++;
        else if (v[l]+v[r]>x) r--;
        else if (v[l]+v[r]<x) l--;
    }

    cout << ret << '\n';
    return 0;

}


// 투포인터 문제
// 정렬 후에 투포인터로 합 체크한 다음 l 또는 r을 이동

