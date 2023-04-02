/**
 * 파티
 *
 * @author Chiwan Park
 * @solved 2023. 04. 02
 *
 * https://www.acmicpc.net/problem/1238
 */
#include <cstdint>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

namespace BOJ_1238 {
using edge_t = tuple<int, int>; // dst, weight

int N, M, X;
vector<vector<edge_t>> Edges;
vector<vector<edge_t>> EdgesRev;

vector<int> find_shortest(int src, vector<vector<edge_t>> &edges) {
  vector<bool> visited(N, false);
  vector<int> distance(N, INT32_MAX / 2);
  distance[src] = 0;
  for (int i = 0; i < N; ++i) {
    int k = -1;
    for (int j = 0; j < N; ++j) {
      if (visited[j]) {
        continue;
      }
      if (k == -1 || distance[k] > distance[j]) {
        k = j;
      }
    }
    visited[k] = true;
    for (auto it = edges[k].cbegin(), end = edges[k].cend(); it != end; ++it) {
      int dst, weight;
      tie(dst, weight) = *it;
      if (distance[dst] > distance[k] + weight) {
        distance[dst] = distance[k] + weight;
      }
    }
  }
  return distance;
}

int do_main(int argc, const char *argv[]) {
  cin >> N >> M >> X;
  X -= 1;
  for (int i = 0; i < N; ++i) {
    Edges.push_back(vector<edge_t>());
    EdgesRev.push_back(vector<edge_t>());
  }
  for (int i = 0; i < M; ++i) {
    int src, dst, weight;
    cin >> src >> dst >> weight;
    Edges[src - 1].push_back(make_tuple(dst - 1, weight));
    EdgesRev[dst - 1].push_back(make_tuple(src - 1, weight));
  }

  auto distFromX = find_shortest(X, Edges);
  auto distToX = find_shortest(X, EdgesRev);
  int farthest = 0;
  for (int i = 0; i < N; ++i) {
    int dist = distFromX[i] + distToX[i];
    farthest = max(farthest, dist);
  }
  cout << farthest;
  return 0;
}
} // namespace BOJ_1238

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_1238::do_main(argc, argv); }
#endif
