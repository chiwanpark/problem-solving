/**
* LECTURE
*
* @author Chiwan Park
* @solved 2013. 11. 04
*
* http://algospot.com/judge/problem/read/LECTURE
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

namespace LECTURE {
    int encode(string s) {
        return ((int) ((s[0] - 'a')) << 8) + (int) (s[1] - 'a');
    }

    string decode(int i) {
        return string(1, (char) ('a' + (i >> 8))) + string(1, (char) ('a' + (i & 0xFF)));
    }

    int do_main(int argc, const char *argv[]) {
        int T;
        string input;
        vector<int> data;

        cin >> T;
        for (int i = 0; i < T; ++i) {
            cin >> input;
            data.clear();
            for (int j = 0, length = input.length(); j < length; j += 2) {
                string substring = input.substr(j, 2);
                data.push_back(encode(substring));
            }

            sort(data.begin(), data.end());

            for (vector<int>::iterator iter = data.begin(), end = data.end(); iter != end; ++iter)
                cout << decode(*iter);
            cout << endl;
        }

        return 0;
    }
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
    return LECTURE::do_main(argc, argv);
}

#endif
