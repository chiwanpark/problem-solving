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
    func_map["HELLOWORLD"] = do_HELLOWORLD_main;
    func_map["MERCY"] = do_MERCY_main;
    func_map["DRAWRECT"] = do_DRAWRECT_main;
    func_map["LECTURE"] = do_LECTURE_main;
    func_map["CONVERT"] = do_CONVERT_main;
    func_map["HOTSUMMER"] = do_HOTSUMMER_main;
    func_map["XHAENEUNG"] = do_XHAENEUNG_main;
    func_map["ENCRYPT"] = do_ENCRYPT_main;
    func_map["MISPELL"] = do_MISPELL_main;
    func_map["ENDIANS"] = do_ENDIANS_main;
    func_map["MAXSUM"] = do_MAXSUM_main;
    func_map["COIN"] = do_COIN_main;
}

int main(int argc, const char *argv[]) {
    string problem;

    initialize_func_map();
    cin >> problem;

    if (func_map.find(problem) != func_map.end())
        return (*(func_map[problem]))(argc, argv);
    return -1;
}
