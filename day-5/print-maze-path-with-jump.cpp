#include "iostream"
#include "vector"
using namespace std;

int count = 0;

// psf = path so far
void printMazePathsWithJump(int sr, int sc, int dr, int dc, string psf) {
  // HEAR CALL IS SMART
  // BASE CASE IS DUMB

  // base case
  if (sr == dr && sc == dc) {
    cout << psf << endl;
    count++;
    return;
  }
  // horizonatal jump
  for (int ms = 1; ms <= dc - sc; ms++) {
    printMazePathsWithJump(sr, sc + ms, dr, dc, "h" + to_string(ms) + psf);
  }

  // vertical jump
  for (int ms = 1; ms <= dr - sr; ms++) {
    printMazePathsWithJump(sr + ms, sc, dr, dc, "v" + to_string(ms) + psf);
  }
  // diagonal jump
  for (int ms = 1; ms <= dr - sr && ms <= dc - sc; ms++) {
    printMazePathsWithJump(sr + ms, sc + ms, dr, dc, "d" + to_string(ms) + psf);
  }
}
int main() {

  cout << "print maze path with jump" << endl << endl;

  int m, n;
  cout << "Enter value of m & n: ";
  cin >> m >> n;

  printMazePathsWithJump(1, 1, m, n, "");
  cout << "Total no. of the paths: " << count << endl;
  return 0;
}