//https://www.acmicpc.net/problem/2632
// 문제
// 고객이 두 종류의 피자 A와 B를 취급하는 피자가게에서 피자를 주문하고자 한다. <그림 1>과 같이 각 종류의 피자는 다양한 크기의 여러 개의 피자조각으로 나누어져 있다. 
// 각 조각에 쓰여진 숫자는 피자조각의 크기를 나타낸다.



// <그림 1>

// 고객이 원하는 피자의 크기를 이야기하면, 피자가게에서는 한 종류의 피자를 2 조각 이상 판매할 때는 반드시 연속된 조각들을 잘라서 판매한다. 
// 이때 판매한 피자조각의 크기 합이 주문한 크기가 되어야 한다. 판매한 피자조각은 모두 A종류이거나, 모두 B종류이거나, 또는 A와 B 종류가 혼합될 수 있다. 
// 예를 들어서, <그림 1> 과 같이 잘라진 피자가 있을 때, 손님이 전체 크기가 7 인 피자를 주문하면, 피자 가게에서는 <그림2>와 같이 5 가지 방법으로 피자를 판매할 수 있다.



// <그림 2>

// 피자가게에서 손님이 원하는 크기의 피자를 판매하는 모든 방법의 가지 수를 계산하는 프로그램을 작성하시오

// 입력
// 첫 번째 줄에는 손님이 구매하고자 하는 피자크기를 나타내는 2,000,000 이하의 자연수가 주어진다. 
// 두 번째 줄에는 A, B 피자의 피자조각의 개수를 나타내 는 정수 m, n 이 차례로 주어진다 (3 ≤ m, n ≤ 1000). 
// 세 번째 줄부터 차례로 m 개의 줄에는 피자 A의 미리 잘라진 피자조각의 크기를 나타내는 정수가 주어진다. 
// 그 다음 n 개의 줄에는 차례로 피자B의 미리 잘라진 피자조각의 크기를 나타내는 정수가 주어진다. 각 종류의 피자조각의 크기는 시계방향으로 차례로 주어지며, 각 피자 조각의 크기는 1000 이하의 자연수이다.

// 출력
// 첫째 줄에는 피자를 판매하는 방법의 가지 수를 나타내는 정수를 출력한다. 피자를 판매하는 방법이 없는 경우에는 숫자 0을 출력한다.



#include<bits/stdc++.h>
using namespace std;


int want, m, n, a[1004], b[1004], psum_a[2004], psum_b[2004];
map<int, int> cnt_a, cnt_b;


void make(int x, int psum[], map<int, int> &cnt_x) {
    for (int interval=1; interval<=x; interval++) {
        for(int start=interval; start<2*x-1; start++) {     // start<n + interval - 1 이렇게 해도 됨
            int sum = psum[start] - psum[start-interval];
            cnt_x[sum]++;
            if (interval == x) break;
        }
    }
    return;
}


int main () {
    scanf("%d %d %d", &want, &m, &n);
    for(int i=1; i<=m; i++){
        scanf("%d", a+i);         // a 배열의 0번째 메모리 주소로부터 +i 거리의 원소, 즉 a[i] 
        psum_a[i] = psum_a[i-1] + a[i];
    }
    for(int i=m+1; i<=2*m; i++) {           // 원형 배열은 배열 두개를 잇는 것
        psum_a[i] = psum_a[i-1] + a[i-m];
    }

    for(int i=1; i<=n; i++){
        scanf("%d", b+i);
        psum_b[i] = psum_b[i-1] + b[i];
    }
    for(int i=n+1; i<=2*n; i++) {
        psum_b[i] = psum_b[i-1] + b[i-n];
    }

    make(m, psum_a, cnt_a);
    make(n, psum_b, cnt_b);

    
    int cnt = 0;
    
    cnt += cnt_a[want];
    cnt += cnt_b[want];
    
    for (int i=1; i<=want; i++) {
        cnt += cnt_a[want-i] * cnt_b[i];        // 맵에 해당하는 값이 없으면 0이기에 카운팅 안됨
    }

    printf("%d\n", cnt);
    return 0;
}


// 개쩌는 문제
// 이번 week 5 문제 중에 가장 어려움
// 기본적 발상은 피자 조각 크기 부분합의 모든 경우를 맵에 담음
// 부분 합을 구하기 위해서 우선 누적합을 구해둠
// 원하는 피자 크기를 맵에서 찾음

// 원하는 피자크기가 A 피자만으로 있는 경우
// 원하는 피자크기가 B 피자만으로 있는 경우
// 원하는 피자크기가 A + B 두 피자조각 합해야 하는 경우