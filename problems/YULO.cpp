/**
* YULO
*
* @author Chiwan Park
* @solved 2015. 05. 24
*
* http://algospot.com/judge/problem/read/YULO
*/
#include <iostream>
#include <array>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;

namespace YULO {
  const int MaxN = 40;

  int N;
  array<int, MaxN> scores;
  array<int, (MaxN >> 1)> sum;

  double process() {
    sort(scores.begin(), scores.begin() + N);
    for (int i = 0; i < (N >> 1); ++i) {
      sum[i] = scores[i] + scores[N - i - 1];
    }

    if ((N & 1) == 1) {
      sum[N >> 1] = scores[N >> 1] * 2;
      sort(sum.begin(), sum.begin() + ((N >> 1) + 1), greater<int>());
    } else {
      sort(sum.begin(), sum.begin() + (N >> 1), greater<int>());
    }

    return sum[0] / 2.0;
  }

  int do_main(int argc, const char *argv[]) {
    int T;

    cin >> T;
    for (int i = 0; i < T; ++i) {
      cin >> N;
      for (int j = 0; j < N; ++j) {
        cin >> scores[j];
      }

      cout << fixed << setprecision(1) << process() << endl;
    }
    return 0;
  }
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
  return YULO::do_main(argc, argv);
}

#endif
