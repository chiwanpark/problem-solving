/**
 * 단어의 개수
 *
 * @author Chiwan Park
 * @solved 2023. 03. 26
 *
 * https://www.acmicpc.net/problem/1152
 */
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

namespace BOJ_1152 {
int do_main(int argc, const char *argv[]) {
  string str;
  getline(cin, str);

  // trimming spaces
  str.erase(str.begin(), find_if(str.begin(), str.end(), [](unsigned char ch) { return !isspace(ch); }));
  str.erase(find_if(str.rbegin(), str.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), str.end());

  if (str.length() == 0) {
    cout << 0;
    return 0;
  }

  int count = 1;
  for (auto it = str.cbegin(), end = str.cend(); it != end; ++it) {
    if (*it == ' ') {
      count += 1;
    }
  }
  cout << count;
  return 0;
}
} // namespace BOJ_1152

#ifndef DRIVER
int main(int argc, const char *argv[]) { return BOJ_1152::do_main(argc, argv); }
#endif
