/**
 * BOGGLE
 *
 * @author Chiwan Park
 * @solved 2014. 07. 29
 *
 * http://algospot.com/judge/problem/read/BOGGLE
 */
#include <iostream>
#include <queue>
#include <string>

using namespace std;

namespace BOGGLE {
const int BoardX = 5;
const int BoardY = 5;
const int NumPosState = BoardX * BoardY;
const int MaxWordLen = 10;
const int Move[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

vector<string> Board(BoardY);

bool search(string word) {
  queue<pair<int, int>> states;
  vector<vector<bool>> visit(NumPosState);

  // insert init state to queue
  for (int i = 0; i < BoardY; ++i) {
    for (int j = 0; j < BoardX; ++j) {
      if (word[0] == Board[i][j]) {
        states.push(pair<int, int>(i * 5 + j, 0));
      }
    }
  }

  // initialize visit
  for (int i = 0; i < NumPosState; ++i) {
    visit[i] = vector<bool>(MaxWordLen, false);
  }

  while (!states.empty()) {
    pair<int, int> current = states.front();
    states.pop();

    if (current.second == word.size() - 1) {
      return true;
    }

    int cx = current.first % 5, cy = current.first / 5;

    for (int i = 0; i < 8; ++i) {
      int nx = cx + Move[i][0], ny = cy + Move[i][1];
      pair<int, int> next = pair<int, int>(ny * 5 + nx, current.second + 1);

      if (nx >= 0 && nx < BoardX && ny >= 0 && ny < BoardY // in boundary
          && Board[ny][nx] == word[current.second + 1]     // and word character is same
          && visit[next.first][next.second] == false) {    // no visited
        visit[next.first][next.second] = true;
        states.push(next);
      }
    }
  }

  return false;
}

int do_main(const int argc, const char *argv[]) {
  int C;

  cin >> C;
  for (int i = 0; i < C; ++i) {
    int N;
    for (int j = 0; j < 5; ++j) {
      cin >> Board[j];
    }

    cin >> N;
    for (int j = 0; j < N; ++j) {
      string word;
      cin >> word;

      if (search(word)) {
        cout << word << " "
             << "YES" << endl;
      } else {
        cout << word << " "
             << "NO" << endl;
      }
    }
  }
  return 0;
}
} // namespace BOGGLE

#ifndef DRIVER

int main(int argc, const char *argv[]) { return BOGGLE::do_main(argc, argv); }

#endif
