/**
 * 트리의 지름
 *
 * @author Chiwan Park
 * @solved 2023. 04. 03
 *
 * https://www.acmicpc.net/problem/1967
 */
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

namespace BOJ_1967 {
using edge_t = tuple<int, int>;   // dst, weight
using status_t = tuple<int, int>; // distance, node

int V;
vector<vector<edge_t>> Tree;

tuple<int, int> find_farthest(int src) {
  status_t farthest = make_tuple(-1, -1);
  vector<bool> visited(V, false);
  queue<status_t> q;
  q.push(make_tuple(0, src));
  while (!q.empty()) {
    int dist, now;
    tie(dist, now) = q.front();
    q.pop();
    visited[now] = true;
    if (farthest < tie(dist, now)) {
      farthest = tie(dist, now);
    }

    for (auto it = Tree[now].cbegin(), end = Tree[now].cend(); it != end; ++it) {
      int dst, weight;
      tie(dst, weight) = *it;
      if (!visited[dst]) {
        q.push(make_tuple(dist + weight, dst));
      }
    }
  }
  return farthest;
}

int do_main(int argc, const char *argv[]) {
  cin >> V;
  for (int i = 0; i < V; ++i) {
    Tree.push_back(vector<edge_t>());
  }
  for (int i = 0; i < V - 1; ++i) {
    int src, dst, weight;
    cin >> src >> dst >> weight;
    Tree[src - 1].push_back(make_tuple(dst - 1, weight));
    Tree[dst - 1].push_back(make_tuple(src - 1, weight));
  }

  int farthest, dist;
  tie(dist, farthest) = find_farthest(0);
  tie(dist, farthest) = find_farthest(farthest);
  cout << dist;
  return 0;
}
} // namespace BOJ_1967

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_1967::do_main(argc, argv); }
#endif
