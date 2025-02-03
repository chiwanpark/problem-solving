/**
 * 직각삼각형
 *
 * @author Chiwan Park
 * @solved 2025. 02. 03
 *
 * https://www.acmicpc.net/problem/4153
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BOJ_4153 {


int do_main(int argc, const char *argv[]) {
  int a, b, c;
  while (true) {
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) {
      break;
    }

    vector<int> lengths = {a, b, c};
    sort(lengths.begin(), lengths.end());

    bool is_triangle = lengths[0] + lengths[1] > lengths[2];
    bool is_right_angled = lengths[0] * lengths[0] + lengths[1] * lengths[1] == lengths[2] * lengths[2];
    if (is_triangle && is_right_angled) {
      cout << "right" << endl;
    } else {
      cout << "wrong" << endl;
    }
  }
  return 0;
}
} // namespace BOJ_4153

#ifndef DRIVER
int main(const int argc, const char *argv[]) { return BOJ_4153::do_main(argc, argv); }
#endif
