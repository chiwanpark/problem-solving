/**
* CSBASEBALL
*
* @author Chiwan Park
* @solved 2015. 05. 24
*
* http://algospot.com/judge/problem/read/CSBASEBALL
*/
#include <iostream>

using namespace std;

namespace CSBASEBALL {
  int do_main(int argc, const char *argv[]) {
    int T, a, b;

    cin >> T;
    for (int i = 0; i < T; ++i) {
      cin >> a >> b;
      if (a > b) {
        cout << 0 << endl;
      } else {
        cout << b - a + 4 << endl;
      }
    }

    return 0;
  }
}

#ifndef DRIVER

int main(const int argc, const char *argv[]) {
  return CSBASEBALL::do_main(argc, argv);
}

#endif
