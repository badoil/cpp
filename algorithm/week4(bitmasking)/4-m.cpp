// 문제
// 피카츄는 "pi", "ka", "chu"를 발음할 수 있다. 따라서, 피카츄는 이 세 음절을 합친 단어만 발음할 수 있다. 예를 들면, "pikapi"와 "pikachu"가 있다.
// 문자열 S가 주어졌을 때, 피카츄가 발음할 수 있는 문자열인지 아닌지 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 문자열 S가 주어진다. 문자열은 알파벳 소문자로 이루어진 문자열이며, 길이는 5000을 넘지 않는다.

// 출력
// 문자열 S가 "pi", "ka", "chu"를 이어 붙여서 만들 수 있으면 "YES"를 아니면 "NO"를 출력한다.


#include<bits/stdc++.h>
using namespace std;

string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool flag = false;
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        if (i<s.size()-1 && s.substr(i, 2)== "pi" || s.substr(i, 2) == "ka") i+=i+2;
        if (i<s.size()-2 && s.substr(i, 3)=="chu") i+=i+3;
        else flag = true;
    }
    if (flag) cout << "NO\n";
    else cout << "YES\n";

    return 0;
    
}


// substr 이용해서 포문 돌기
// 해당문자에 "pi", "ka", "chu" 없으면 flag = 1 만들어서
// 결과 출력