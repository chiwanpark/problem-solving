/**
* PICNIC
*
* @author Chiwan Park
* @solved 2014. 03. 25
*
* http://algospot.com/judge/problem/read/PICNIC
*/
#include <iostream>
#include <list>
#include <array>

using namespace std;

namespace PICNIC {
  const int MaxN = 10;

  int N, M;
  int Answer;

  array<list<int>, MaxN + 1> Link;
  array<bool, MaxN + 1> Visited;

  void initialize() {
    for (int i = 0; i < N; ++i) {
      Link[i].clear();
    }
    Visited.fill(false);
    Answer = 0;
  }

  void process() {
    bool flag = false;

    for (int i = 0; i < N; ++i) {
      if (!Visited[i]) {
        flag = true;
        for (list<int>::iterator iter = Link[i].begin(), end = Link[i].end(); iter != end; ++iter) {
          if (!Visited[*iter]) {
            Visited[i] = true;
            Visited[*iter] = true;

            process();

            Visited[i] = false;
            Visited[*iter] = false;
          }
        }
        break;
      }
    }

    if (!flag) {
      ++Answer;
    }
  }

  int do_main(int argc, const char *argv[]) {
    int C;

    cin >> C;

    for (int i = 0; i < C; ++i) {
      cin >> N >> M;

      initialize();
      for (int j = 0; j < M; ++j) {
        int a, b;
        cin >> a >> b;

        if (a > b) {
          int temp = b;
          b = a;
          a = temp;
        }

        Link[a].push_back(b);
      }

      process();

      cout << Answer << endl;
    }

    return 0;
  }
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
    return PICNIC::do_main(argc, argv);
}

#endif
