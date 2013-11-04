/**
* MEETING
*
* @author Chiwan Park
* @solved 2013. 11. 04
*
* http://algospot.com/judge/problem/read/MEETING
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace MEETING {
    int N;
    vector<int> male, female;

    inline int abs(int a) {
        return a < 0 ? -a : a;
    }

    void initialize(void) {
        male.assign(N, 0);
        female.assign(N, 0);
    }

    int calculate_min_diff(void) {
        sort(male.begin(), male.end());
        sort(female.begin(), female.end());

        int sum = 0;

        for (vector<int>::iterator iterMale = male.begin(), maleEnd = male.end(), iterFemale = female.begin();
                iterMale != maleEnd; ++iterMale, ++iterFemale)
            sum += abs(*iterFemale - *iterMale);

        return sum;
    }

    int do_main(int argc, const char *argv[]) {
        int T;

        cin >> T;
        for (int i = 0; i < T; ++i) {
            cin >> N;

            initialize();

            for (int j = 0; j < N; ++j)
                cin >> male[j];
            for (int j = 0; j < N; ++j)
                cin >> female[j];

            cout << calculate_min_diff() << endl;
        }

        return 0;
    }
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
    return MEETING::do_main(argc, argv);
}

#endif
