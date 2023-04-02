/**
 * 정수 삼각형
 *
 * @author Chiwan Park
 * @solved 2023. 04. 03
 *
 * https://www.acmicpc.net/problem/1932
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace BOJ_1932 {
int do_main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> Dprev(n, 0), Dcurr(n, 0);
  for (int i = 0; i < n; ++i) {
    swap(Dcurr, Dprev);
    for (int j = 0; j < i + 1; ++j) {
      int v;
      cin >> v;
      Dcurr[j] = Dprev[j];
      if (j > 0) {
        Dcurr[j] = max(Dcurr[j], Dprev[j - 1]);
      }
      Dcurr[j] += v;
    }
  }
  cout << *max_element(Dcurr.begin(), Dcurr.end());
  return 0;
}
} // namespace BOJ_1932

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_1932::do_main(argc, argv); }
#endif
