/**
* CHRISTMAS
*
* @author Chiwan Park
* @solved 2014. 03. 24
*
* http://algospot.com/judge/problem/read/CHRISTMAS
*/
#include <iostream>
#include <array>

using namespace std;

namespace CHRISTMAS {
  const int MaxN = 100000;

  int N, K;
  array<int, MaxN + 1> Box, Count, Sum, Pos, Max;
  int Ans1, Ans2;

  void initialize() {
    Box.fill(0);
    Sum.fill(0);
    Count.fill(0);
    Pos.fill(-1);
    Max.fill(0);
    Ans1 = 0;
    Ans2 = 0;

    Pos[0] = 0;
    Count[0] = 1;
  }

  void process1() {
    for (int i = 1; i <= N; ++i) {
      Ans1 = (Ans1 + Count[Sum[i]]) % 20091101;
      ++Count[Sum[i]];
    }
  }

  void process2() {
    for (int i = 1; i <= N; ++i) {
      int pos = Pos[Sum[i]];
      Pos[Sum[i]] = i;

      int value = Max[i - 1];
      if (pos != -1 && value < Max[pos] + 1) {
        value = Max[pos] + 1;
      }

      Max[i] = value;
    }

    Ans2 = Max[N];
  }

  int do_main(int argc, const char *argv[]) {
    int T;

    cin >> T;
    for (int i = 0; i < T; ++i) {
      initialize();

      cin >> N >> K;
      for (int j = 1; j <= N; ++j) {
        cin >> Box[j];
        Sum[j] = (Sum[j - 1] + Box[j]) % K;
      }

      process1();
      process2();

      cout << Ans1 << ' ' << Ans2 << endl;
    }

    return 0;
  }
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
  return CHRISTMAS::do_main(argc, argv);
}

#endif