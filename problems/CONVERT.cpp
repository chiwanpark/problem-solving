/**
* CONVERT
*
* @author Chiwan Park
* @solved 2013. 11. 04
*
* http://algospot.com/judge/problem/read/CONVERT
*/
#include <iostream>
#include <iomanip>

using namespace std;

int do_CONVERT_main(int argc, const char *argv[]) {
    int N;
    double value;
    string unit;

    cin >> N;

    cout.setf(ios::fixed);
    cout.precision(4);

    for (int i = 0; i < N; ++i) {
        cin >> value >> unit;

        if (unit == "kg") {
            value *= 2.2046;
            unit = "lb";
        } else if (unit == "g") {
            value *= 3.7854;
            unit = "l";
        } else if (unit == "l") {
            value *= 0.2642;
            unit = "g";
        } else if (unit == "lb") {
            value *= 0.4536;
            unit = "kg";
        }

        cout << i + 1 << " " << value << " " << unit << endl;
    }

    return 0;
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
    return do_CONVERT_main(argc, argv);
}

#endif
