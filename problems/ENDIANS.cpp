/**
* ENDIANS
*
* @author Chiwan Park
* @solved 2013. 11. 04
*
* http://algospot.com/judge/problem/read/ENDIANS
*/
#include <iostream>

using namespace std;

int do_ENDIANS_main(int argc, const char *argv[]) {
    int C;
    unsigned int input, answer;

    cin >> C;
    for (int i = 0; i < C; ++i) {
        cin >> input;
        answer = 0;

        for (int j = 0; j < 4; ++j) {
            answer <<= 8;
            answer += input & 0xFF;
            input >>= 8;
        }

        cout << answer << endl;
    }

    return 0;
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
    return do_ENDIANS_main(argc, argv);
}

#endif
