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
    func_map["HELLOWORLD"] = HELLOWORLD::do_main;
    func_map["MERCY"] = MERCY::do_main;
    func_map["DRAWRECT"] = DRAWRECT::do_main;
    func_map["LECTURE"] = LECTURE::do_main;
    func_map["CONVERT"] = CONVERT::do_main;
    func_map["HOTSUMMER"] = HOTSUMMER::do_main;
    func_map["XHAENEUNG"] = XHAENEUNG::do_main;
    func_map["ENCRYPT"] = ENCRYPT::do_main;
    func_map["MISPELL"] = MISPELL::do_main;
    func_map["ENDIANS"] = ENDIANS::do_main;
    func_map["MAXSUM"] = MAXSUM::do_main;
    func_map["COINS"] = COINS::do_main;
    func_map["DIAMONDPATH"] = DIAMONDPATH::do_main;
    func_map["TSP1"] = TSP1::do_main;
    func_map["LIS"] = LIS::do_main;
    func_map["BRAVEDUCK"] = BRAVEDUCK::do_main;
    func_map["ANAGRAM"] = ANAGRAM::do_main;
    func_map["MEETING"] = MEETING::do_main;
    func_map["STRJOIN"] = STRJOIN::do_main;
    func_map["GRID"] = GRID::do_main;
    func_map["CHRISTMAS"] = CHRISTMAS::do_main;
    func_map["PICNIC"] = PICNIC::do_main;
    func_map["JOSEPHUS"] = JOSEPHUS::do_main;
    func_map["BOGGLE"] = BOGGLE::do_main;
    func_map["BRACKETS2"] = BRACKETS2::do_main;
    func_map["ZEROONE"] = ZEROONE::do_main;
    func_map["CSBASEBALL"] = CSBASEBALL::do_main;
    func_map["NQUEEN"] = NQUEEN::do_main;
    func_map["BRACKETS"] = BRACKETS::do_main;
    func_map["FIX"] = FIX::do_main;
    func_map["YULO"] = YULO::do_main;
    func_map["JUMPGAME"] = JUMPGAME::do_main;
    func_map["TRIANGLEPATH"] = TRIANGLEPATH::do_main;
    func_map["CLOCKSYNC"] = CLOCKSYNC::do_main;
    func_map["TILING2"] = TILING2::do_main;
}

int main(int argc, const char *argv[]) {
    string problem;

    initialize_func_map();
    cin >> problem;

    if (func_map.find(problem) != func_map.end())
        return (*(func_map[problem]))(argc, argv);
    return -1;
}
