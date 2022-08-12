//https://www.acmicpc.net/source/share/5abff43b14d0489aac5c48a0a717c1a8


// 빈도정렬 문제
// 문제
// 위대한 해커 창영이는 모든 암호를 깨는 방법을 발견했다. 그 방법은 빈도를 조사하는 것이다.
// 창영이는 말할 수 없는 방법을 이용해서 현우가 강산이에게 보내는 메시지를 획득했다. 이 메시지는 숫자 N개로 이루어진 수열이고, 숫자는 모두 C보다 작거나 같다. 창영이는 이 숫자를 자주 등장하는 빈도순대로 정렬하려고 한다.
// 만약, 수열의 두 수 X와 Y가 있을 때, X가 Y보다 수열에서 많이 등장하는 경우에는 X가 Y보다 앞에 있어야 한다. 만약, 등장하는 횟수가 같다면, 먼저 나온 것이 앞에 있어야 한다.
// 이렇게 정렬하는 방법을 빈도 정렬이라고 한다.
// 수열이 주어졌을 때, 빈도 정렬을 하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 메시지의 길이 N과 C가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ C ≤ 1,000,000,000)

// 둘째 줄에 메시지 수열이 주어진다.

// 출력
// 첫째 줄에 입력으로 주어진 수열을 빈도 정렬한 다음 출력한다.


//예제 입력 1
// 5 2
// 2 1 2 1 2

// 예제 출력 1
// 2 2 2 1 1


#include<bits/stdc++.h>
using namespace std;

int n, c, a[1004];
map<int, int> mp, mp_first;
vector<pair<int, int>> v;


bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.first == b.first) return mp_first[a.second] < mp_first[b.second];     // 등장하는 횟수가 같다면, 먼저 나온 것이 앞에 있어야 함
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;

    for (int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        if (mp_first[a[i]]==0) mp_first[a[i]] = 1+i;
    }
    
    for (auto a: mp) {
        v.push_back({a.second, a.first});   // '해당수':'카운팅' -> '카운팅':'해당수'  자리 바꿈 , 그런데 굳이 자리바꿀 필요 있나 싶음. 그냥 그대로 해도 될듯, 물론 이때는 cmp 좀 수정필요할듯
    }
    sort(v.begin(), v.end(), cmp);

    for (auto a: v) {
        for(int i=0; i<a.first; i++) {      // 카운팅 수만큼 반복해서
            cout << a.second << " ";        // 해당 수를 출력
        }
    }
    return 0;
}


// 빈도정렬은 입력한 수열을 맵에 '해당수':'카운팅' 식으로 입력하고
// 이놈을 정렬하기 위해 튜플로 만들어서 벡터에 집어넣음
// 정렬을 위해서 커스텀 정렬 cmp 사용