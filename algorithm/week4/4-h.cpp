// 문제
// 대략 위의 그림과 같이 생긴 성곽이 있다. 굵은 선은 벽을 나타내고, 점선은 벽이 없어서 지나다닐 수 있는 통로를 나타낸다. 이러한 형태의 성의 지도를 입력받아서 다음을 계산하는 프로그램을 작성하시오.

// 1. 이 성에 있는 방의 개수
// 2. 가장 넓은 방의 넓이
// 3, 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
// 위의 예에서는 방은 5개고, 가장 큰 방은 9개의 칸으로 이루어져 있으며, 위의 그림에서 화살표가 가리키는 벽을 제거하면 16인 크기의 방을 얻을 수 있다.
// 성은 M × N(1 ≤ M, N ≤ 50)개의 정사각형 칸으로 이루어진다. 성에는 최소 두 개의 방이 있어서, 항상 하나의 벽을 제거하여 두 방을 합치는 경우가 있다.

// 입력
// 첫째 줄에 두 정수 N, M이 주어진다. 다음 M개의 줄에는 N개의 정수로 벽에 대한 정보가 주어진다. 벽에 대한 정보는 한 정수로 주어지는데, 
// 서쪽에 벽이 있을 때는 1을, 북쪽에 벽이 있을 때는 2를, 동쪽에 벽이 있을 때는 4를, 남쪽에 벽이 있을 때는 8을 더한 값이 주어진다. 
// 참고로 이진수의 각 비트를 생각하면 쉽다. 따라서 이 값은 0부터 15까지의 범위 안에 있다.

// 출력
// 첫째 줄에 1의 답을, 둘째 줄에 2의 답을, 셋째 줄에 3의 답을 출력한다.


// 예제 입력 1                 예제 출력 1 
// 7 4                       5
// 11 6 11 6 3 10 6          9
// 7 9 6 13 5 15 5           16
// 1 10 12 7 13 7 5
// 13 11 10 8 10 12 13



#include<bits/stdc++.h>
using namespace std;


int n, m, a[54][54], visited[54][54], roomSize[2504], cnt, bigRoom, mx;
int dy[4] = { 0, -1, 0, 1 };        // 방의 개폐가 동서남북 순으로 표현된다고 햇으므로 그에 맞춰서 좌표 설정
int dx[4] = { -1, 0, 1, 0 };


int dfs(int y, int x, int id) {
    if (visited[y][x]) return 0;
    visited[y][x] = id;     // visited에 1만으로 채우는게 아니라 방의 id로 채워서 식별
    int ret = 1;    // 방의 사이즈               
    for (int i=0; i<4; i++) {
        if (!(a[y][x] & (1<<i))) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            ret += dfs(ny, nx, id);   // 방 사이즈 누적
        }
    }
    return ret;
}


int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (!visited[i][j]) {
                cnt++;
                roomSize[cnt] = dfs(i, j, cnt);         // roomSize에 방번호(cnt)마다 리턴받은 방의 크기(ret) 저장
                bigRoom = max(bigRoom, roomSize[cnt]);
            }
        }
    }
    
    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (i+1 < n) {          // 행으로 내려갈때 마지막 행 이상으로 내려가면 안되므로
                int a = visited[i+1][j];    // id로 구획된 방들, 즉 이 값은 id
                int b = visited[i][j];
                if (a != b) mx = max(mx, roomSize[a]+roomSize[b]);  // 벽을 허물어 방을 합치는 것을 표현
            }

            if (j+1 < m) {          // 행으로 내려갈때 마지막 행 이상으로 내려가면 안되므로
                int a = visited[i][j+1];
                int b = visited[i][j];
                if (a != b) mx = max(mx, roomSize[a]+roomSize[b]);
            }
        }
    }

    cout << cnt << "\n" << bigRoom << "\n" << mx << "\n";
    return 0;
}



// 이 문제의 포인트는 한칸의 동서남북 방향의 개폐 여부를 정수로 나타내고
// 이를 비트마스킹으로 체크한다는 점
// 커넥티드 컴포넌트를 구함
// visited에 1만으로 채우는게 아니라 방의 id로 채워서 식별
// roomSize에 방번호(cnt)마다 리턴받은 방의 크기(ret) 저장
// 이때 방번호는 visited 에 저장되어 있음