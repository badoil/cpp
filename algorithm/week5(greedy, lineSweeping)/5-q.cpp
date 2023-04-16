// 문제
// 어젯밤 겨울 캠프 장소에서 월드 본원까지 이어지는, 흙으로 된 비밀길 위에 폭우가 내려서 N (1 <= N <= 10,000) 개의 물웅덩이가 생겼다. 
// 월드학원은 물웅덩이를 덮을 수 있는 길이 L (L은 양의 정수) 짜리 널빤지들을 충분히 가지고 있어서, 이들로 다리를 만들어 물웅덩이들을 모두 덮으려고 한다. 
// 물웅덩이들의 위치와 크기에 대한 정보가 주어질 때, 모든 물웅덩이들을 덮기 위해 필요한 널빤지들의 최소 개수를 구하여라.

// 입력
// 첫째 줄에 N과 L이 들어온다.
// 둘째 줄부터 N+1번째 줄까지 총 N개의 줄에 각각의 웅덩이들의 정보가 주어진다. 웅덩이의 정보는 웅덩이의 시작 위치와 끝 위치로 이루어진다. 각 위치는 0이상 1,000,000,000이하의 정수이다.

// 출력
// 첫째 줄에 모든 물웅덩이들을 덮기 위해 필요한 널빤지들의 최소 개수를 출력한다.



#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, l, idx, b, ret;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;
    vector<pair<int, int>> a(n);

    for (int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    
    sort(a.begin(), a.end());
    
    for(int i=0; i<n; i++) {
        if (a[i].second <= idx) continue;       // 이미 있는 널빤지가 이미 물웅덩이를 덮고 있는 경우
        if (a[i].first > idx) {                 // 이미 있는 널빤지가 새 물웅덩이를 못 덭는 경우
            b = ((a[i].second - a[i].first)/l) + ((a[i].second - a[i].first) % l ? 1 : 0);  // 널판지 갯수
            ret += b;
            idx = a[i].first + b*l;
        } else {                                // 이미 있는 널빤지가 새 물웅덩이를 부분적으로 덮는 경우
            b = ((a[i].second - idx)/l) + ((a[i].second - idx) % l ? 1 : 0);    // 널판지 갯수
            ret += b;
            idx = idx + b*l;
        }
    }

    cout << ret << "\n";
    return 0;
}




// 카운팅 배열 생각할수도 있는데, 배열이 길이라고 했을때 10억개의 크기인 배열이므로
// 배열은 못씀
// 고로 벡터 사용
// 웅덩이의 시작점과 끝점을 놓여진 널빤지의 끝점과 비교하면서 
// 최소한의 널빤지 개수를 더해 나감