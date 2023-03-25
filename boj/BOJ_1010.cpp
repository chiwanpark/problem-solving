/**
* 다리 놓기
*
* @author Chiwan Park
* @solved 2023. 03. 25
*
* https://www.acmicpc.net/problem/1010
*/
#include <iostream>

using namespace std;

namespace BOJ_1010 {
  const int MaxM = 30;

  int T;
  int N, M;
  int Dy[MaxM + 1][MaxM + 1];

  void do_dynamic(void) {
    for (int i = 0; i <= MaxM; ++i) {
      Dy[0][i] = 1;
    }
    for (int i = 1; i <= MaxM; ++i) {
      for (int j = 1; j <= MaxM; ++j) {
        Dy[i][j] = Dy[i - 1][j - 1] + Dy[i][j - 1];
      }
    }
  }

  int do_main(int argc, const char *argv[]) {
    cin >> T;
    do_dynamic();
    for (int i = 0; i < T; ++i) {
      cin >> N >> M;
      cout << Dy[N][M] << endl;
    }
    return 0;
  }
}

#ifndef DRIVER
int main(int argc, const char *argv[]) {
  return BOJ_1010::do_main(argc, argv);
}
#endif
