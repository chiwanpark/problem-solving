/**
 * N 찍기
 *
 * @author Chiwan Park
 * @solved 2025. 01. 28
 *
 * https://www.acmicpc.net/problem/2741
 */
#include <iostream>

using namespace std;

namespace BOJ_2741 {
int do_main(int argc, const char *argv[]) {
  int N;
  ios::sync_with_stdio(false);
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cout << i << "\n";
  }
  return 0;
}
} // namespace BOJ_2741

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_2741::do_main(argc, argv); }
#endif
