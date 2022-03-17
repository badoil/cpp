#include <iostream>

namespace mySpace {
  int twoNumbers(int a, int b) {
    return a + b;
  }
}

namespace mySpace2 {
  int twoNumberss(int a, int b) {
    return a * b;
  }
}

using namespace std;

int main(void) {
  using namespace mySpace;
  using namespace mySpace2;
  cout << twoNumbers(1,3) << endl;
}