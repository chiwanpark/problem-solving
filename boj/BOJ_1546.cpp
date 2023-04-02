/**
 * 평균
 *
 * @solved Chiwan Park
 * @author 2023. 04. 02
 *
 * https://www.acmicpc.net/problem/1546
 */
#include <algorithm>
#include <iostream>

using namespace std;

namespace BOJ_1546 {
int do_main(int argc, const char *argv[]) {
  int N, score, sum_score = 0, max_score = 0;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> score;
    sum_score += score;
    max_score = max(max_score, score);
  }
  cout << (double)sum_score / max_score * 100 / N;
  return 0;
}
} // namespace BOJ_1546

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_1546::do_main(argc, argv); }
#endif
