/**
 * 검증수
 *
 * @author Chiwan Park
 * @solved 2025. 01. 28
 *
 * https://www.acmicpc.net/problem/2475
 */
#include <iostream>

using namespace std;

namespace BOJ_2475 {
int do_main(int argc, const char *argv[]) {
  int ret = 0;
  for (int i = 0; i < 5; ++i) {
    int n;
    cin >> n;
    ret = (ret + n * n) % 10;
  }
  cout << ret;
  return 0;
}
} // namespace BOJ_2475

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_2475::do_main(argc, argv); }
#endif
