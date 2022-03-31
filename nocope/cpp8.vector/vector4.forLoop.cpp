#include <chrono>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
  cout << "how many elements??" << endl;
  size_t n;
  cin >> n;

  vector<int> numsA(n, 1);
  vector<int> numsB(n, 1);
  vector<int> numsC(n, 1);

  auto start = chrono::high_resolution_clock::now();
  // index
  for (int idx=0; idx<1000; idx++) {
  for(int idx=0; idx<numsA.size(); idx++)
  {
    numsA[idx] *= 2;
  }}
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> diff = end-start;
  cout << "idx base: " << diff.count() << endl;

  auto start2 = chrono::high_resolution_clock::now();
  // iterator base
  for (int idx=0; idx<1000; idx++) {
  for(auto itr=numsB.begin(); itr != numsB.end(); itr++)
  {
    (*itr) *= 2;
  }}
  auto end2 = chrono::high_resolution_clock::now();
  chrono::duration<double> diff2 = end2-start2;
  cout << "itr base: " << diff2.count() << endl;

  auto start3 = chrono::high_resolution_clock::now();
  // range base
  for (int idx=0; idx<1000; idx++) {
  for(int num: numsC)
  {
    num *= 2;
  }}
  auto end3 = chrono::high_resolution_clock::now();
  chrono::duration<double> diff3 = end3-start3;
  cout << "range base: " << diff3.count() << endl;

  return 0;

}