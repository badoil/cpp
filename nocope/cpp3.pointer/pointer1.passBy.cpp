void fooV(int a)
{
  int b = a+1;
}

void fooP(int * ap)
{
  int b = *ap + 1;
}

void fooR(int & a)
{
  int b = a + 1;
}


int main ()
{
  int a = 0;
  fooV(a);     // foo 함수에 a를 값으로 넘겨주고 이는 foo라는 스택 프레임이 a=0를 복사해서 넣은것
  fooP(&a);   // 포인터로 받으니, 포인터가 가리키는 주소를 넘김, 포인터로 매개변수를 받게되면 함수 바깥에 있는 그 변수에 접근 가능
  fooR(a);
  return 0;
}



/*
pass by value
        pointer
        reference
      
pass by value 는 복사로 값을 넘겨줌
pass by pointer 매개변수가 주소로 넘겨지고 그 변수를 포인터로 가리킴
pass by reference 포인터로 넘기는 것과 같음  compiler explorer 에서 확인 가능

매개변수가 큰 어레이값이면 pass by value 사용할 때 메모리를 많이 잡아먹음, 이럴때는 포인터나 레퍼런스 써야함
포인터가 꼭 필요한 경우 아니라면 레퍼런스를 사용, 포인터는 버그를 일이킬 수 있음
왜냐하면 포인터가 널포인터 에러를 발생시킬 가능성이 있기 때문


*/
