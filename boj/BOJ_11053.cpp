/**
 * 가장 긴 증가하는 부분 수열
 *
 * @author Chiwan Park
 * @solved 2023. 04. 06
 *
 * https://www.acmicpc.net/problem/11053
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace BOJ_11053 {
int N;
vector<int> Seq;
vector<int> Dy;

void do_dynamic() {
  Dy[0] = 1;
  for (int i = 1; i < N; ++i) {
    Dy[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (Seq[i] > Seq[j] && Dy[j] + 1 > Dy[i]) {
        Dy[i] = Dy[j] + 1;
      }
    }
  }
}

int do_main(int argc, const char *argv[]) {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int n;
    cin >> n;
    Seq.push_back(n);
  }

  Dy = vector<int>(N, 0);
  do_dynamic();

  cout << *max_element(Dy.begin(), Dy.end());
  return 0;
}
} // namespace BOJ_11053

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_11053::do_main(argc, argv); }
#endif
