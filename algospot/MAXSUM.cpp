/**
 * MAXSUM
 *
 * @author Chiwan Park
 * @solved 2013. 11. 04
 *
 * http://algospot.com/judge/problem/read/MAXSUM
 */
#include <cstdio>

namespace MAXSUM {
int do_main(int argc, const char *argv[]) {
  int T, N, input, g, answer;

  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    scanf("%d", &N);
    g = 0;
    answer = 0;
    for (int j = 0; j < N; ++j) {
      scanf("%d", &input);

      if (g > 0)
        g += input;
      else
        g = input;
      if (answer < g)
        answer = g;
    }

    printf("%d\n", answer);
  }

  return 0;
}
} // namespace MAXSUM

#ifndef DRIVER

int main(int argc, const char *argv[]) { return MAXSUM::do_main(argc, argv); }

#endif
