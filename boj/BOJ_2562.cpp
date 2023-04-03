/**
 * 최댓값
 *
 * @author Chiwan Park
 * @solved 2023. 04. 03
 *
 * https://www.acmicpc.net/problem/2562
 */
#include <iostream>

using namespace std;

namespace BOJ_2562 {
int do_main(int argc, const char *argv[]) {
  int v, m = 0, p = 0;
  for (int i = 0; i < 9; ++i) {
    cin >> v;
    if (v > m) {
      m = v;
      p = i;
    }
  }
  cout << m << '\n' << p + 1;
  return 0;
}
} // namespace BOJ_2562

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_2562::do_main(argc, argv); }
#endif
