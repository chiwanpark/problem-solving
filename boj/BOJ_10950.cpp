/**
 * A+B - 3
 *
 * @author Chiwan Park
 * @solved 2025. 02. 03
 *
 * https://www.acmicpc.net/problem/10950
 */
#include <iostream>

using namespace std;

namespace BOJ_10950 {
int do_main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
  }
  return 0;
}
} // namespace BOJ_10950

#ifndef DRIVER
int main(const int argc, const char *argv[]) { return BOJ_10950::do_main(argc, argv); }
#endif
