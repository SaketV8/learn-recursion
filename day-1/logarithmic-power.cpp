#include "iostream"

using namespace std;

int powerLogarithmic(int x, int n) {
  if (n == 0)
    return 1;

  // method 1
  // // for even
  // if (n % 2 == 0) {
  //   return powerLogarithmic(x, n / 2) * powerLogarithmic(x, n / 2);

  // // for odd
  // } else {
  //   return x * powerLogarithmic(x, n / 2) * powerLogarithmic(x, n / 2);
  // }

  // method 2
  int xpn2 = powerLogarithmic(x, n / 2);

  int xn = xpn2 * xpn2;
  
  if (x % 2 != 0) {
    xn = x * xn;
  }

  return xn;
}

int main() {

  cout << powerLogarithmic(5, 3) << endl;

  cout << endl;
  return 0;
}
