/**
 * DIAMONDPATH
 *
 * @author Chiwan Park
 * @solved 2013. 11. 04
 *
 * http://algospot.com/judge/problem/read/DIAMONDPATH
 */
#include <cstring>
#include <iostream>

using namespace std;

namespace DIAMONDPATH {
const int MaxN = 100;

int N;
int Num[MaxN * 2 + 10][MaxN * 2 + 10];
int Dy[MaxN * 2 + 10][MaxN * 2 + 10];

inline int max(int a, int b) { return a > b ? a : b; }

void do_dynamic(void) {
  Dy[0][0] = Num[0][0];
  for (int i = 1; i < 2 * N - 1; ++i) {
    int end = (i >= N) ? 2 * N - i - 1 : i + 1;
    for (int j = 0; j < end; ++j) {
      if (i < N) {
        if (j == 0)
          Dy[i][j] = Dy[i - 1][j];
        else if (j == end - 1)
          Dy[i][j] = Dy[i - 1][j - 1];
        else
          Dy[i][j] = max(Dy[i - 1][j], Dy[i - 1][j - 1]);
      } else
        Dy[i][j] = max(Dy[i - 1][j], Dy[i - 1][j + 1]);

      Dy[i][j] += Num[i][j];
    }
  }
}

int do_main(const int argc, const char *argv[]) {
  int T;

  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> N;

    memset(Dy, 0, sizeof(Dy));

    for (int j = 0; j < 2 * N - 1; ++j) {
      int end = (j >= N) ? 2 * N - j - 1 : j + 1;
      for (int k = 0; k < end; ++k)
        cin >> Num[j][k];
    }

    do_dynamic();

    cout << Dy[2 * N - 2][0] << endl;
  }

  return 0;
}
} // namespace DIAMONDPATH

#ifndef DRIVER

int main(const int argc, const char *argv[]) { return DIAMONDPATH::do_main(argc, argv); }

#endif
