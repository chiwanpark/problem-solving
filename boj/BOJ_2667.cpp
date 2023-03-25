/**
 * 단지번호붙이기
 *
 * @author Chiwan Park
 * @solved 2023. 03. 25
 *
 * https://www.acmicpc.net/problem/2667
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace BOJ_2667 {
const int MaxN = 25;

int N;
char Map[MaxN + 1][MaxN + 1];
int Direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int do_dfs(int i, int j, char id, int size) {
  Map[i][j] = id;
  for (int k = 0; k < 4; ++k) {
    int ni = i + Direction[k][0];
    int nj = j + Direction[k][1];
    if (ni < 0 || nj < 0 || ni >= N || nj >= N || Map[ni][nj] != '1') {
      continue;
    }
    size = do_dfs(ni, nj, id, size + 1);
  }
  return size;
}

int do_main(int argc, const char *argv[]) {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> Map[i];
  }

  vector<int> sizes;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (Map[i][j] != '1') {
        continue;
      }
      int size = do_dfs(i, j, sizes.size() + '2', 1);
      if (size > 0) {
        sizes.push_back(size);
      }
    }
  }

  sort(sizes.begin(), sizes.end());
  cout << sizes.size() << endl;
  for (int i = 0, size = sizes.size(); i < size; ++i) {
    cout << sizes[i] << endl;
  }
  return 0;
}
} // namespace BOJ_2667

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_2667::do_main(argc, argv); }
#endif
