/**
 * Driver Program for Backjoon Online Judge Problem Solving
 *
 * @author Chiwan Park
 * @created 2023. 03. 25
 */
#include <iostream>
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
}

int main(int argc, const char *argv[]) {
  string problem;

  initialize_func_map();
  cin >> problem;

  if (func_map.find(problem) != func_map.end()) {
    return (*(func_map[problem]))(argc, argv);
  }
  return -1;
}