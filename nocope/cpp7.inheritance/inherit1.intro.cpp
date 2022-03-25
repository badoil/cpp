class Base
{
  private:
    int pri;

  protected:
    int pro;

  public:
    void setPri(int i)
    {
      pri = i;
    }
    void setPro(int i)
    {
      pro = i;
    }
};

class Derived : public Base
{
  public:
    void test()
    {
      Base::pro = 10;
      // Base::pri = 100;   // 자식 클래스는 부모클래스의 private 변수에 직접 접근 불가
    }
};

int main(int argc, char const *argv[])
{
  Derived derived;
  derived.setPri(10);
  derived.setPro(10);

  return 0;
}





/*
1. class relationship
2. code reuse
3. class interface consistency
  - abstract / interface
  - pure virtual function
4. dynamic function binding
  - virtual function
  - virtual table


class Derived : public Base
- 이경우 Base 클래스는 public, protected 모두 그대로고 접근가능하지만 private 접근 불가

class Derived : protected Base
- Base 클래스의 public 이 protected 로 변하고 setPri, setPro 모두 접근 불가

class Derived : private Base
-  Base 클래스의 public, protected 이 private 으로 되고 접근 불가

*/