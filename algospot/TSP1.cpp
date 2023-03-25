/**
* TSP1
*
* @author Chiwan Park
* @solved 2013. 11. 04
*
* http://algospot.com/judge/problem/read/TSP1
*/
#include <iostream>
#include <cstring>

using namespace std;

namespace TSP1 {
    const int MaxN = 8;

    int N;
    double Edge[MaxN][MaxN];
    double MinEdge[MaxN];
    double Minimized;
    int Visited[MaxN];

    void initialize(void) {
        memset(Edge, 0, sizeof(Edge));
        memset(Visited, 0, sizeof(Visited));
        for (int i = 0; i < 8; ++i)
            MinEdge[i] = 30000;
        Minimized = 30000;
    }

    double calculate_bound(double sum) {
        for (int i = 0; i < N; ++i) {
            if (!Visited[i])
                sum += MinEdge[i];
        }

        return sum;
    }

    void do_backtracking(int v, double sum, int count) {
        Visited[v] = 1;

        if (count == N) {
            if (Minimized > sum)
                Minimized = sum;
        } else if (Minimized >= calculate_bound(sum)) {
            for (int i = 0; i < N; ++i) {
                if (Visited[i])
                    continue;

                do_backtracking(i, sum + Edge[v][i], count + 1);
            }
        }

        Visited[v] = 0;
    }

    int do_main(int argc, const char *argv[]) {
        int C;

        cout.setf(ios::fixed);
        cout.precision(10);

        cin >> C;
        for (int i = 0; i < C; ++i) {
            cin >> N;

            initialize();
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    cin >> Edge[j][k];
                    if (MinEdge[j] > Edge[j][k])
                        MinEdge[j] = Edge[j][k];
                }
            }

            for (int j = 0; j < N; ++j)
                do_backtracking(j, 0, 1);

            cout << Minimized << endl;
        }

        return 0;
    }
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
    return TSP1::do_main(argc, argv);
}

#endif
