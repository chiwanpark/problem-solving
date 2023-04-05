/**
 * 가장 긴 증가하는 부분 수열 5
 *
 * @author Chiwan Park
 * @solved 2023. 04. 06
 *
 * https://www.acmicpc.net/problem/14003
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;

namespace BOJ_14003 {
int N;
vector<int> Seq;
vector<int> LIS;
vector<int> Rev;
vector<int> Prev;

void find_LIS() {
  LIS.push_back(Seq[0]);
  Rev.push_back(0);
  Prev.push_back(-1);
  for (int i = 1; i < N; ++i) {
    if (*LIS.rbegin() < Seq[i]) {
      LIS.push_back(Seq[i]);
      Rev.push_back(i);
      Prev.push_back(Rev[LIS.size() - 2]);
    } else {
      auto l = lower_bound(LIS.begin(), LIS.end(), Seq[i]);
      auto idx = l - LIS.begin();
      *l = Seq[i];
      Rev[idx] = i;
      Prev.push_back(idx > 0 ? Rev[idx - 1] : -1);
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

  cout << LIS.size() << '\n';
  stack<int> s;
  s.push(*Rev.rbegin());
  do {
    s.push(Prev[s.top()]);
  } while (s.top() >= 0);
  while (!s.empty()) {
    if (s.top() >= 0) {
      cout << Seq[s.top()] << ' ';
    }
    s.pop();
  }
  return 0;
}
} // namespace BOJ_14003

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_14003::do_main(argc, argv); }
#endif
