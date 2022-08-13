// https://www.acmicpc.net/source/share/fdee73d789cf421db0e71ad9d332cb4a

// 문제
// 상근이는 오락실에서 바구니를 옮기는 오래된 게임을 한다. 스크린은 N칸으로 나누어져 있다. 스크린의 아래쪽에는 M칸을 차지하는 바구니가 있다. 
// (M<N) 플레이어는 게임을 하는 중에 바구니를 왼쪽이나 오른쪽으로 이동할 수 있다. 하지만, 바구니는 스크린의 경계를 넘어가면 안 된다. 가장 처음에 바구니는 왼쪽 M칸을 차지하고 있다.
// 스크린의 위에서 사과 여러 개가 떨어진다. 각 사과는 N칸중 한 칸의 상단에서 떨어지기 시작하며, 스크린의 바닥에 닿을때까지 직선으로 떨어진다. 한 사과가 바닥에 닿는 즉시, 다른 사과가 떨어지기 시작한다.
// 바구니가 사과가 떨어지는 칸을 차지하고 있다면, 바구니는 그 사과가 바닥에 닿을 때, 사과를 담을 수 있다. 상근이는 사과를 모두 담으려고 한다. 
// 이때, 바구니의 이동 거리의 최솟값을 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N과 M이 주어진다. (1 ≤ M < N ≤ 10) 둘째 줄에 떨어지는 사과의 개수 J가 주어진다. (1 ≤ J ≤ 20) 다음 J개 줄에는 사과가 떨어지는 위치가 순서대로 주어진다.

// 출력
// 모든 사과를 담기 위해서 바구니가 이동해야 하는 거리의 최솟값을 출력한다.


#include<bits/stdc++.h>
using namespace std;

int n, m, j, l, r, temp, ret;

int main () {
    cin >> n >> m;
    cin >> j;
    l=1;
    for (int i=0; i<j; i++) {
        cin >> temp;
        r = l + m - 1;                      // 물건이 l-r 범위를 차지한다면 이 물건의 위치를 r로 잡은것, 다만 문제에서 물건의 처음 위치를 l=1, r=1로 둔셈
        if (l<=temp && temp<=r) continue;
        else {
            if (temp < l) {                 // 과일이 l 왼쪽에 떨어지는 경우
                ret += (l - temp);          // 움직인 수를 더해줌
                l = temp;                   // 물건의 l 위치 이동
            } else {                        // 과일이 r 오른쪽에 떨어지는 경우
                ret += (temp - r);
                l += (temp - r);
            }
        }
    }

    cout << temp << "\n";
    return 0;
}

// 물건이 l-r 범위를 차지한다면 이 물건의 위치를 r로 잡은것, 다만 문제에서 
// 물건의 처음 위치를 l=1, r=1로 둔셈
// 어차피 l의 처음 위치는 중요치 않음