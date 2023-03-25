/**
* TILIING2
*
* @author Chiwan Park
* @solved 2017. 10. 10
*
* http://algospot.com/judge/problem/read/TILING2
*/
#include <iostream>

using namespace std;

namespace TILING2 {
    const int MaxN = 100;
    const int Divisor = 1000000007;

    int Dy[MaxN + 1];

    void do_dynamic() {
        Dy[0] = 1;
        Dy[1] = 1;

        for (int i = 2; i <= MaxN; ++i) {
            Dy[i] = (Dy[i - 1] + Dy[i - 2]) % Divisor;
        }
    }

    int do_main(int argc, const char *argv[]) {
        int C, N;

        do_dynamic();

        cin >> C;
        for (int i = 0; i < C; ++i) {
            cin >> N;
            cout << Dy[N] << endl;
        }

        return 0;
    }
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
    return TILING2::do_main(argc, argv);
}

#endif
