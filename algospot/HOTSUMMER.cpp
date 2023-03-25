/**
* HOTSUMMER
*
* @author Chiwan Park
* @solved 2013. 11. 04
*
* http://algospot.com/judge/problem/read/HOTSUMMER
*/
#include <iostream>

using namespace std;

namespace HOTSUMMER {
    int do_main(int argc, const char *argv[]) {
        int T, value, sum, goal;

        cin >> T;
        for (int i = 0; i < T; ++i) {
            cin >> goal;

            sum = 0;
            for (int j = 0; j < 9; ++j) {
                cin >> value;
                sum += value;
            }

            if (sum > goal)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }

        return 0;
    }
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
    return HOTSUMMER::do_main(argc, argv);
}

#endif
