/**
* COIN
*
* @author Chiwan Park
* @solved 2013. 11. 04
*
* http://algospot.com/judge/problem/read/COINS
*/
#include <iostream>
#include <cstring>

using namespace std;

const int MaxCoin = 100;
const int MaxMoney = 5000;

int M, C;
int Coin[MaxCoin + 10];
int Dy[MaxMoney + 10];

void do_dynamic(void) {
    Dy[0] = 1;
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (j + Coin[i] <= M)
                Dy[j + Coin[i]] = (Dy[j + Coin[i]] + Dy[j]) % 1000000007;
        }
    }
}

int do_COIN_main(int argc, const char *argv[]) {
    int T;

    cin >> T;

    for (int i = 0; i < T; ++i) {
        memset(Dy, 0, sizeof(Dy));

        cin >> M >> C;
        for (int j = 0; j < C; ++j)
            cin >> Coin[j];

        do_dynamic();

        cout << Dy[M] << endl;
    }
    return 0;
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
    return do_COIN_main(argc, argv);
}

#endif
