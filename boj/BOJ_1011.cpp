/**
 * Fly me to the Alpha Centauri
 *
 * @author Chiwan Park
 * @solved 2023. 03. 25
 *
 * https://www.acmicpc.net/problem/1011
 */
#include <cmath>
#include <iostream>

using namespace std;

namespace BOJ_1011 {
int do_main(int argc, const char *argv[]) {
  int T;
  long long int x, y;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> x >> y;

    long long int d = static_cast<long long int>(y - x);
    long long int n = static_cast<long long int>(sqrt(d));
    if (n * n == d) {
      cout << 2 * n - 1 << endl;
    } else if (d <= n * n + n) {
      cout << 2 * n << endl;
    } else if (d <= n * n + 2 * n) {
      cout << 2 * n + 1 << endl;
    }
  }
  return 0;
}
} // namespace BOJ_1011

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_1011::do_main(argc, argv); }
#endif
