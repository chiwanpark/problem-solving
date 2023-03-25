/**
* 수열 정렬
*
* @author Chiwan Park
* @solved 2013. 03. 24.
*
* https://www.acmicpc.net/problem/1015
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

namespace BOJ_1015 {
  const int MaxN = 50;
  const int MaxNumber = 1000;

  int N;
  int A[MaxN + 10], B[MaxN + 10];
  int P[MaxN + 10];

  queue<int> Queue[MaxNumber + 10];

  void do_sort(void) {
    for (int i = 1; i <= N; ++i) {
      B[i] = A[i];
    }

    sort(B + 1, B + N + 1);

    for (int i = 1; i <= N; ++i) {
      Queue[B[i]].push(i);
    }

    for (int i = 1; i <= N; ++i) {
      P[i] = Queue[A[i]].front() - 1;
      Queue[A[i]].pop();
    }
  }

  int do_main(int argc, const char* argv[]) {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
      cin >> A[i];
    }
    do_sort();
    for (int i = 1; i <= N; ++i) {
      cout << P[i] << " ";
    }
    return 0;
  }
}

#ifndef DRIVER
int main(int argc, const char *argv[]) {
  return BOJ_1015::do_main(argc, argv);
}
#endif
