/**
* MISPELL
*
* @author Chiwan Park
* @solved 2013. 11. 04
*
* http://algospot.com/judge/problem/read/MISPELL
*/
#include <iostream>
#include <string>

using namespace std;

int do_MISPELL_main(int argc, const char *argv[]) {
    int N, pos;
    string input;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> pos >> input;
        cout << i + 1 << " " << input.substr(0, pos - 1) << input.substr(pos, input.length() - pos) << endl;
    }
    return 0;
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
    return do_MISPELL_main(argc, argv);
}

#endif
