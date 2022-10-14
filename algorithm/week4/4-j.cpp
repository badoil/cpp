// https://www.acmicpc.net/problem/14391

// 문제
// 영선이는 숫자가 쓰여 있는 직사각형 종이를 가지고 있다. 종이는 1×1 크기의 정사각형 칸으로 나누어져 있고, 숫자는 각 칸에 하나씩 쓰여 있다. 
// 행은 위에서부터 아래까지 번호가 매겨져 있고, 열은 왼쪽부터 오른쪽까지 번호가 매겨져 있다.
// 영선이는 직사각형을 겹치지 않는 조각으로 자르려고 한다. 각 조각은 크기가 세로나 가로 크기가 1인 직사각형 모양이다. 
// 길이가 N인 조각은 N자리 수로 나타낼 수 있다. 가로 조각은 왼쪽부터 오른쪽까지 수를 이어 붙인 것이고, 세로 조각은 위에서부터 아래까지 수를 이어붙인 것이다.

// 아래 그림은 4×4 크기의 종이를 자른 한 가지 방법이다.



// 각 조각의 합은 493 + 7160 + 23 + 58 + 9 + 45 + 91 = 7879 이다.
// 종이를 적절히 잘라서 조각의 합을 최대로 하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 종이 조각의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 4)
// 둘째 줄부터 종이 조각이 주어진다. 각 칸에 쓰여 있는 숫자는 0부터 9까지 중 하나이다.

// 출력
// 영선이가 얻을 수 있는 점수의 최댓값을 출력한다.

#include<bits/stdc++.h>
using namespace std;

int n, m, ret, a[4][4];

int main () {
    
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%ld", a[i][j]);
        }
    }

    for (int s=0; s<(1<<(n*m)); s++) {      // 전체 경우의 수를 탐색
        int sum = 0;
        for (int i=0; i<n; i++) {
            int cur = 0;

            for(int j=0; j<m; j++) {
                int k = i * m + j;              // 2차원 배열의 각 위치를 표현하기
                if ((s & (1<<k)) == 0) {        // 결국 모든 0과 1로 채워진 모든 경우의 수 조합 맵을 구성할 수 있을것임
                    cur = cur * 10 + a[i][j];
                } else {
                    sum += cur;
                    cur = 0;   
                }
            }
            sum += cur;     // 한줄 다 끝났을때 cur 값이 남아있기 때문
        }

        for (int i=0; i<m; i++) {
            int cur = 0;

            for(int j=0; j<n; j++) {
                int k = i * m + i;
                if ((s & (1<<k)) != 0) {
                    cur = cur * 10 + a[i][j];
                } else {
                    sum += cur;
                    cur = 0;   
                }
            }
            sum += cur;
        }

        ret = max(ret, sum);
    }

    printf("%d", &ret);
    return 0;
}


// 전체 맵에서 0은 가로로 1은 세로로 가는 값이라고 생각
// 비트마스킹으로 결국 모든 0과 1로 채워진 모든 경우의 수 조합 맵을 구성할 수 있을것임
// 그때마다 가로, 세로로 탐색하면서 그때 마다 최대값 갱신해줌