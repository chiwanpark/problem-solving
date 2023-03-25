/**
 * A+B
 *
 * @author Chiwan Park
 * @solved 2013. 03. 16.
 *
 * https://www.acmicpc.net/problem/1000
 **/
#include <iostream>

using namespace std;

namespace BOJ_1000 {
int do_main(int argc, const char *argv[]) {
  int a, b;
  cin >> a >> b;
  cout << a + b;
  return 0;
}
} // namespace BOJ_1000

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_1000::do_main(argc, argv); }
#endif
