/**
* 숨바꼭질
*
* @author Chiwan Park
* @solved 2013. 03. 16.
*
* https://www.acmicpc.net/problem/1697
**/
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

namespace BOJ_1697 {
  const int MaxN = 105000;
  const int MinN = -MaxN;
  const int Shift = MaxN;

  int Steps[MaxN * 2 + 10];
  int N, K;
  queue<int> Queue;

  void do_bfs(void) {
    for (int i = 0; i <= MaxN * 2 + 1; ++ i)
      Steps[i] = INT_MAX >> 1;

    Steps[N + Shift] = 0;
    Queue.push(N);

    while(Queue.empty() == false) {
      int v = Queue.front();
      int steps = Steps[v + Shift] + 1;
      Queue.pop();

      if (MinN <= v + 1 && v + 1 <= MaxN && steps < Steps[v + 1 + Shift]) { // v + 1
        Steps[v + 1 + Shift] = steps;
        Queue.push(v + 1);
      }

      if (MinN <= v - 1 && v - 1 <= MaxN && steps < Steps[v - 1 + Shift]) { // v - 1
        Steps[v - 1 + Shift] = steps;
        Queue.push(v - 1);
      }

      if (MinN <= v * 2 && v * 2 <= MaxN && steps < Steps[v * 2 + Shift]) { // v * 2
        Steps[v * 2 + Shift] = steps;
        Queue.push(v * 2);
      }
    }
  }

  int do_main(int argc, const char* argv[]) {
    cin >> N >> K;
    do_bfs();
    cout << Steps[K + Shift];
    return 0;
  }
}

#ifndef DRIVER
int main(int argc, const char *argv[]) {
  return BOJ_1697::do_main(argc, argv);
}
#endif
