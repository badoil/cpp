#include <iostream>
#include <bitset>

using namespace std;

int main () {
  unsigned int a = 0b1100;
  unsigned int b = 0b0101;

  cout << std::bitset<4>(a & b) << endl; 
  cout << std::bitset<4>(a | b) << endl;
  cout << std::bitset<4>(a ^ b) << endl;

  return 0;
}