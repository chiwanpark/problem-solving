/**
 * 별 찍기 - 2
 *
 * @author Chiwan Park
 * @solved 2023. 04. 03
 *
 * https://www.acmicpc.net/problem/2439
 */
#include <iostream>

using namespace std;

namespace BOJ_2439 {
int do_main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ((j < n - i - 1) ? ' ' : '*');
    }
    cout << '\n';
  }
  return 0;
}
} // namespace BOJ_2439

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_2439::do_main(argc, argv); }
#endif
