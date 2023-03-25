/**
 * A/B
 *
 * @author Chiwan Park
 * @solved 2023. 03. 25
 *
 * https://www.acmicpc.net/problem/1008
 */
#include <iomanip>
#include <iostream>

using namespace std;

namespace BOJ_1008 {
int do_main(int argc, const char *argv[]) {
  double a, b;
  cin >> a >> b;
  cout << fixed << setprecision(10) << a / b;
  return 0;
}
} // namespace BOJ_1008

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_1008::do_main(argc, argv); }
#endif
