/**
 * 별 찍기 - 1
 *
 * @author Chiwan Park
 * @solved 2023. 04. 03
 *
 * https://www.acmicpc.net/problem/2438
 */
#include <iostream>

using namespace std;

namespace BOJ_2438 {
int do_main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      cout << '*';
    }
    cout << '\n';
  }
  return 0;
}
} // namespace BOJ_2438

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_2438::do_main(argc, argv); }
#endif
