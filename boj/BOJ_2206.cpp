/**
 * 벽 부수고 이동하기
 *
 * @author Chiwan Park
 * @solved 2023. 04. 06
 *
 * https://www.acmicpc.net/problem/2206
 */
#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

namespace BOJ_2206 {
using state_t = tuple<int, int>; // i, j
const array<array<int, 2>, 4> Direction = {{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};

int N, M;
vector<vector<bool>> Maze;

bool is_valid(int i, int j) { return i >= 0 && i <= N - 1 && j >= 0 && j <= M - 1; }

vector<vector<int>> shortest_dist(int si, int sj) {
  vector<vector<int>> distance(N, vector<int>(M, INT32_MAX / 2));
  queue<state_t> q;
  q.emplace(si, sj);
  distance[si][sj] = 1;

  while (!q.empty()) {
    int i, j;
    tie(i, j) = q.front();
    q.pop();

    for (int k = 0; k < 4; ++k) {
      int ni = i + Direction[k][0];
      int nj = j + Direction[k][1];
      if (!is_valid(ni, nj) || Maze[ni][nj]) {
        continue;
      }
      if (distance[ni][nj] > distance[i][j] + 1) {
        distance[ni][nj] = distance[i][j] + 1;
        q.emplace(ni, nj);
      }
    }
  }
  return distance;
}

int do_main(int argc, const char *argv[]) {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    string line;
    cin >> line;
    vector<bool> converted;
    for (int j = 0; j < M; ++j) {
      converted.push_back(line.at(j) == '1');
    }
    Maze.push_back(converted);
  }

  vector<vector<int>> distFrom11 = shortest_dist(0, 0);
  vector<vector<int>> distFromNM = shortest_dist(N - 1, M - 1);

  int answer = distFrom11[N - 1][M - 1];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (!Maze[i][j]) {
        continue;
      }
      for (int k = 0; k < 4; ++k) {
        int i11 = i + Direction[k][0];
        int j11 = j + Direction[k][1];
        if (!is_valid(i11, j11) || Maze[i11][j11]) {
          continue;
        }
        for (int l = 0; l < 4; ++l) {
          int iNM = i + Direction[l][0];
          int jNM = j + Direction[l][1];
          if (!is_valid(iNM, jNM) || Maze[iNM][jNM]) {
            continue;
          }
          answer = min(answer, distFrom11[i11][j11] + distFromNM[iNM][jNM] + 1);
        }
      }
    }
  }
  if (answer >= INT32_MAX / 2) {
    answer = -1;
  }
  cout << answer;

  return 0;
}
} // namespace BOJ_2206

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_2206::do_main(argc, argv); }
#endif
