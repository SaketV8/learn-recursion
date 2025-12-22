#include "iostream"
#include "vector"

using namespace std;

// sr = source row
// sc = source column
// dr = destination row
// dc = destinantion column
vector<string> getMazePathsWithJumps(int sr, int sc, int dr, int dc) {
  // base case
  if (sr == dr && sc == dc) {
    // we are at position no need to move
    return {""};
  }
  vector<string> paths;

  // HORIZONTAL PATH
  // no of horizontal moves = dc - sc
  // ms = move size
  // ms <= dc - sc, limit so that we are not out of maze
  for (int ms = 1; ms <= dc - sc; ms++) {
    // my faith, after the horizontal jump, we have our path to destination
    vector<string> hpaths = getMazePathsWithJumps(sr, sc + ms, dr, dc);
    // faith to expectation
    // sc --> sc+ms ==converted==> sc --> dc by prefixing the "h" + <ms>
    for (auto &hpath : hpaths) {
      // like h1 or h2 or h3 etc
      paths.push_back("h" + to_string(ms) + hpath);
    }
  }

  // VERTICAL PATH
  // no of vertical moves = dr - sr
  // ms = move size
  // ms <= dr - sr, limit so that we are not out of maze
  for (int ms = 1; ms <= dr - sr; ms++) {
    // my faith, after the horizontal jump, we have our path to destination
    vector<string> vpaths = getMazePathsWithJumps(sr + ms, sc, dr, dc);
    // faith to expectation
    // sr --> sr+js ==converted==> sr --> dr by prefixing the "v" + <ms>
    for (auto &vpath : vpaths) {
      // like v1 or v2 or v3 etc
      paths.push_back("v" + to_string(ms) + vpath);
    }
  }

  // DIAGONAL PATH
  // ms = move size
  // ms <= dr - sr && ms <= dc - sc  , limit so that we are not out of maze
  for (int ms = 1; ms <= dr - sr && ms <= dc - sc; ms++) {
    // my faith, after the horizontal jump, we have our path to destination
    vector<string> dpaths = getMazePathsWithJumps(sr + ms, sc + ms, dr, dc);
    // faith to expectation
    for (auto &dpath : dpaths) {
      // like d1 or d2 or d3 etc
      paths.push_back("d" + to_string(ms) + dpath);
    }
  }

  return paths;
}

int main() {

  cout << "get maze path with jump" << endl << endl;
  int m, n;
  cout << "Enter value of m & n: ";
  cin >> m >> n;

  cout << "[ ";
  vector<string> paths = getMazePathsWithJumps(1, 1, m, n);
  for (auto &s : paths) {
    cout << s << ", ";
  }
  cout << "] -> " << paths.size() << " ways available" << endl;

  return 0;
}