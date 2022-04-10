#include <iostream>
#include <thread>
using namespace std;

void fn() 
{
    int a = 0;
    cout << "fn" << endl;
}

int main()
{
    cout << "process start" << endl;
    thread t1(fn);      //  쓰레드  t1 생성
    thread t2(fn);      //  쓰레드  t2 생성
    thread t3([]{       //  람다쓰레드 생성도 가능
        int a = 0;
        cout << "lambda thread" << endl;
    });

    t1.join();          // 메인 쓰레드가 t1, t2 끝나기를 기다림             
    t2.join();

    cout << "process end" << endl;
}