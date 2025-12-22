#include "iostream"
#include "vector"
using namespace std;

int count = 0;

// path = psf = path so far
void getMazePaths(int sr, int sc, int dr, int dc, string path) {
  // METHOD 1:
  // call smart, base case stupid
  if (sc == dc && sr == dr) {
    cout << path << endl;
    count++;
    return;
  }

  // HORIZONTAL MOVE
  if (sc < dc) {
    getMazePaths(sr, sc + 1, dr, dc, path + "h");
  }

  // VERTICAL MOVE
  if (sr < dr) {
    getMazePaths(sr + 1, sc, dr, dc, path + "v");
  }

  // METHOD 2:
  // call stupid, base case smart
  // if (sc > dc || sr > dc) {
  //   // out of bound chala gya, so return, no print
  //   return;
  // }

  // if (sc == dc && sr == dr) {
  //   cout << path << endl;
  //   count++;
  //   return;
  // }

  // // HORIZONTAL MOVE
  // getMazePaths(sr, sc + 1, dr, dc, path + "h");
  // // VERTICAL MOVE
  // getMazePaths(sr + 1, sc, dr, dc, path + "v");
}

int main() {

  cout << "print maze path" << endl << endl;

  int m, n;
  cout << "Enter value of m & n: ";
  cin >> m >> n;

  getMazePaths(1, 1, m, n, "");
  cout << "Total no. of the paths: " << count << endl;
  return 0;
}