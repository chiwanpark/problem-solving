/**
 * BRACKETS2
 *
 * @author Chiwan Park
 * @solved 2015. 05. 24
 *
 * http://algospot.com/judge/problem/read/BRACKETS2
 */
#include <iostream>
#include <stack>
#include <string>

using namespace std;

namespace BRACKETS2 {
bool valid(char p, char q) { return (p == '{' && q == '}') || (p == '[' && q == ']') || (p == '(' && q == ')'); }

bool process(string input) {
  stack<char> s;

  for (string::iterator iter = input.begin(), end = input.end(); iter != end; ++iter) {
    if (*iter == ')' || *iter == '}' || *iter == ']') {
      if (s.empty() || !valid(s.top(), *iter)) {
        return false;
      }

      s.pop();
    } else {
      s.push(*iter);
    }
  }

  return s.empty();
}

int do_main(const int argc, const char *argv[]) {
  int C;
  string input;

  cin >> C;
  for (int i = 0; i < C; ++i) {
    cin >> input;
    bool result = process(input);
    if (result) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
} // namespace BRACKETS2

#ifndef DRIVER

int main(int argc, const char *argv[]) { return BRACKETS2::do_main(argc, argv); }

#endif
