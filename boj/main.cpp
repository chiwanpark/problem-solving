/**
 * Driver Program for Backjoon Online Judge Problem Solving
 *
 * @author Chiwan Park
 * @created 2023. 03. 25
 */
#include <iostream>
#include <limits>
#include <map>

#include "problems.h"

using namespace std;

map<string, MAINFUNC> func_map;

void initialize_func_map(void) {
  func_map["10699"] = BOJ_10699::do_main;
  func_map["10998"] = BOJ_10998::do_main;
  func_map["10869"] = BOJ_10869::do_main;
  func_map["1010"] = BOJ_1010::do_main;
  func_map["4673"] = BOJ_4673::do_main;
  func_map["2178"] = BOJ_2178::do_main;
  func_map["2667"] = BOJ_2667::do_main;
  func_map["1149"] = BOJ_1149::do_main;
  func_map["1000"] = BOJ_1000::do_main;
  func_map["1001"] = BOJ_1001::do_main;
  func_map["1015"] = BOJ_1015::do_main;
  func_map["1038"] = BOJ_1038::do_main;
  func_map["1697"] = BOJ_1697::do_main;
  func_map["1008"] = BOJ_1008::do_main;
  func_map["11382"] = BOJ_11382::do_main;
  func_map["1011"] = BOJ_1011::do_main;
  func_map["1152"] = BOJ_1152::do_main;
  func_map["1157"] = BOJ_1157::do_main;
  func_map["1197"] = BOJ_1197::do_main;
  func_map["1330"] = BOJ_1330::do_main;
  func_map["1546"] = BOJ_1546::do_main;
  func_map["1167"] = BOJ_1167::do_main;
  func_map["1238"] = BOJ_1238::do_main;
  func_map["1504"] = BOJ_1504::do_main;
  func_map["1629"] = BOJ_1629::do_main;
  func_map["1967"] = BOJ_1967::do_main;
  func_map["1932"] = BOJ_1932::do_main;
  func_map["1753"] = BOJ_1753::do_main;
  func_map["2438"] = BOJ_2438::do_main;
  func_map["2439"] = BOJ_2439::do_main;
  func_map["2562"] = BOJ_2562::do_main;
  func_map["2675"] = BOJ_2675::do_main;
  func_map["2739"] = BOJ_2739::do_main;
  func_map["2920"] = BOJ_2920::do_main;
  func_map["2206"] = BOJ_2206::do_main;
  func_map["9663"] = BOJ_9663::do_main;
  func_map["11049"] = BOJ_11049::do_main;
  func_map["11053"] = BOJ_11053::do_main;
  func_map["12015"] = BOJ_12015::do_main;
  func_map["14003"] = BOJ_14003::do_main;
  func_map["2475"] = BOJ_2475::do_main;
  func_map["2741"] = BOJ_2741::do_main;
  func_map["10950"] = BOJ_10950::do_main;
  func_map["4153"] = BOJ_4153::do_main;
  func_map["30802"] = BOJ_30802::do_main;
  func_map["11660"] = BOJ_11660::do_main;
  func_map["18870"] = BOJ_18870::do_main;
}

int main(int argc, const char *argv[]) {
  string problem;

  initialize_func_map();
  cin >> problem;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (func_map.find(problem) != func_map.end()) {
    return (*(func_map[problem]))(argc, argv);
  }
  return -1;
}
