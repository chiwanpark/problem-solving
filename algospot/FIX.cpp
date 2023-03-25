/**
 * FIX
 *
 * @author Chiwan Park
 * @solved 2015. 05. 24
 *
 * http://algospot.com/judge/problem/read/FIX
 */
#include <iostream>

using namespace std;

namespace FIX {
int do_main(int argc, const char *argv[]) {
  int T, N, count;
  int difficulty;

  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> N;
    count = 0;
    for (int j = 0; j < N; ++j) {
      cin >> difficulty;
      if (difficulty == j + 1) {
        ++count;
      }
    }

    cout << count << endl;
  }

  return 0;
}
} // namespace FIX

#ifndef DRIVER

int main(int argc, const char *argv[]) { return FIX::do_main(argc, argv); }

#endif
