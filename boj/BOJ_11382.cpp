/**
 * 꼬마 정민
 *
 * @author Chiwan Park
 * @solved 2023. 03. 25
 */
#include <iostream>

using namespace std;

namespace BOJ_11382 {
int do_main(int argc, const char *argv[]) {
  long long int a, b, c;
  cin >> a >> b >> c;
  cout << a + b + c;
  return 0;
}
} // namespace BOJ_11382

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_11382::do_main(argc, argv); }
#endif
