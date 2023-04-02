/**
 * 최단경로
 *
 * @author Chiwan Park
 * @solved 2023. 04. 03
 *
 * https://www.acmicpc.net/problem/1753
 */
#include <cstdint>
#include <functional>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

namespace BOJ_1753 {
const int INF = INT32_MAX / 2;
using edge_t = tuple<int, int>; // dst, weight
using dist_t = tuple<int, int>; // distance, node

int V, E, K;
vector<vector<edge_t>> Edges;

vector<int> dijkstra() {
  vector<int> distance(V, INF);
  vector<bool> visited(V, false);
  priority_queue<dist_t, vector<dist_t>, greater<dist_t>> q;
  distance[K] = 0;
  q.emplace(0, K);

  while (!q.empty()) {
    int node = get<1>(q.top());
    q.pop();
    if (visited[node]) {
      continue;
    }
    visited[node] = true;

    for (auto it = Edges[node].cbegin(), end = Edges[node].cend(); it != end; ++it) {
      int dst, weight;
      tie(dst, weight) = *it;
      if (!visited[dst] && distance[dst] > distance[node] + weight) {
        distance[dst] = distance[node] + weight;
        q.emplace(distance[dst], dst);
      }
    }
  }
  return distance;
}

int do_main(int argc, const char *argv[]) {
  cin >> V >> E >> K;
  K -= 1;
  Edges = vector<vector<edge_t>>(V, vector<edge_t>());
  for (int i = 0; i < E; ++i) {
    int src, dst, weight;
    cin >> src >> dst >> weight;
    Edges[src - 1].push_back(make_tuple(dst - 1, weight));
  }

  auto dist = dijkstra();
  for (int i = 0; i < V; ++i) {
    if (dist[i] == INF) {
      cout << "INF\n";
    } else {
      cout << dist[i] << "\n";
    }
  }
  return 0;
}
} // namespace BOJ_1753

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_1753::do_main(argc, argv); }
#endif
