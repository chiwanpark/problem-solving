/**
* GRID
*
* @author Chiwan Park
* @solved 2014. 03. 22
*
* http://algospot.com/judge/problem/read/GRID
*/
#include <iostream>
#include <array>

using namespace std;

namespace GRID {
    const int MaxN = 1000;

    array<int, MaxN + 1> A, B, C;

    void do_dynamic() {
        A.fill(0), B.fill(0), C.fill(0);

        A[0] = 1, A[1] = 1, A[2] = 5;
        B[0] = 1, B[1] = 1, B[2] = 2;
        C[0] = 0, C[1] = 0, C[2] = 1;

        for (int i = 3; i <= MaxN; ++i) {
            C[i] = A[i - 2] + C[i - 2];
            B[i] = A[i - 1] + B[i - 1];
            A[i] = A[i - 2] + A[i - 1] + 2 * B[i - 1] + C[i];
        }
    }

    int do_main(int argc, const char *argv[]) {
        int C, N;

        do_dynamic();

        cin >> C;
        for (int i = 0; i < C; ++i) {
            cin >> N;
            cout << i + 1 << ' ' << A[N] << endl;
        }

        return 0;
    }
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
    return GRID::do_main(argc, argv);
}

#endif