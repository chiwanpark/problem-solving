/**
 * 단어 공부
 *
 * @author Chiwan Park
 * @solved 2023. 03. 26
 *
 * https://www.acmicpc.net/problem/1157
 */
#include <algorithm>
#include <cctype>
#include <iostream>
#include <unordered_map>

using namespace std;

namespace BOJ_1157 {
int do_main(int argc, const char *argv[]) {
  string str;
  unordered_map<unsigned char, int> counts;
  using pair_t = decltype(counts)::value_type;
  cin >> str;

  for (auto it = str.cbegin(), end = str.cend(); it != end; ++it) {
    unsigned char ch = toupper(*it);
    counts[ch] = counts[ch] + 1;
  }
  auto top = max_element(counts.cbegin(), counts.cend(),
                         [](const pair_t &p1, const pair_t &p2) { return p1.second < p2.second; });
  for (auto it = counts.cbegin(), end = counts.cend(); it != end; ++it) {
    if (it->first != top->first && it->second == top->second) {
      cout << '?';
      return 0;
    }
  }
  cout << top->first;
  return 0;
}
} // namespace BOJ_1157

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_1157::do_main(argc, argv); }
#endif
