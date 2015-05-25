/**
* CLOCKSYNC
*
* @author Chiwan Park
* @solved 2015. 05. 25
*
* http://algospot.com/judge/problem/read/CLOCKSYNC
*/
#include <iostream>
#include <array>
#include <queue>
#include <tuple>

using namespace std;

namespace CLOCKSYNC {
  const int MaxState = 1048576;
  const int Clocks = 16;

  const int click_map[10][5] = {{0, 1,  2,  -1}, // 0
                                {3, 7,  9,  11, -1}, // 1
                                {4, 10, 14, 15, -1}, // 2
                                {0, 4,  5,  6,  7}, // 3
                                {6, 7,  8,  10, 12}, // 4
                                {0, 2,  14, 15, -1}, // 5
                                {3, 14, 15, -1}, // 6
                                {4, 5,  7,  14, 15}, // 7
                                {1, 2,  3,  4,  5}, // 8
                                {3, 4,  5,  9,  13}}; // 9

  inline unsigned int next_bit(unsigned int current, int position, int base) {
    int shift = base - (2 * position);
    return (((((current >> shift) & 3) + 1) % 4) << shift) | (current & (~(3 << shift)));
  }

  tuple<unsigned int, int, int> next_state(tuple<unsigned int, int, int> current, int button) {
    unsigned int clockState;
    int clicked;
    int count;

    tie(clockState, clicked, count) = current;

    clicked = next_bit((unsigned int) clicked, button, 18);
    count += 1;

    for (int i = 0; i < 5 && click_map[button][i] >= 0; ++i) {
      clockState = next_bit(clockState, click_map[button][i], 30);
    }

    return make_tuple(clockState, clicked, count);
  }

  int process(unsigned int initial) {
    array<bool, MaxState> visit{};
    queue<tuple<unsigned int, int, int>> q; // first = current clock state, second = clicked state, third = count

    q.push(make_tuple(initial, 0, 0));
    visit[0] = true;
    while (!q.empty()) {
      tuple<unsigned int, int, int> current = q.front();
      q.pop();

      if (get<0>(current) == 0) {
        return get<2>(current);
      }

      for (int i = 0; i <= 9; ++i) {
        tuple<unsigned int, int, int> next = next_state(current, i);
        if (!visit[get<1>(next)]) {
          visit[get<1>(next)] = true;
          q.push(next);
        }
      }
    }

    return -1;
  }

  int do_main(int argc, const char *argv[]) {
    int C;

    cin >> C;
    for (int i = 0; i < C; ++i) {
      unsigned int clockState = 0;

      for (int j = 0; j < Clocks; ++j) {
        unsigned int current;
        cin >> current;
        current = (current / 3) % 4;
        clockState = (clockState << 2) + current;
      }

      cout << process(clockState) << endl;
    }
    return 0;
  }
}

#ifndef DRIVER

int main(int argc, const char *argv[]) {
  return CLOCKSYNC::do_main(argc, argv);
}

#endif
