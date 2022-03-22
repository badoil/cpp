#include <iostream>
using namespace std;

class alignas(32) Cat     // 32바이트 할당
{
  public:
    void speak();

  private:
    // double d8;     // 16bytes
    // int i4a;
    // int i4b;

    // int i4a;          // 24bytes
    // double d8;
    // int i4b;

    char c1;        // 24bytes = 1(c1) + 3(padding) + 4(i4a) + 4(i4b) + 4(padding) + 8(d8)
    int i4a;
    int i4b;
    double d8;

};


int main()
{
  Cat stackCat;
  cout << sizeof(stackCat) << endl;

  Cat cats[100];

  return 0;
}



/*
object in memory
class뿐만 아니라 struct도 동일


Cat 의 멤버변수 첫번째는 16bytes 가 나오고 순서만 바꾼 두번째는 24bytes가 나온다
이유는?
4바이트인 int는 오브젝트 내에서 4의 배수의 위치에서 시작되고
8바이트인 double은 8의 배수의 위체에서 시작
따라서 i4a 끝나고 4바이트 패딩을 넣고 8의 위치에서 시작
그리고 오브젝트 전체 사이즈는 오브젝트의 가장 큰 멤버 변수의 사이즈의 배수로 끝나야함
d8 다음에 바로 i4b가 오고 이게 4(i4a) + 4(패딩) + 8(d8) + 4(i4b) = 20 애서 끝나지 않고 4 패딩 더 넣음
4(i4a) + 4(padding) + 8(d8) + 4(i4b) + 4(padding)
d8 은 8바이트이겡 24에서 끝남


Cat cats[100] 해주면 
cpu는 보통 멀티코어로 되어있고 cahe 기능이 있음, 캐시의 가장 작은 기본단위인 cacheline이 64바이트임
고로 cats[3]의 16바이트에서 어레이 오브젝트가 쪼개짐, 즉 false sharing 문제 발생
이를 방지하기 위해 class alignas(32) Cat 해주어서 오브젝트 하나당 32바이트를 할당해버림
이 부부분은 병렬 프로그래밍 파트에서 다시 다룸

*/