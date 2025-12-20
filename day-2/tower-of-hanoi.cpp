#include "iostream"

using namespace std;

// no. version of tower
void toh(int n, int t1, int t2, int t3) {
  // when we have 0 disk remaining
  if (n == 0)
    return;
  toh(n - 1, t1, t3, t2);
  cout << n << "[" << t1 << "-->" << t2 << "]" << endl;
  toh(n - 1, t3, t2, t1);
}

// string version of tower
void tohStr(int n, string src, string dest, string helper) {
  if (n == 0)
    return;

  tohStr(n - 1, src, helper, dest);
  cout << n << "[" << src << "-->" << dest << "]" << endl;
  tohStr(n - 1, helper, dest, src);
}

int main() {

  cout << "Tower of Hanoi" << endl << endl;

  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  toh(n, 10, 11, 12);

  cout << "====================" << endl;

  tohStr(n, "A", "B", "C");

  return 0;
}

// ==========================================================
// Rules for tower of Hanoi
// ==========================================================
// 3.1 print instruction to move the disks
// 3.2 from tower 1 to tower 2 using tower 3
// 3.3 followin gthe rules
//    3.3.1 move 1 disk at a time
//    3.3.2 never place a smaller disk under a larger disk
//    3.3.3 you can only move a disk at the top
// ==========================================================