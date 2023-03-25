/**
 * ZEROONE
 *
 * @author Chiwan Park
 * @solved 2015. 05. 24
 *
 * http://algospot.com/judge/problem/read/ZEROONE
 */
#include <cstdio>

using namespace std;

namespace ZEROONE {
const int MaxLen = 1000000;

char input[MaxLen + 1];
int sum[MaxLen + 1];

int do_main(int argc, const char *argv[]) {
  int N, s, e;

  scanf("%s%d", input, &N);
  sum[0] = input[0] - '0';
  for (int i = 1; input[i]; ++i) {
    sum[i] = sum[i - 1] + input[i] - '0';
  }

  for (int i = 0; i < N; ++i) {
    scanf("%d %d", &s, &e);
    if (e < s) {
      int tmp = e;
      e = s;
      s = tmp;
    }

    int range_sum;
    if (s == 0) {
      range_sum = sum[e];
    } else {
      range_sum = sum[e] - sum[s - 1];
    }

    if (range_sum == 0 || range_sum == (e - s + 1)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }

  return 0;
}
} // namespace ZEROONE

#ifndef DRIVER

int main(int argc, const char *argv[]) { return ZEROONE::do_main(argc, argv); }

#endif
