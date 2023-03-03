// https://www.acmicpc.net/source/share/9815cd371fe643f59ac17a410e0cfca4

// 문제
// 눈금의 간격이 1인 M×N(M,N≤100)크기의 모눈종이가 있다. 이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때, 
// 이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.
// 예를 들어 M=5, N=7 인 모눈종이 위에 <그림 1>과 같이 직사각형 3개를 그렸다면, 그 나머지 영역은 <그림 2>와 같이 3개의 분리된 영역으로 나누어지게 된다.

// <그림 2>와 같이 분리된 세 영역의 넓이는 각각 1, 7, 13이 된다.
// M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때, K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지, 
// 그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. M, N, K는 모두 100 이하의 자연수이다. 
// 둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값이 빈칸을 사이에 두고 차례로 주어진다. 
// 모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다. 입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.

// 출력
// 첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다. 둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다.


#include<bits/stdc++.h>
using namespace std;

int b1, b2, a1, a2, a[104][104], visited[104][104], ny, nx;
int dy[4] = { -1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<int> v;

int dfs(int y, int x) {
    visited[y][x] = 1;
    int cnt = 1;
    for (int i=0; i<4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny<0 || ny>=100 || nx<0 || nx>=100) continue;
        if (visited[ny][nx]==0 && a[ny][nx]==0) {
            cnt += dfs(ny, nx);
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> b1 >> b2 >> a1 >> a2;        // 사각형을 지정해준다
    for(int i=b1; i<b2; i++) {
        for(int j=a1; j<a2; i++) {
            a[i][j] = 1;
        }
    }
    
    for(int i=0; i<104; i++) {
        for(int j=0; j<104; j++) {
            if(a[i][j]==0 && visited[i][j]==0) {
                v.push_back(dfs(i, j));
            }
        }
    }

    cout << v.size() << "\n";
    
    sort(v.begin(), v.end());
    for(int a: v) {
        cout << a << " ";
    }
    return 0;
    
}


// 지정한 영역외의 connected component의 사각형 갯수를 구하는 문제, 즉 dfs 문제
// dfs 함수에 리턴값이 int 인 것이 포인트
// dfs를 재귀적으로 호출할때 connected component 영역의 부분인 사각형 1씩이 더해지는 셈
// 결국 dfs 함수는 connected component 영역만큼 호출되는 것이기 때문에
// 호출횟수가 곧 영역의 갯수, 즉 넓이가 된다.
// 이 값을 벡터에 넣고 사이즈와 각 원소들을 출력하면 끝