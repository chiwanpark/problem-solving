/**
 * 특정한 최단 경로
 *
 * @author Chiwan Park
 * @solved 2023. 04. 03
 *
 * https://www.acmicpc.net/problem/1504
 */
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

namespace BOJ_1504 {
using edge_t = tuple<int, int>; // dst, weight
const int INF = INT32_MAX / 2;

int N, E, V1, V2;
vector<vector<edge_t>> Edges;

vector<int> find_shortest(int src) {
  vector<int> distance(N, INF);
  distance[src] = 0;
  vector<bool> visited(N, false);

  for (int i = 0; i < N; ++i) {
    int k = -1;
    for (int j = 0; j < N; ++j) {
      if (!visited[j] && (k == -1 || distance[k] > distance[j])) {
        k = j;
      }
    }
    visited[k] = true;
    for (auto it = Edges[k].cbegin(), end = Edges[k].cend(); it != end; ++it) {
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
  cin >> N >> E;
  for (int i = 0; i < N; ++i) {
    Edges.push_back(vector<edge_t>());
  }
  for (int i = 0; i < E; ++i) {
    int src, dst, weight;
    cin >> src >> dst >> weight;
    Edges[src - 1].push_back(make_tuple(dst - 1, weight));
    Edges[dst - 1].push_back(make_tuple(src - 1, weight));
  }
  cin >> V1 >> V2;
  V1 -= 1;
  V2 -= 1;

  auto distFrom0 = find_shortest(0);
  auto distFromV1 = find_shortest(V1);
  auto distFromV2 = find_shortest(V2);

  int dist = INF;
  // case 1: 0 -> V1 -> V2 -> N
  if (distFrom0[V1] != INF && distFromV1[V2] != INF && distFromV2[N - 1] != INF) {
    dist = distFrom0[V1] + distFromV1[V2] + distFromV2[N - 1];
  }
  // case 2: 0 -> V2 -> V1 -> N
  if (distFrom0[V2] != INF && distFromV2[V1] != INF && distFromV1[N - 1] != INF) {
    dist = min(dist, distFrom0[V2] + distFromV2[V1] + distFromV1[N - 1]);
  }
  if (dist == INF) {
    dist = -1;
  }
  cout << dist;
  return 0;
}
} // namespace BOJ_1504

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_1504::do_main(argc, argv); }
#endif
