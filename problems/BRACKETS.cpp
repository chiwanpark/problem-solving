/**
* BRACKETS
*
* @author Chiwan Park
* @solved 2015. 05. 24
*
* http://algospot.com/judge/problem/read/BRACKETS
*/
#include <iostream>
#include <string>
#include <array>

using namespace std;

namespace BRACKETS {
  const int MaxLen = 100;
  string input;
  array<array<int, MaxLen>, MaxLen> Dy;

  inline bool valid(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']');
  }

  int calculate(int s, int e) {
    if (Dy[s][e] == -1 && s == e - 1 && valid(input[s], input[e])) {
      Dy[s][e] = 2;
    } else if (s == e && Dy[s][e] == -1) {
      Dy[s][e] = 0;
    } else if (s < e && Dy[s][e] == -1) {
      Dy[s][e] = 0;

      // case 1: [sub] or (sub)
      if (valid(input[s], input[e])) {
        int val = calculate(s + 1, e - 1);
        if (val != -1 && Dy[s][e] < val + 2) {
          Dy[s][e] = val + 2;
        }
      }

      // case 2: sub] or sub)
      int val = calculate(s + 1, e);
      if (Dy[s][e] < val) {
        Dy[s][e] = val;
      }

      // case 3: [sub or (sub
      val = calculate(s, e - 1);
      if (Dy[s][e] < val) {
        Dy[s][e] = val;
      }

      // case 4: subsub
      for (int i = s + 1; i < e; ++i) {
        int val1 = calculate(s, i);
        int val2 = calculate(i + 1, e);
        if (val1 != -1 && val2 != -1 && Dy[s][e] < val1 + val2) {
          Dy[s][e] = val1 + val2;
        }
      }
    }

    return Dy[s][e];
  }

  int do_main(int argc, const char *argv[]) {
    while (!cin.eof()) {
      cin >> input;
      if (input == "end") {
        break;
      }

      int len = input.size();
      for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
          Dy[i][j] = -1;
        }
      }

      cout << calculate(0, len - 1) << endl;
    }

    return 0;
  }
}

#ifndef DRIVER

int main(const int argc, const char *argv[]) {
  return BRACKETS::do_main(argc, argv);
}

#endif
