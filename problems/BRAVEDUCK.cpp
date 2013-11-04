/**
* BRAVEDUCK
*
* @author Chiwan Park
* @solved 2013. 11. 04
*
* http://algospot.com/judge/problem/read/BRAVEDUCK
*/
#include <iostream>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

namespace BRAVEDUCK {
    const int MaxN = 100;

    int J, N;
    pair<int, int> Stones[MaxN + 2];
    queue<int> Queue;
    int Visited[MaxN + 2];

    inline int distance(pair<int, int> a, pair<int, int> b) {
        return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    }

    void do_bfs(void) {
        int v;
        pair<int, int> vpos;

        Visited[0] = 1;
        Queue.push(0);

        while (!Queue.empty()) {
            v = Queue.front();
            vpos = Stones[v];
            Queue.pop();

            for (int i = 0; i < N + 2; ++i) {
                if (!Visited[i] && J * J >= distance(vpos, Stones[i])) {
                    Queue.push(i);
                    Visited[i] = 1;
                }
            }
        }
    }

    int do_main(int argc, const char *argv[]) {
        int T;

        cin >> T;
        for (int i = 0; i < T; ++i) {
            memset(Visited, 0, sizeof(Visited));

            cin >> J >> Stones[0].first >> Stones[0].second >> Stones[1].first >> Stones[1].second >> N;
            for (int j = 0; j < N; ++j)
                cin >> Stones[j + 2].first >> Stones[j + 2].second;

            do_bfs();

            if (Visited[1])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

        return 0;
    }
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
    return BRAVEDUCK::do_main(argc, argv);
}

#endif
