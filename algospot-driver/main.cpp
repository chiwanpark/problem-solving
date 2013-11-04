/**
* Driver Program for Algospot Problem Solving
*
* @author Chiwan Park
* @created 2013. 11. 04
*/
#include <iostream>
#include <map>
#include "problems.h"

using namespace std;

map<string, MAINFUNC> func_map;

void initialize_func_map(void) {
}

int main(int argc, const char *argv[]) {
    string problem;

    initialize_func_map();
    cin >> problem;

    if (func_map.find(problem) != func_map.end())
        return (*(func_map[problem]))(argc, argv);
    return -1;
}