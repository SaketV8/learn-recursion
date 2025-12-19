#include "iostream"

using namespace std;

void printDecreasing(int n) {
  if (n == 0) {
    return;
  }
  cout << n << " ";
  printDecreasing(n - 1);
}

int main() {

  printDecreasing(7);

  cout << endl;
  return 0;
}
