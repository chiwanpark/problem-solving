/**
 * 행렬 곱셈 순서
 *
 * @author Chiwan Park
 * @solved 2023. 04. 06
 *
 * https://www.acmicpc.net/problem/11049
 */
#include <cstdint>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

namespace BOJ_11049 {
using matrix_t = tuple<int, int>;

int N;
vector<matrix_t> Matrices;
vector<vector<int>> Dy;

void do_dynamic() {
  for (int size = 2; size < N; ++size) {
    for (int i = 0; i < N - size; ++i) {
      int j = i + size;
      int n = get<0>(Matrices[i]);
      int k = get<1>(Matrices[j]);
      for (int l = i; l < j; ++l) {
        int m = get<1>(Matrices[l]);
        int cost = Dy[i][l] + Dy[l + 1][j] + n * m * k;
        if (Dy[i][j] > cost) {
          Dy[i][j] = cost;
        }
      }
    }
  }
}

int do_main(int argc, const char *argv[]) {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int n, m;
    cin >> n >> m;
    Matrices.emplace_back(n, m);
  }

  Dy = vector<vector<int>>(N, vector<int>(N, INT32_MAX - 1));
  for (int i = 0; i < N - 1; ++i) {
    int n, m, k;
    tie(n, m) = Matrices[i];
    tie(m, k) = Matrices[i + 1];
    Dy[i][i] = 0;
    Dy[i][i + 1] = n * m * k;
  }
  Dy[N - 1][N - 1] = 0;
  do_dynamic();

  cout << Dy[0][N - 1];
  return 0;
}
} // namespace BOJ_11049

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_11049::do_main(argc, argv); }
#endif
