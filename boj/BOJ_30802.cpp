/**
 * 웰컴 키트
 *
 * @author Chiwan Park
 * @solved 2025. 02. 03
 *
 * https://www.acmicpc.net/problem/30802
 */
#include <iostream>
#include <vector>

using namespace std;

namespace BOJ_30802 {
int do_main(int argc, const char *argv[]) {
  int n, t, p;
  vector<int> people;

  cin >> n;
  for (int i = 0; i < 6; ++i) {
    int m;
    cin >> m;
    people.push_back(m);
  }
  cin >> t >> p;

  int shirts = 0;
  for (int i = 0; i < 6; ++i) {
    shirts += people[i] / t + (people[i] % t > 0 ? 1 : 0);
  }
  cout << shirts << endl << n / p << " " << n % p;
  return 0;
}
} // namespace BOJ_30802

#ifndef DRIVER
int main(const int argc, const char *argv[]) { return BOJ_30802::do_main(argc, argv); }
#endif
