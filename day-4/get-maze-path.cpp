#include "iostream"
#include "vector"

using namespace std;

// sr = source row
// sc = source column
// dr = destination row
// dc = destinantion column
vector<string> getMazePaths(int sr, int sc, int dr, int dc) {
  if (sr == dr && sc == dc) {
    return {""};
  }

  vector<string> hpaths;
  vector<string> vpaths;

  // if sc < dc them we can move horizontally otherwise we are out of maze
  if (sc < dc) {
    // if we move horizontal in maze column++
    hpaths = getMazePaths(sr, sc + 1, dr, dc);
  }

  // if sr < dr them we can move vertically otherwise we are out of maze
  if (sr < dr) {
    // if we move vertical in maze row++
    vpaths = getMazePaths(sr + 1, sc, dr, dc);
  }

  // resultant path
  vector<string> paths;
  for (auto &hpath : hpaths) {
    paths.push_back("h" + hpath);
  }

  for (auto &vpath : vpaths) {
    paths.push_back("v" + vpath);
  }

  return paths;
}

int main() {

  cout << "get maze path" << endl << endl;
  int m, n;
  cout << "Enter value of m & n: ";
  cin >> m >> n;

  cout << "[ ";
  vector<string> paths = getMazePaths(1, 1, m, n);
  for (auto &s : paths) {
    cout << s << ", ";
  }
  cout << "] -> " << paths.size() << " ways available" << endl;

  return 0;
}