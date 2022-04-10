#include <iostream>
#include <thread>
#include <vector>
using namespace std;

thread gThread;
void fn() 
{
    cout << "fn" << endl;
    cout << this_thread::get_id() << endl;      // 쓰레드 아이디
}

void threadCaller()
{
    gThread = thread(fn);
}

int main()
{
    thread t1(fn);      
    thread t2{move(t1)};        //  t1의 소유권을 t2에게
    t2.join();              //  t1의 소유권을 t2에게 줫기 때문에 t2를 기다려야함

    threadCaller();
    gThread.join();

    cout << "thread count: " << thread::hardware_concurrency() << endl;     // thread의 갯수

    vector<thread> threads;         // 쓰레드를 벡터로 여러개 만들 수 잇음
    for(int i=0; i<10; i++)
    {
        threads.emplace_back(fn);
    }
    for(auto & thread: threads)
    {
        thread.join();
    }

}


/*
thread는 클래스, thread를 생성한다는 것은 쓰레드 오브젝트를 생성하는것
따라서 생성자, 소멸자 존재
이때 함수를 thread와 같이 던져줘야 쓰레드가 활성화됨

copy contructor 는 삭제됨
*/