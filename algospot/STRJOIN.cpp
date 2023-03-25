/**
 * STRJOIN
 *
 * @author Chiwan Park
 * @solved 2013. 11. 04
 *
 * http://algospot.com/judge/problem/read/STRJOIN
 */
#include <functional>
#include <iostream>
#include <queue>

using namespace std;

namespace STRJOIN {
priority_queue<int, vector<int>, greater<int>> Queue;

int calculate_minimum(void) {
  int p, q, sum = 0;

  while (Queue.size() > 1) {
    p = Queue.top();
    Queue.pop();
    q = Queue.top();
    Queue.pop();

    sum += p + q;
    Queue.push(p + q);
  }

  return sum;
}

int do_main(int argc, const char *argv[]) {
  int C, N, value;

  cin >> C;
  for (int i = 0; i < C; ++i) {
    while (!Queue.empty())
      Queue.pop();

    cin >> N;
    for (int j = 0; j < N; ++j) {
      cin >> value;
      Queue.push(value);
    }

    cout << calculate_minimum() << endl;
  }

  return 0;
}
} // namespace STRJOIN

#ifndef DRIVER

int main(int argc, const char *argv[]) { return STRJOIN::do_main(argc, argv); }

#endif
