// *
// 문제
// 세준이는 등산광이다. 세준이는 높은 곳에서 도시를 내려다 보는 것을 좋아한다. 하지만, 겁이 많은 세준이는 어두워지기 전에 호텔로 내려오려고 한다.
// 세준이가 가려고하는 산의 지도가 입력으로 주어진다. 산의 지도를 M이라고 했을 때, M[i][j]는 (i,j)의 높이가 M[i][j]라는 것을 의미한다. 
// 그 값이 'A'-'Z'일 때는 0-25를 뜻하는 것이고, 'a'-'z'일 때는, 26-51을 뜻한다.

// 세준이의 호텔은 (0,0)에 있다. 그리고, 세준이는 지금 위치에서 바로 인접한 정수 좌표 중 높이의 차이가 T보다 크지 않은 곳으로만 다닐 수 있다.
// 만약 세준이가 현재 위치에서 높이가 낮은 곳이나 같은 곳으로 이동한다면 시간은 1초가 걸린다. 하지만 높은 곳으로 이동한다면 두 위치의 높이의 차이의 제곱만큼 시간이 걸린다. 
// 예를 들어 높이가 5에서 높이가 9인 곳으로 간다면, 시간은 (5-9)2=16초가 걸린다. 하지만, 높이가 9인 곳에서 5인 곳으로 간다면 시간은 1초가 걸린다.
// 산의 지도와, T, 그리고 어두워지는 시간 D가 주어졌을 때, 세준이가 D보다 크지 않은 시간 동안 올라갈 수 있는 최대 높이를 구하는 프로그램을 작성하시오.(세준이는 호텔에서 출발해서 호텔로 돌아와야 한다.)

// 입력
// 첫째 줄에 산의 세로크기 N과 가로크기 M 그리고, T와 D가 주어진다. N과 M은 25보다 작거나 같은 자연수이다. 
// 둘째 줄부터 N개의 줄에 지도가 주어진다. T는 52보다 작거나 같은 자연수이고, D는 1,000,000보다 작거나 같은 자연수이다.

// 출력
// 첫째 줄에 세준이가 갈 수 있는 가장 높은 곳의 높이를 출력한다.


#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m, t, d, a[30][30], dp[3000][3000], ret;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

vector<int> v;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> t >> d;
    for (int i=0; i<n; i++) {
        cin >> s;
        for (int j=0; j<m; j++) {
            if (s[j] >= 'a') a[i][j] = s[j] - 'a' + 26;
            else a[i][j] = s[j] - 'A';
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            v.push_back(i*100+j);       // 플로이드-워셜 알고리즘 순회하기위해 2차원좌표를 1차원좌표로 벡터 인덱스 만들어줌
        }
    }

    ret = a[0][0];
    fill(&dp[0][0], &dp[0][0] + 3000*3000, INF);
    
    // dp[i][j] 디피를 생성, 이때 디피는 2차원좌표 -> 2차원좌표로 표현하는데, 2차원좌표를 i*100+j 로 1차원형식으로 표현
    // dp는 각 지점들로 이동할때마다의 시간을 저장
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                int diff = abs(a[i][j]-a[ny][nx]);
                if (ny>=n || nx>=m || ny<0 || nx<0) continue;
                if (diff <= t) {
                    if (a[i][j]<a[ny][nx]) dp[i*100+j][ny*100+nx] = diff * diff;        // 이렇게 하려고 2차원을 1차원으로 바꾼거임
                    else dp[i*100+j][ny*100+nx] = 1;
                }

            }
        }
    }

    // 플로이드-워셜 조짐
    // 최단시간이 최단경로이므로
    // 주어진 시간동안 가장 높이 가야하므로
    for (int k: v) {
        for (int i: v) {
            for (int j: v) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    for(int i: v){
        if (d >= dp[0][i] + dp[i][0]) {         // 호텔 0에서 산 i + 산 i에서 호텔 0으로 왕복한 거리, 즉 그 시간이 어두워지기 전이면
            ret = max(ret, a[i/100][i%100]);    // 모든 산까지중에 최고 높이 구하기
        }
    }

    cout << ret << "\n";
    return 0;
}


// 플로이드-워셜 문제
// 2차원좌표를 1차원좌표로 바꿔 표현하기가 핵심

// dp 맵에서는 시간을 저장
// a 맵은 높이를 저장