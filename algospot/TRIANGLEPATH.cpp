/**
 * TRIANGLEPATH
 *
 * @author Chiwan Park
 * @solved 2015. 05. 25
 *
 * http://algospot.com/judge/problem/read/TRIANGLEPATH
 */
#include <array>
#include <iostream>

using namespace std;

namespace TRIANGLEPATH {
const int MaxN = 100;

array<array<int, MaxN>, MaxN> dy;

int do_main(int argc, const char *argv[]) {
  int C, N, result;

  cin >> C;
  for (int i = 0; i < C; ++i) {
    cin >> N;
    result = 0;
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k <= j; ++k) {
        cin >> dy[j][k];
        if (k == j || (k > 0 && dy[j - 1][k - 1] > dy[j - 1][k])) {
          dy[j][k] += dy[j - 1][k - 1];
        } else if (j > 0) {
          dy[j][k] += dy[j - 1][k];
        }

        if (result < dy[j][k]) {
          result = dy[j][k];
        }
      }
    }

    cout << result << endl;
  }

  return 0;
}
} // namespace TRIANGLEPATH

#ifndef DRIVER

int main(int argc, const char *argv[]) { return TRIANGLEPATH::do_main(argc, argv); }

#endif
