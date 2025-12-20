#include "iostream"

using namespace std;

void pzz(int n) {
  if (n == 0)
    return;

  cout << "Pre: " << n << endl;
  pzz(n - 1);
  cout << "In: " << n << endl;
  pzz(n - 1);
  cout << "Post: " << n << endl;
}

int main() {

  cout << "Understanding the flow of recursion" << endl << endl;

  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  pzz(n);

  return 0;
}

// ===========================================
// OUTPUT: (n = 2)
// ===========================================
// Pre: 2
// Pre: 1
// In: 1
// Post: 1
// In: 2
// Pre: 1
// In: 1
// Post: 1
// Post: 2
// ===========================================

// ===========================================
// OUTPUT: (n = 3)
// ===========================================
// Pre: 3
// Pre: 2
// Pre: 1
// In: 1
// Post: 1
// In: 2
// Pre: 1
// In: 1
// Post: 1
// Post: 2
// In: 3
// Pre: 2
// Pre: 1
// In: 1
// Post: 1
// In: 2
// Pre: 1
// In: 1
// Post: 1
// Post: 2
// Post: 3
// ===========================================