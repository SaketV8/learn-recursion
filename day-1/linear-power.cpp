#include "iostream"

using namespace std;

int powerLinear(int x, int n) {
  if (n == 0)
    return 1;
  // return x * powerLinear(x, n - 1);
  // return powerLinear(x, n - 1) * x;

  // multiline
  int xnm1 = powerLinear(x, n - 1);
  int xn = x * xnm1;

  return xn;
}

int main() {

  cout << powerLinear(6, 2) << endl;

  cout << endl;
  return 0;
}
