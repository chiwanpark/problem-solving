/**
 * 가장 긴 증가하는 부분 수열 2
 *
 * @author Chiwan Park
 * @solved 2023. 04. 06
 *
 * https://www.acmicpc.net/problem/12015
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace BOJ_12015 {
int N;
vector<int> Seq;
vector<int> LIS;

void find_LIS() {
  LIS.push_back(Seq[0]);
  for (int i = 1; i < N; ++i) {
    if (*LIS.rbegin() < Seq[i]) {
      LIS.push_back(Seq[i]);
    } else {
      auto l = lower_bound(LIS.begin(), LIS.end(), Seq[i]);
      *l = Seq[i];
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

  find_LIS();

  cout << LIS.size();
  return 0;
}
} // namespace BOJ_12015

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_12015::do_main(argc, argv); }
#endif
