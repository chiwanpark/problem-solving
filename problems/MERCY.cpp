/**
* MERCY
*
* @author Chiwan Park
* @solved 2013. 11. 04
*
* http://algospot.com/judge/problem/read/MERCY
*/
#include <iostream>

using namespace std;

int do_MERCY_main(int argc, const char *argv[]) {
    int N;

    cin >> N;
    for (int i = 0; i < N; ++i)
        cout << "Hello Algospot!" << endl;

    return 0;
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
    return do_MERCY_main(argc, argv);
}

#endif
