/**
* 오늘 날짜
*
* @author Chiwan Park
* @solved 2023. 03. 25
*
* https://www.acmicpc.net/problem/10699
*/
#include <ctime>
#include <iostream>

using namespace std;

namespace BOJ_10699 {
  int do_main(int argc, const char *argv[]) {
    char result[30];
    time_t t = time(nullptr) + 9 * 3600;
    tm* now = localtime(&t);
    strftime(result, 29, "%Y-%m-%d", now);
    cout << result;
    return 0;
  }
}

#ifndef DRIVER
int main(const int argc, const char *argv[]) {
  return BOJ_10699::do_main(argc, argv);
}
#endif
