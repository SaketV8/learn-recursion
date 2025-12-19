#include "iostream"

using namespace std;

int factorial(int n) {
  if (n == 1)
    return 1;

  // one liner
  // return n * factorial(n-1);

  // multi line code
  // fnm1 => factotrial of n - 1
  int fnm1 = factorial(n - 1);
  // fn => factotrial of n
  int fn = n * fnm1;
  return fn;
}

int main() {

  cout << factorial(5) << endl;

  cout << endl;
  return 0;
}
