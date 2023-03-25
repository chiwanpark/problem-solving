/**
 * NQUEEN
 *
 * @author Chiwan Park
 * @solved 2015. 05. 24
 *
 * http://algospot.com/judge/problem/read/NQUEEN
 */
#include <cmath>
#include <iostream>

using namespace std;

namespace NQUEEN {
const int MaxN = 12;
int N, count;
int current[MaxN];

void search(int i) {
  if (i == N) {
    count++;
    return;
  }

  for (int j = 0; j < N; ++j) {
    bool flag = true;
    for (int k = 0; k < i; ++k) {
      if (current[k] == j || abs(j - current[k]) == i - k) {
        flag = false;
        break;
      }
    }

    if (flag) {
      current[i] = j;
      search(i + 1);
    }
  }

  current[i] = 0;
}

int do_main(int argc, const char *argv[]) {
  int T;

  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> N;
    count = 0;
    search(0);
    cout << count << endl;
  }

  return 0;
}
} // namespace NQUEEN

#ifndef DRIVER

int main(const int argc, const char *argv[]) { return NQUEEN::do_main(argc, argv); }

#endif
