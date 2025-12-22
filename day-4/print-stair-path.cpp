#include "iostream"
#include "vector"
using namespace std;

int count = 0;

void printStairPath(int n, string path) {
  if (n == 0) {
    cout << path << endl;
    count++;
    return;
  } else if (n < 0) {
    // we are in basement, there's no way, its fraud path
    return;
  }
  // leveled options
  // for 3 type jump, put all these option via call

  // jumps 1 stairs
  printStairPath(n - 1, path + "1");
  // jumps 2 stairs
  printStairPath(n - 2, path + "2");
  // jumps 3 stairs
  printStairPath(n - 3, path + "3");
}

int main() {

  cout << "print stair path" << endl << endl;

  int n;
  cout << "Enter the value of n: ";
  cin >> n;
  printStairPath(n, "");
  cout << "Total no. of the subsequence: " << count << endl;
  return 0;
}