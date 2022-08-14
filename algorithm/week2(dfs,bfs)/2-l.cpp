// https://www.acmicpc.net/source/share/5d5e7e5459524080abec73ee77de2fbe

// 문제
// 동혁이는 NBA 농구 경기를 즐겨 본다. 동혁이는 골이 들어갈 때 마다 골이 들어간 시간과 팀을 적는 이상한 취미를 가지고 있다.
// 농구 경기는 정확히 48분동안 진행된다. 각 팀이 몇 분동안 이기고 있었는지 출력하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 골이 들어간 횟수 N(1<=N<=100)이 주어진다. 둘째 줄부터 N개의 줄에 득점 정보가 주어진다. 득점 정보는 득점한 팀의 번호와 득점한 시간으로 이루어져 있다. 팀 번호는 1 또는 2이다. 득점한 시간은 MM:SS(분:초) 형식이며, 분과 초가 한자리 일 경우 첫째자리가 0이다. 분은 0보다 크거나 같고, 47보다 작거나 같으며, 초는 0보다 크거나 같고, 59보다 작거나 같다. 득점 시간이 겹치는 경우는 없다.

// 출력
// 첫째 줄에 1번 팀이 이기고 있던 시간, 둘째 줄에 2번 팀이 이기고 있던 시간을 출력한다. 시간은 입력과 같은 형식(MM:SS)으로 출력한다.


// 예제 입력       예제 출력 
// 5
// 1 01:10      45:30
// 1 02:20      00:10
// 2 45:30
// 2 46:40
// 2 47:50

#include<bits/stdc++.h>
using namespace std;


int n, t, a, b, asum, bsum;
string s, previ;

string print(int sum) {
    string m = "00" + to_string(sum/60);
    string s = "00" + to_string(sum%60);
    return m.substr(m.size()-2, 2) + ":" + s.substr(s.size()-2, 2);     // m.size()-2 하는이유는 암의 00을 포함하거나 빼주기 위해서임
}

int second(string s) {
    return atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3, 2).c_str());    // atoi는 char -> int, c_str은 string -> char 로 바꿈
}

void go(int &sum, string s) {           // go함수에서 각 팀의 이기고 있는 총 시간을 더하면서 업뎃함
    sum += (second(s) - second(previ));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> t >> s;
        if (a>b) go(asum, s);   // 현재(s)까지 이기고 있으니깐 바로 전에 골넣은 시간과 현재 시간 빼줘서 그 값을 asum 이나 bsum에 계속 더해줘야함
        else go(bsum, s);
        t == 1 ? a++ : b++;
        previ = s;              // 다음 포문 인덱스에서 asum 이나 bsum을 구하기 위해서 previ(바로 전에 골넣은 시간)이 필요
    }

    if (a>b) go(asum, "48:00");     // 끝나는 시간까지 계사해줘야함 
    else go(bsum, "48:00");
    
    cout << print(asum) << "\n";
    cout << print(bsum) << "\n";

    return 0;
}

// 문제의 포인트는 2가지
// 1. 27:30, 이렇게 들어오면 계산하기 힘드니까 초로 환산
// 2. previ = s 이전 값을 할당해서 기억