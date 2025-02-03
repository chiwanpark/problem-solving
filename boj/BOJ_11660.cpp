/**
 * 구간 합 구하기 5
 *
 * @author Chiwan Park
 * @solved 2025. 02. 03
 *
 * https://www.acmicpc.net/problem/11660
 */
#include <array>
#include <iostream>

using namespace std;

namespace BOJ_11660 {
const int MaxN = 1024;
array<array<int, MaxN + 1>, MaxN + 1> D;

int do_main(int argc, const char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> D[i + 1][j + 1];
      D[i + 1][j + 1] += D[i + 1][j] + D[i][j + 1] - D[i][j];
    }
  }

  for (int i = 0; i < m; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << D[x2][y2] - D[x2][y1 - 1] - D[x1 - 1][y2] + D[x1 - 1][y1 - 1] << "\n";
  }
  return 0;
}
} // namespace BOJ_11660

#ifndef DRIVER
int main(const int argc, const char *argv[]) { return BOJ_11660::do_main(argc, argv); }
#endif
