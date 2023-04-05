/**
 * N-Queen
 *
 * @author Chiwan Park
 * @solved 2023. 04. 06
 *
 * https://www.acmicpc.net/problem/9663
 */
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

namespace BOJ_9663 {
int N;
int Count;
vector<int> Queen;

void search(int i) {
  if (i == N) {
    ++Count;
    return;
  }

  for (int j = 0; j < N; ++j) {
    bool conflict = false;
    for (int k = 0; k < i; ++k) {
      if (Queen[k] == j || abs(Queen[k] - j) == i - k) {
        conflict = true;
        break;
      }
    }

    if (!conflict) {
      Queen[i] = j;
      search(i + 1);
    }
  }
  Queen[i] = 0;
}

int do_main(int argc, const char *argv[]) {
  cin >> N;
  Queen = vector<int>(N, 0);
  search(0);
  cout << Count;
  return 0;
}
} // namespace BOJ_9663

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_9663::do_main(argc, argv); }
#endif
