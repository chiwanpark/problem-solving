/**
* A-B
*
* @author Chiwan Park
* @solved 2013. 03. 16.
*
* https://www.acmicpc.net/problem/1001
**/
#include <iostream>

using namespace std;

namespace BOJ_1001 {
  int do_main(int argc, const char* argv[]) {
    int a, b;
    cin >> a >> b;
    cout << a - b;
    return 0;
  }
}

#ifndef DRIVER
int main(int argc, const char *argv[]) {
  return BOJ_1001::do_main(argc, argv);
}
#endif
