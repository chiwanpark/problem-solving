/**
 * 감소하는 수
 *
 * @author Chiwan Park
 * @solved 2013. 03. 24.
 *
 * https://www.acmicpc.net/problem/1038
 */
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

namespace BOJ_1038 {
const int MaxN = 1000000;

int N;
long long int Answer = -1;
int Count;
priority_queue<long long int, vector<long long int>, greater<long long int>> Queue;

void do_bfs(void) {
  for (int i = 0; i <= 9; ++i) {
    Queue.push(i);
  }

  while (Queue.empty() == false) {
    long long int v = Queue.top();
    Queue.pop();
    ++Count;

    if (Count - 1 == N) {
      Answer = v;
      return;
    }

    for (int i = 0; i <= 9; ++i) {
      if (v % 10 > i) {
        Queue.push(v * 10 + i);
      }
    }
  }
}

int do_main(int argc, const char *argv[]) {
  cin >> N;
  do_bfs();
  cout << Answer;
  return 0;
}
} // namespace BOJ_1038

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_1038::do_main(argc, argv); }
#endif
