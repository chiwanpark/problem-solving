/**
 * 최소 스패닝 트리
 *
 * @author Chiwan Park
 * @solved 2023. 03. 26
 *
 * https://www.acmicpc.net/problem/1197
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

using namespace std;

namespace BOJ_1197 {
using edge_t = tuple<int, int, int>; // vertex, vertex, weight

int V, E;
vector<edge_t> Edges;
vector<int> Set;

bool compare_edge(const edge_t &e1, const edge_t &e2) { return get<2>(e1) < get<2>(e2); }

int set_find(int p) {
  if (p != Set[p]) {
    Set[p] = set_find(Set[p]);
  }
  return Set[p];
}

void set_merge(int p, int q) {
  p = set_find(p);
  q = set_find(q);
  if (p < q) {
    Set[q] = p;
  } else {
    Set[p] = q;
  }
}

int do_kruskal(void) {
  int cost = 0;
  sort(Edges.begin(), Edges.end(), [](const edge_t &e1, const edge_t &e2) { return get<2>(e1) < get<2>(e2); });
  for (auto it = Edges.cbegin(), end = Edges.cend(); it != end; ++it) {
    int p, q, w;
    tie(p, q, w) = *it;
    p = set_find(p);
    q = set_find(q);
    if (p == q) {
      continue;
    }
    cost += w;
    set_merge(p, q);
  }
  return cost;
}

int do_main(int argc, const char *argv[]) {
  cin >> V >> E;

  Set.resize(V, 0);
  iota(Set.begin(), Set.end(), 0);

  Edges.reserve(E);
  for (int i = 0; i < E; ++i) {
    int p, q, w;
    cin >> p >> q >> w;
    Edges.push_back(make_tuple(p - 1, q - 1, w));
  }

  int cost = do_kruskal();
  cout << cost;
  return 0;
}
} // namespace BOJ_1197

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_1197::do_main(argc, argv); }
#endif
