/**
 * 곱셈
 *
 * @author Chiwan Park
 * @solved 2023. 04. 03
 *
 * https://www.acmicpc.net/problem/1629
 */
#include <iostream>

using namespace std;

namespace BOJ_1629 {

long long int get_mod(int a, int b, int c) {
  if (b == 1) {
    return a % c;
  }
  long long int sub_mod = get_mod(a, b / 2, c);
  if (b % 2 == 0) {
    return (sub_mod * sub_mod) % c;
  }
  return (((sub_mod * sub_mod) % c) * (a % c)) % c;
}

int do_main(int argc, const char *argv[]) {
  int a, b, c;
  cin >> a >> b >> c;
  cout << get_mod(a, b, c);
  return 0;
}
} // namespace BOJ_1629

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_1629::do_main(argc, argv); }
#endif
