/**
 * LIS
 *
 * @author
 * @solved 2013. 11. 04
 *
 * http://algospot.com/judge/problem/read/LIS
 */
#include <iostream>

using namespace std;

namespace LIS {
const int MaxN = 500;

int N;
int Sequence[MaxN];
int Dy[MaxN];

void do_dynamic(void) {
  for (int i = 0; i < N; ++i) {
    Dy[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (Sequence[j] < Sequence[i] && Dy[i] < Dy[j] + 1)
        Dy[i] = Dy[j] + 1;
    }
  }
}

int do_main(int argc, const char *argv[]) {
  int C, Answer;

  cin >> C;
  for (int i = 0; i < C; ++i) {
    cin >> N;
    Answer = 0;
    for (int j = 0; j < N; ++j)
      cin >> Sequence[j];

    do_dynamic();

    for (int j = 0; j < N; ++j) {
      if (Answer < Dy[j])
        Answer = Dy[j];
    }
    cout << Answer << endl;
  }
  return 0;
}
} // namespace LIS

#ifndef DRIVER

int main(int argc, const char *argv[]) { return LIS::do_main(argc, argv); }

#endif
