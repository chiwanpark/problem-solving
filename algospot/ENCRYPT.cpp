/**
 * ENCRYPT
 *
 * @author Chiwan Park
 * @solved 2013. 11. 04
 *
 * http://algospot.com/judge/problem/read/ENCRYPT
 */
#include <iostream>
#include <string>

using namespace std;

namespace ENCRYPT {
string encrypt(const string &s) {
  string result = "";

  for (string::const_iterator iter = s.begin(), end = s.end(); iter < end; iter += 2)
    result += *iter;

  if (s.length() > 1) {
    for (string::const_iterator iter = s.begin() + 1, end = s.end(); iter < end; iter += 2)
      result += *iter;
  }

  return result;
}

int do_main(int argc, const char *argv[]) {
  int T;

  cin >> T;
  for (int i = 0; i < T; ++i) {
    string original;

    cin >> original;
    cout << encrypt(original) << endl;
  }
  return 0;
}
} // namespace ENCRYPT

#ifndef DRIVER

int main(int argc, const char *argv[]) { return ENCRYPT::do_main(argc, argv); }

#endif