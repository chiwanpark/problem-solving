/**
 * 문자열 반복
 *
 * @author Chiwan Park
 * @solved 2023. 04. 03
 *
 * https://www.acmicpc.net/problem/2675
 */
#include <iostream>
#include <string>

using namespace std;

namespace BOJ_2675 {
int do_main(int argc, const char *argv[]) {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int r;
    string s;

    cin >> r >> s;
    for (auto it = s.cbegin(), end = s.cend(); it != end; ++it) {
      for (int j = 0; j < r; ++j) {
        cout << *it;
      }
    }
    cout << '\n';
  }
  return 0;
}
} // namespace BOJ_2675

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_2675::do_main(argc, argv); }
#endif
