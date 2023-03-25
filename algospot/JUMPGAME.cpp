/**
 * JUMPGAME
 *
 * @author Chiwan Park
 * @solved 2015. 05. 25
 *
 * http://algospot.com/judge/problem/read/JUMPGAME
 */
#include <array>
#include <iostream>

using namespace std;

namespace JUMPGAME {
const int MaxN = 100;

int N;
array<array<int, MaxN>, MaxN> map;
array<array<int, MaxN>, MaxN> dy;

int move_possible(int i, int j) {
  if (dy[i][j] == -1) {
    if ((i == N - 1 && j == N - 1) ||                                  // case finished
        (j + map[i][j] < N && move_possible(i, j + map[i][j]) == 1) || // case moving right
        (i + map[i][j] < N && move_possible(i + map[i][j], j) == 1)) { // case moving down
      dy[i][j] = 1;
    } else {
      dy[i][j] = 0;
    }
  }

  return dy[i][j];
}

int do_main(int argc, const char *argv[]) {
  int C;

  cin >> C;
  for (int i = 0; i < C; ++i) {
    cin >> N;
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        cin >> map[j][k];
        dy[j][k] = -1;
      }
    }

    dy[N - 1][N - 1] = true;

    if (move_possible(0, 0)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
} // namespace JUMPGAME

#ifndef DRIVER

int main(int argc, const char *argv[]) { return JUMPGAME::do_main(argc, argv); }

#endif
