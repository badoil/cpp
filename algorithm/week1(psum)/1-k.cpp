// https://www.acmicpc.net/source/share/316bc219aa424428a8bc5ae767894d88

// 문제
// 임한수와 임문빈은 서로 사랑하는 사이이다.
// 임한수는 세상에서 팰린드롬인 문자열을 너무 좋아하기 때문에, 둘의 백일을 기념해서 임문빈은 팰린드롬을 선물해주려고 한다.
// 임문빈은 임한수의 영어 이름으로 팰린드롬을 만들려고 하는데, 임한수의 영어 이름의 알파벳 순서를 적절히 바꿔서 팰린드롬을 만들려고 한다.
// 임문빈을 도와 임한수의 영어 이름을 팰린드롬으로 바꾸는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 임한수의 영어 이름이 있다. 알파벳 대문자로만 된 최대 50글자이다.

// 출력
// 첫째 줄에 문제의 정답을 출력한다. 만약 불가능할 때는 "I'm Sorry Hansoo"를 출력한다. 정답이 여러 개일 경우에는 사전순으로 앞서는 것을 출력한다.

// AABB  -> ABBA
// ABACABA -> AABCBAA


#include<bits/stdc++.h>
using namespace std;

string s, ret;
int cnt[200], flag;
char mid;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> s;
    for(char c: s) cnt[c]++;
    for(int i='Z'; i>='A'; i--) {
        if (cnt[i]) {
            if (cnt[i] & 1){            // 플래그 연산, 이진수가 1로 끝나면 홀수임
                mid = cnt[i];
                flag++;                 // 홀수개 문자 카운팅
                cnt[i]--;               // 홀수에서 하나 빼줘서 짝수로 만듬, 밑에 포문에서 펠린드롬 문자 만들기 위해.
            }
            if (flag == 2) break;           // 홀수개 문자가 2개 이상 된다면 펠린드롬 문자 아님
            for(int j=0; j<cnt[i]; j+=2) {  // 펠린드롬 문자는 ret 압뒤로 같은 문자를 붙여가면서 만듬
                ret = char(i) + ret;
                ret += char(i);
            }
        }
    }
    if (mid) ret.insert(ret.begin() + ret.size()/2, mid);   // 만든 짝수 펠린드롬 문자에, mid가 있다면 가운데에 미드를 넣어줘서 완성
    if (flag == 2) cout << "sorry" << "\n";
    else cout << ret << "\n";

    return 0;
}


// 펠린드롬 만드는 문제임
// 오름차순으로 출력하기때문에 알파벳 끝에서 부터 내려오고
// 펠린드롬 문자열이라면 제일 뒤쪽 알파벳이 가운데에 오게됨   예) ABBCZCBBA

// 카운팅 배열을 만들고, 펠린드롬 아닌 문자를 우선 판별해야함
// 홀수개 문자가 2개 이상 된다면 펠린드롬 문자 아님
// 