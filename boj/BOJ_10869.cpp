/**
* 사칙연산
*
* @author Chiwan Park
* @solved 2023. 03. 25
*
* https://www.acmicpc.net/problem/10869
*/
#include <iostream>

using namespace std;

namespace BOJ_10869 {
  int do_main(int argc, const char *argv[]) {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl << a - b << endl << a * b << endl << a / b << endl << a % b;
    return 0;
  }
}

#ifndef DRIVER
int main(const int argc, const char *argv[]) {
  return BOJ_10869::do_main(argc, argv);
}
#endif
