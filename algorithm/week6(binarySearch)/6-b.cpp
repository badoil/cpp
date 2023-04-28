// *
// 문제
// 강토는 자신의 기타 강의 동영상을 블루레이로 만들어 판매하려고 한다. 
// 블루레이에는 총 N개의 강의가 들어가는데, 블루레이를 녹화할 때, 강의의 순서가 바뀌면 안 된다. 
// 순서가 뒤바뀌는 경우에는 강의의 흐름이 끊겨, 학생들이 대혼란에 빠질 수 있기 때문이다. 
// 즉, i번 강의와 j번 강의를 같은 블루레이에 녹화하려면 i와 j 사이의 모든 강의도 같은 블루레이에 녹화해야 한다.
// 강토는 이 블루레이가 얼마나 팔릴지 아직 알 수 없기 때문에, 블루레이의 개수를 가급적 줄이려고 한다. 
// 오랜 고민 끝에 강토는 M개의 블루레이에 모든 기타 강의 동영상을 녹화하기로 했다. 
// 이때, 블루레이의 크기(녹화 가능한 길이)를 최소로 하려고 한다. 단, M개의 블루레이는 모두 같은 크기이어야 한다.
// 강토의 각 강의의 길이가 분 단위(자연수)로 주어진다. 이때, 가능한 블루레이의 크기 중 최소를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 강의의 수 N (1 ≤ N ≤ 100,000)과 M (1 ≤ M ≤ N)이 주어진다. 
// 다음 줄에는 강토의 기타 강의의 길이가 강의 순서대로 분 단위로(자연수)로 주어진다. 
// 각 강의의 길이는 10,000분을 넘지 않는다.

// 출력
// 첫째 줄에 가능한 블루레이 크기중 최소를 출력한다.

// 예제 입력 1                  예제 출력 1 
// 9 3                        17
// 1 2 3 4 5 6 7 8 9

// 힌트
// 강의는 총 9개이고, 블루레이는 총 3개 가지고 있다.
// 1번 블루레이에 1, 2, 3, 4, 5, 
// 2번 블루레이에 6, 7, 
// 3번 블루레이에 8, 9 를 넣으면 각 블루레이의 크기는 15, 13, 17이 된다. 
// 블루레이의 크기는 모두 같아야 하기 때문에, 블루레이의 크기는 17이 된다. 
// 17보다 더 작은 크기를 가지는 블루레이를 만들 수 없다. 


#include<bits/stdc++.h>
using namespace std;


int n, m, ret=987654321, a[100004];

bool check(int mid) {
    for (int i=0; i<n; i++) {
        if (mid < a[i]) {
            return false;
        }
    }

    int temp = mid;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (a[i] > mid) {
            mid = temp;
            cnt++;
        }
        mid -= a[i];
    }
    if (mid != temp) cnt++;

    return m >= cnt;
}

int main() {
    cin >> n >> m;
    int psum = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        psum += a[i];
    }

    int lo = 0, hi = psum;
    while(lo <= hi) {
        int mid = (lo+hi)/2;
        if (check(mid)) {
            ret = min(ret, mid);
            hi = mid - 1;
        } else lo = mid + 1;
    }

    cout << ret << "\n";
    return 0;
}


// 이분탐색 문제
// 총강의 길이의 mid로 필요한 블루레이 갯수를 구하고 그 갯수가 주어진 블루레이보다 같거나 적으면
// 그 mid를 최소값을 갱신해 나감