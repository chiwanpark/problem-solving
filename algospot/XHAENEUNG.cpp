/**
* XHAENEUNG
*
* @author Chiwan Park
* @solved 2013. 11. 04
*
* http://algospot.com/judge/problem/read/XHAENEUNG
*/
#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

map<string, int> s2n_map;
map<int, string> n2s_map;

namespace XHAENEUNG {
    void initialize_number_map() {
        s2n_map["zero"] = 0;
        s2n_map["one"] = 1;
        s2n_map["two"] = 2;
        s2n_map["three"] = 3;
        s2n_map["four"] = 4;
        s2n_map["five"] = 5;
        s2n_map["six"] = 6;
        s2n_map["seven"] = 7;
        s2n_map["eight"] = 8;
        s2n_map["nine"] = 9;
        s2n_map["ten"] = 10;

        for (map<string, int>::iterator iter = s2n_map.begin(), end = s2n_map.end(); iter != end; ++iter) {
            string english = iter->first;
            sort(english.begin(), english.end());

            n2s_map[iter->second] = english;
        }

        s2n_map.clear();
        for (map<int, string>::iterator iter = n2s_map.begin(), end = n2s_map.end(); iter != end; ++iter)
            s2n_map[iter->second] = iter->first;
    }

    int s2n(string s) {
        sort(s.begin(), s.end());

        if (s2n_map.find(s) != s2n_map.end())
            return s2n_map[s];

        return -0xFFFF;
    }

    bool grade_answer(string A, char oper, string B, string C) {
        int iA = s2n(A), iB = s2n(B), iC = s2n(C);

        if (oper == '+')
            return ((iA + iB) == iC);
        else if (oper == '-')
            return ((iA - iB) == iC);
        else if (oper == '*')
            return ((iA * iB) == iC);

        return false;
    }

    int do_main(int argc, const char *argv[]) {
        int T;
        string A, B, C;
        char oper, equal;

        initialize_number_map();

        cin >> T;
        for (int i = 0; i < T; ++i) {
            cin >> A >> oper >> B >> equal >> C;

            if (grade_answer(A, oper, B, C))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }

        return 0;
    }
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
    return XHAENEUNG::do_main(argc, argv);
}

#endif
