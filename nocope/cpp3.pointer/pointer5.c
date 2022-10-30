#include <stdio.h>

int main () {
    int aList[5] = {10, 20, 30, 40, 50};

    // a
    int total = 0;
    for (int i=0; i<5; i++) {
        total += aList[i];
    }
    printf("total: %d", total);

    total = 0;
    int* paList = aList;        // paList 포인터에 aList 주소 할당

    // b
    while(paList < aList+5){            // aList는 aList+4 까지 있음(인덱스 0부터), 즉 aList 끝날때까지 순회하라는 뜻 
        total += *paList;               // paList 포인터 간접지정으로 값을 지정하고 그 값에 누산
        paList++;
    }
    printf("total: %d", total);

    return 0;

}


// a, b 는 동일한 결과 total 값을 출력할것
// 물론 a가 직관적인 좋은 코드이지만
// b를 이해햐면 포인터 이해한 것임