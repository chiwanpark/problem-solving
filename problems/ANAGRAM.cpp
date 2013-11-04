/**
* ANAGRAM
*
* @author Chiwan Park
* @solved 2013. 11. 04
*
* http://algospot.com/judge/problem/read/ANAGRAM
*/
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

namespace ANAGRAM {
    bool is_valid_password(string serial, string password) {
        if (serial == password)
            return false;

        map<char, int> cnt_serial;
        for (string::iterator iter = serial.begin(), end = serial.end(); iter != end; ++iter)
            ++cnt_serial[*iter];
        for (string::iterator iter = password.begin(), end = password.end(); iter != end; ++iter)
            --cnt_serial[*iter];

        for (map<char, int>::iterator iter = cnt_serial.begin(), end = cnt_serial.end(); iter != end; ++iter) {
            if (iter->second != 0)
                return false;
        }

        return true;
    }

    int do_main(int argc, const char *argv[]) {
        int T;
        string serial, password;

        cin >> T;
        for (int i = 0; i < T; ++i) {
            cin >> serial >> password;

            if (is_valid_password(serial, password))
                cout << "Yes" << endl;
            else
                cout << "No." << endl;
        }

        return 0;
    }
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
    return ANAGRAM::do_main(argc, argv);
}

#endif
