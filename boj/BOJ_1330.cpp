/**
 * 두 수 비교하기
 *
 * @author Chiwan Park
 * @solved 2023. 04. 02
 *
 * https://www.acmicpc.net/problem/1330
 */
#include <iostream>

using namespace std;

namespace BOJ_1330 {
int do_main(int argc, const char *argv[]) {
  int a, b;
  cin >> a >> b;
  if (a > b) {
    cout << '>';
  } else if (a < b) {
    cout << '<';
  } else {
    cout << "==";
  }
  return 0;
}
} // namespace BOJ_1330

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_1330::do_main(argc, argv); }
#endif
