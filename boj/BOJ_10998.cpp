/**
* AxB
*
* @author Chiwan Park
* @solved 2023. 03. 25
*
* https://www.acmicpc.net/problem/10998
*/
#include <iostream>

using namespace std;

namespace BOJ_10998 {
  int do_main(int argc, const char *argv[]) {
    int a, b;
    cin >> a >> b;
    cout << a * b;
    return 0;
  }
}

#ifndef DRIVER
int main(const int argc, const char *argv[]) {
  return BOJ_10998::do_main(argc, argv);
}
#endif
