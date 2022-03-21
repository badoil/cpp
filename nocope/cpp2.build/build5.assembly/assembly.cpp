double multiply(double a, double b)
{
  return a * b;
};

double devide(double a, double b)
{
  return a / b;
};


// 그냥 곱셈과 비트를 사용한 것이 컴파일 과정에서 동일, 비트가 더 빠르지 않음
unsigned int num8x(unsigned int a)
{
  return a*8;
}

unsigned int num8x_2(unsigned int a)
{
  return a<<3;
}


// 위에는 idiv, 아래는 imul로 어셈블리 코드가 생성되는데, 
// devide 함수가 devideBy13보다 어셈블리 코드 길이가 더 길지만 idiv보다 imul의 처리 속도가 5배 빠름
int devide(int a, int b)
{
  return a / b;
};

int devideBy13(int a)
{
  return a / 13;
};


/*
assembly를 직접 볼일은 없다. 벤치마크나 프로파일을 봐야됨
그러나 학습 중이라 해보는 것

1. 어셈블리를 봄으로서 각 컴파일마다 어떻게 최적화를 해주는지 알 수 있음
2. 각 아키텍쳐마다 어떻게 머신코드가 생성되는 알 수 있음
노코프는 인텔 x86-64 아키텍쳐 사용

이 assembly.cpp 파일을 g++ assembly.cpp -S 옵션으로 컴파일하면
assembly.s 라는 어셈블리 파일이 생김
어셈블리 파일로 보는건 비효율적이기 때문에

compiler explorer 사용하는 것이 더 이해하기 편함
위의 함수들은 어셈블리 코드로 보았을때 효율성을 비교한 것임

if else 보다 switch case 가 더 빠른 것은 사실이나 이것도 컴파일러에 따라서 동일한
속도를 가질 수 있음. clang 컴파일러는 이 둘이 동일

결론적으로 모던 컴파일러들이 가독성을 해치지 않는 범위에서 충분히 최적화를 해줌

*/