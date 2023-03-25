/**
* RGB거리
*
* @author Chiwan Park
* @solved 2023. 03. 25
*
* https://www.acmicpc.net/problem/1149
*/
#include <iostream>
#include <algorithm>

using namespace std;

namespace BOJ_1149 {
  const int MaxN = 1000;

  int N;
  int Cost[MaxN][3];

  void do_dynamic(void) {
    for (int i = 1; i < N; ++i) {
      Cost[i][0] += min(Cost[i - 1][1], Cost[i - 1][2]);
      Cost[i][1] += min(Cost[i - 1][0], Cost[i - 1][2]);
      Cost[i][2] += min(Cost[i - 1][0], Cost[i - 1][1]);
    }
  }

  int do_main(int argc, const char *argv[]) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
      cin >> Cost[i][0] >> Cost[i][1] >> Cost[i][2];
    }
    do_dynamic();
    cout << min({Cost[N - 1][0], Cost[N - 1][1], Cost[N - 1][2]});
    return 0;
  }
}

#ifndef DRIVER
int main(int argc, const char *argv[]) {
  BOJ_1149::do_main(argc, argv);
}
#endif
