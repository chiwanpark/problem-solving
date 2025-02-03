/**
 * 좌표 압축
 *
 * @author Chiwan Park
 * @solved 2025. 02. 03
 *
 * https://www.acmicpc.net/problem/18870
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

namespace BOJ_18870 {
vector<int> unique_sorted(vector<int> values) {
  set<int> s(values.begin(), values.end());
  return vector<int>(s.begin(), s.end());
}

int do_main(int argc, const char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  vector<int> values;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    values.push_back(v);
  }

  vector<int> compressed = unique_sorted(values);

  for (int i = 0; i < n; ++i) {
    cout << lower_bound(compressed.begin(), compressed.end(), values[i]) - compressed.begin() << " ";
  }

  return 0;
}
} // namespace BOJ_18870

#ifndef DRIVER
int main(const int argc, const char *argv[]) { return BOJ_18870::do_main(argc, argv); }
#endif
