/**
* 셀프 넘버
*
* @author Chiwan Park
* @solved 2023. 03. 25
*
* https://www.acmicpc.net/problem/4673
*/
#include <iostream>

using namespace std;

namespace BOJ_4673 {
  bool flag[10001];

  int sum(int n) {
    int sum = n;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }

  void fill_flag(void) {
    for (int i = 1; i <= 10000; ++i) {
      if (!flag[i]) {
        for (int j = sum(i); j <= 10000; j = sum(j)) {
          flag[j] = true;
        }
      }
    }
  }

  int do_main(int argc, const char *argv[]) {
    fill_flag();

    for (int i = 1; i <= 10000; ++i) {
      if (!flag[i]) {
        cout << i << endl;
      }
    }
    return 0;
  }
}

#ifndef DRIVER
int main(int argc, const char *argv[]) {
  return BOJ_4673::do_main(argc, argv);
}
#endif
