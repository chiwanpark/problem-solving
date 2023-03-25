/**
* 미로 탐색
*
* @author Chiwan Park
* @solved 2023. 03. 25
*
* https://www.acmicpc.net/problem/2178
*/
#include <iostream>
#include <queue>

using namespace std;

namespace BOJ_2178 {
  const int MaxN = 100;
  const int MaxM = 100;

  int N, M;
  char Maze[MaxN + 1][MaxM + 1];
  int Direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  struct Move {
    int x, y;
    int dist;
  };
  queue<Move> Queue;

  int do_bfs(void) {
    Move current;

    Queue.push(Move{0, 0, 1});
    while (!Queue.empty()) {
      current = Queue.front();
      if (current.x == M - 1 && current.y == N - 1) {
        return current.dist;
      }
      Queue.pop();
      for (int i = 0; i < 4; ++i) {
        Move next{current.x + Direction[i][0], current.y + Direction[i][1], current.dist + 1};
        if (next.x < 0 || next.y < 0 || next.x >= M || next.y >= N || Maze[next.y][next.x] != '1') {
          continue;
        }
        Maze[next.y][next.x] = '0';
        Queue.push(next);
      }
    }
    return -1;
  }

  int do_main(int argc, const char *argv[]) {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
      cin >> Maze[i];
    }
    cout << do_bfs();
    return 0;
  }
}

#ifndef DRIVER
int main(int argc, const char *argv[]) {
  return BOJ_2178::do_main(argc, argv);
}
#endif
