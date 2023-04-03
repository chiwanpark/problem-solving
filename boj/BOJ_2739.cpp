/**
 * 구구단
 *
 * @author Chiwan Park
 * @solved 2023. 04. 03
 *
 * https://www.acmicpc.net/problem/2739
 */
#include <iostream>

using namespace std;

namespace BOJ_2739 {
int do_main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  for (int i = 1; i <= 9; ++i) {
    cout << n << " * " << i << " = " << n * i << "\n";
  }
  return 0;
}
} // namespace BOJ_2739

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_2739::do_main(argc, argv); }
#endif
