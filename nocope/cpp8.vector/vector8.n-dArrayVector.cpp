#include <vector>
#include <array>
using namespace std;


int main()
{
    array<array<int,3>, 3> fixedMatrix;
    vector<vector<int>> dynamicMatrix(3, vector<int>(3));

    fixedMatrix[0][0] = 1;

    array<array<int, 10>, 10> mat;

    for(int rowIdx=0; rowIdx<10; rowIdx++)
    {
        for(int colIdx=0; colIdx<10; colIdx++)
        {
            mat[rowIdx][colIdx] += 1;
        }
    }

    for(int colIdx=0; colIdx<10; colIdx++)                  // 이놈이 훨씬 느림
    {
        for(int rowIdx=0; rowIdx<10; rowIdx++)
        {
            mat[rowIdx][colIdx] += 1;
        }
    }
}


/*
메모리상에 한 row당 캐시라인이 생기는데, 캐시라인만큼 row가 들어옴
이너루프가 row이면 매번 이 캐시라인을 넘어가버림, 즉 캐시미스가 발생
그래서 매우 느려짐 
그런데 이너루프가 컬럼이면 캐시라인내의 데이터이기 때문에 빠를 수 밖에 없음, 메모리 접근에 낭비되는 시간을 최소화 
와 이너루프가 컬럼이 되는게 좋은 이유를 이제 알다니ㅋㅋㅋ

*/