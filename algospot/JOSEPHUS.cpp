/**
* JOSEPHUS
*
* @author Chiwan Park
* @solved 2014. 03. 25
*
* http://algospot.com/judge/problem/read/JOSEPHUS
*/
#include <iostream>
#include <list>

using namespace std;

namespace JOSEPHUS {
  int N, K;
  list<int> Soldiers;

  void initialize() {
    Soldiers.clear();
    for (int i = 1; i <= N; ++i) {
      Soldiers.push_back(i);
    }
  }

  void process() {
    list<int>::iterator iter = Soldiers.begin();
    while (Soldiers.size() > 2) {
      iter = Soldiers.erase(iter);
      if (iter == Soldiers.end()) {
        iter = Soldiers.begin();
      }

      for (int i = 1; i < K; ++i) {
        ++iter;
        if (iter == Soldiers.end()) {
          iter = Soldiers.begin();
        }
      }
    }
  }

  int do_main(int argc, const char *argv[]) {
    int C;

    cin >> C;
    for (int i = 0; i < C; ++i) {
      cin >> N >> K;
      initialize();
      process();

      cout << Soldiers.front() << ' ';
      Soldiers.pop_front();
      cout << Soldiers.front() << endl;
    }

    return 0;
  }
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
  return JOSEPHUS::do_main(argc, argv);
}

#endif