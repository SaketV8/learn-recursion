#include "iostream"
#include "vector"

using namespace std;

vector<string> getStairPaths(int n) {
  if (n == 0) {
    // if at 0, then there's no path empty path, return vector of string
    // containing the empty string
    return {""}; // blank path, don't walk
    // ex => 1 + {""} = {1}
  } else if (n < 0) {
    // we are in below the ground, so there's no way, so we return empty vector
    return {}; // below the ground, you are stuck, fraud jump
    // ex => 1 + {} = {}
    // MOST IMPORTANT INTUITION
    // If paths is {}, the loop runs zero times, so, no addition of 1, 2 or 3
    // happen so, we can say => 1 + {} = {}
  }
  vector<string> paths1 = getStairPaths(n - 1);
  vector<string> paths2 = getStairPaths(n - 2);
  vector<string> paths3 = getStairPaths(n - 3);

  vector<string> resultant_paths;

  // these all are of post order ==> eulers tree
  for (string path : paths1) {
    resultant_paths.push_back('1' + path);
  }
  for (string path : paths2) {
    resultant_paths.push_back('2' + path);
  }
  for (string path : paths3) {
    resultant_paths.push_back('3' + path);
  }

  return resultant_paths;
};

int main() {

  cout << "get stair path" << endl << endl;

  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  cout << "[ ";
  vector<string> paths = getStairPaths(n);
  for (auto &s : paths) {
    cout << s << ", ";
  }

  cout << "] -> " << paths.size() << " ways available" << endl;

  return 0;
}