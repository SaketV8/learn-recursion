#include "iostream"

using namespace std;

// func defintion
void A();
void B();
void C();

void A() {
  cout << "Line 1" << endl;
  B();
  cout << "Line 2" << endl;
}

void B() {
  cout << "Line 3" << endl;
  C();
  cout << "Line 4" << endl;
}

void C() { cout << "Line 5" << endl; }

int main() {

  A();

  return 0;
}
