/**
 * DRAWRECT
 *
 * @author Chiwan Park
 * @solved 2013. 11. 04
 *
 * http://algospot.com/judge/problem/read/DRAWRECT
 */
#include <algorithm>
#include <iostream>

using namespace std;

namespace DRAWRECT {
int T;
int X[3], Y[3];

void determine_point() {
  int x, y;

  sort(X, X + 3);
  sort(Y, Y + 3);

  x = (X[0] == X[1]) ? X[2] : X[0];
  y = (Y[0] == Y[1]) ? Y[2] : Y[0];

  cout << x << " " << y << endl;
}

int do_main(int argc, const char *argv[]) {
  cin >> T;
  for (int i = 0; i < T; ++i) {
    for (int j = 0; j < 3; ++j)
      cin >> X[j] >> Y[j];

    determine_point();
  }

  return 0;
}
} // namespace DRAWRECT

#ifndef DRIVER

int main(int argc, const char *argv[]) { return DRAWRECT::do_main(argc, argv); }

#endif
