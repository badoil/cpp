// https://www.acmicpc.net/source/share/17cfa215dcf2499cafcbf8004a349c22

// 문제
// 좋은 패스워드를 만드는것은 어려운 일이다. 대부분의 사용자들은 buddy처럼 발음하기 좋고 기억하기 쉬운 패스워드를 원하나, 이런 패스워드들은 보안의 문제가 발생한다. 
// 어떤 사이트들은 xvtpzyo 같은 비밀번호를 무작위로 부여해 주기도 하지만, 사용자들은 이를 외우는데 어려움을 느끼고 심지어는 포스트잇에 적어 컴퓨터에 붙여놓는다. 
// 가장 이상적인 해결법은 '발음이 가능한' 패스워드를 만드는 것으로 적당히 외우기 쉬우면서도 안전하게 계정을 지킬 수 있다. 

// 회사 FnordCom은 그런 패스워드 생성기를 만들려고 계획중이다. 당신은 그 회사 품질 관리 부서의 직원으로 생성기를 테스트해보고 생성되는 패스워드의 품질을 평가하여야 한다. 
// 높은 품질을 가진 비밀번호의 조건은 다음과 같다.

// 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
// 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
// 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
// 이 규칙은 완벽하지 않다;우리에게 친숙하거나 발음이 쉬운 단어 중에서도 품질이 낮게 평가되는 경우가 많이 있다.

// 입력
// 입력은 여러개의 테스트 케이스로 이루어져 있다.
// 각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 테스트할 패스워드가 주어진다.
// 마지막 테스트 케이스는 end이며, 패스워드는 한글자 이상 20글자 이하의 문자열이다. 또한 패스워드는 대문자를 포함하지 않는다.

// 출력
// 각 테스트 케이스를 '예제 출력'의 형태에 기반하여 품질을 평가하여라.

#include<bits/stdc++.h>
using namespace std;

string s;
int lcnt, vcnt;

bool isVowel(int idx) {
    return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
    
}

int main () {
    while (true) {
        cin >> s;
        if(s == "end")break;

        lcnt = vcnt = 0 ;
        bool flag = 0;          // 불리언으로
        bool thereIsVowel = 0;  // 불리언으로
        int prev = -1;          // 
        for(int i=0; i<s.size(); i++) {
            int idx = s[i];
            if(isVowel(idx)) vcnt++,lcnt=0, thereIsVowel=1;         // vcnt, lcnt 는 모음 자음의 3개 연속 여부 체크하기 위해 카운팅
            else vcnt=0, lcnt++;                                    // 이번 글자가 모음이면 자음 카운팅은 0을 해주고, 자음이면 반대로 해줌
            if(lcnt==3 || vcnt==3) flag = 1;                        // vcnt, lcnt 중에 3이 있다면 연속으로 자음이나 모음이 온것임
            if(idx>0 && prev==idx && idx!='e' && idx!='o') flag = 1;// 전 글자와 현 글자가 동일

            prev = idx;     // 포문 넘어가기 전에 prev로 다음 포문의 전 인덱스를 만들어줌
        }
        if (thereIsVowel == 0) flag = 1;                                // 모음이 하나 이상 있어야 하므로, 만족 못시킴(flag=1)
        if (flag) cout << "<" << s << ">" << "is not acceptable \n";    // 만족 못시킴(flag=1)이면 is not acceptable
        else cout << "<" << s << ">" << "is acceptable \n";

    }
    return 0;
}

// 포문 돌면서 각 테트트 케이스마다 조건 만족하는지 여부 체크
// 변수를 어디에 위치시킬 것인가, prev = idx 테크닉, 자음/모음 연속 카운팅 테크닉 포인트