// https://www.acmicpc.net/problem/17611
// 문제
// 다각형의 두 선분이 연속하는 선분의 꼭짓점을 제외하고는 만나지 않는 다각형을 단순다각형이라고 부른다. 
// 다각형의 각 변이 x축과 y축에 평행한 다각형을 직각다각형이라 부른다. 단순다각형이면서 직각다각형을 단순직각다각형이라 부른다. 
// 아래 두 그림은 단순직각다각형의 예를 보여준다. 


// 단순직각다각형이 주어질 때, 수평선 H가 다각형의 수직선분과 몇 번 교차하는지 또는 수직선 V가 다각형의 수평선분과 몇 번 교차하는지 알고자 한다. 
// 첫 번째 그림에서 수평선 H는 4개의 수직선분과 교차하고 수직선 V는 2개의 수평선분과 교차한다. 
// 두 번째 그림은 첫 번째 그림에서 수평선 H의 위치를 조금 위로 옮긴 것으로 8개의 수직선분과 교차하게 된다. 
// 이때, 단순직각다각형과 가장 많이 교차하는 수평선 H와 수직선 V의 위치를 찾아 그때의 교차 횟수를 구하고자 한다. 
// 단, 수평선 H는 다각형의 어떤 수평선분과도 겹처 놓여서는 안 되고, 유사하게 수직선 V는 다각형의 어떤 수직선분과도 겹쳐 놓여서는 안 된다.

// 수평선 H의 위치를 잘 정해서 주어진 단순직각다각형의 수직선분과 가장 많이 교차하는 지점을 찾을 때, 그 때의 교차 횟수를 h라 하고, 
// 유사하게 수직선 V와 주어진 단순직각다각형의 수평선분과 가장 많이 교차하는 횟수를 v라 할 때, max(h, v)를 출력하는 프로그램을 작성하시오.

// 입력
// 입력의 첫 줄에는 단순직각다각형의 꼭지점의 개수를 나타내는 정수 n(4 ≤ n ≤ 100,000)이 주어지고, 
// 이어지는 n개 줄 각각에 단순직각다각형 꼭지점의 좌표 (xi, yi)가 차례대로 주어진다. 주어지는 꼭지점들의 순서는 시계방향이다. 
// 다각형의 꼭지점을 나타내는 각 좌표값은 정수이며, -500,000 ≤ xi, yi ≤ 500,000이다.

// 출력
// max(h, v)를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int n, y, x, x1, y1, x2, y2, ret, _x[1000004], _y[1000004];
pair<int, int> a[100004];
vector<int>  check_y, check_x;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> y >> x;
        y += 500000;
        x += 500000;
        a[i] = {y, x};
        check_y.push_back(y);
        check_x.push_back(x);
    }

    a[n] = a[0];
    for (int i=0; i<n; i++) {
        tie(y1, x1) = a[i];
        tie(y2, x2) = a[i+1];
        if (y1>y2) swap(y1, y2);
        for (int j=y1+1; j<=y2; j++) {
            _y[j]++;                    // 이렇게 하면 y 선분이 만들어짐, 같은 j 값이라는 것은 그 점으로 이루어진 선이 여러개 있다는 의미
        }

        if (x1>x2) swap(x1, x2);
        for (int j=x1+1; j<=x2; j++) {
            _x[j]++;                    // x 선분 만들기
        }
    }

    for(int a : check_y) ret = max(ret, _y[a]); 
    for(int a : check_x) ret = max(ret, _x[a]);   
    cout << ret << "\n";
}



// 카운팅 배열 이용하기
// 카운팅 배열로 해당 인덱스에 해당하는 선들을 카운팅
// 이 카운팅된 것이 해당 지점을 지나면 만나게되는 점들임