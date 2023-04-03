/**
 * 음계
 *
 * @author Chiwan Park
 * @solved 2023. 04. 03
 *
 * https://www.acmicpc.net/problem/2920
 */
#include <iostream>

using namespace std;

namespace BOJ_2920 {
int do_main(int argc, const char *argv[]) {
  int p = -1, v;
  string ans;
  for (int i = 0; i < 8; ++i) {
    cin >> v;
    if (p == -1) {
      p = v;
      continue;
    }
    if (p < v) {
      if (ans.empty() || ans == "ascending") {
        ans = "ascending";
      } else {
        ans = "mixed";
        break;
      }
    } else {
      if (ans.empty() || ans == "descending") {
        ans = "descending";
      } else {
        ans = "mixed";
        break;
      }
    }
    p = v;
  }
  cout << ans;
  return 0;
}
} // namespace BOJ_2920

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_2920::do_main(argc, argv); }
#endif
