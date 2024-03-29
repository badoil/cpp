// 문제
// 두 종류의 부등호 기호 ‘<’와 ‘>’가 k개 나열된 순서열 A가 있다. 우리는 이 부등호 기호 앞뒤에 서로 다른 한 자릿수 숫자를 넣어서 모든 부등호 관계를 만족시키려고 한다. 
// 예를 들어, 제시된 부등호 순서열 A가 다음과 같다고 하자. 

// A ⇒ < < < > < < > < >

// 부등호 기호 앞뒤에 넣을 수 있는 숫자는 0부터 9까지의 정수이며 선택된 숫자는 모두 달라야 한다. 아래는 부등호 순서열 A를 만족시키는 한 예이다. 

// 3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0

// 이 상황에서 부등호 기호를 제거한 뒤, 숫자를 모두 붙이면 하나의 수를 만들 수 있는데 이 수를 주어진 부등호 관계를 만족시키는 정수라고 한다. 
// 그런데 주어진 부등호 관계를 만족하는 정수는 하나 이상 존재한다. 
// 예를 들어 3456128790 뿐만 아니라 5689023174도 아래와 같이 부등호 관계 A를 만족시킨다. 

// 5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4

// 여러분은 제시된 k개의 부등호 순서를 만족하는 (k+1)자리의 정수 중에서 최댓값과 최솟값을 찾아야 한다. 
// 앞서 설명한 대로 각 부등호의 앞뒤에 들어가는 숫자는 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }중에서 선택해야 하며 선택된 숫자는 모두 달라야 한다. 

// 입력
// 첫 줄에 부등호 문자의 개수를 나타내는 정수 k가 주어진다. 
// 그 다음 줄에는 k개의 부등호 기호가 하나의 공백을 두고 한 줄에 모두 제시된다. k의 범위는 2 ≤ k ≤ 9 이다. 

// 출력
// 여러분은 제시된 부등호 관계를 만족하는 k+1 자리의 최대, 최소 정수를 첫째 줄과 둘째 줄에 각각 출력해야 한다. 
// 단 아래 예(1)과 같이 첫 자리가 0인 경우도 정수에 포함되어야 한다. 모든 입력에 답은 항상 존재하며 출력 정수는 하나의 문자열이 되도록 해야 한다. 


#include<bits/stdc++.h>
using namespace std;


int k, check[10];
char a[20];
vector<string> v;

bool good(char a, char b, char oper) {          // 부등식 만족하는 판별하는 함수
    if (oper=='>' && a>b) return true;
    if (oper=='<' && a<b) return true;
    return false;
}

void go(int idx, string num) {
    if (idx-1 == k) v.push_back(num); return;

    for (int i=0; i<9; i++) {
        if (check[i]) continue;
        if (idx==0 || good(num[idx-1], i+'0', a[idx-1])) {      // i+'0' int를 char 로 형변환
            check[i] = 1;
            go(idx+1, num+to_string(i));
            check[i] = 0;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k;
    for(int i=0; i<k; i++) {
        cin >> a[i];
    }

    go(0, "");
    sort(v.begin(), v.end());

    cout << v[v.size()-1] << "\n";
    cout << v[0] << "\n";
    
}



// 시간 복잡도 10!
// 362만 정도, 충분히 완전탐색 할 수 있는 문제
// 오퍼레이터 a 와 num 을 순서대로 체크하면서 재귀함수 호출
// 포인트는 num 이 문자열이라는 것. 부등호를 만족하는 하나의 숫자로 봐야하는데 이는 문자열로 만드는게 편함
// 부등호를 만족하는 여러 숫자 집합(숫자로된 문자열)을 비교해서 최대와 최소 출력하기 때문에
// 그래서 재귀함수 호출할때마다 인덱스와 추가된 num 문자열을 인자로 담는 것임