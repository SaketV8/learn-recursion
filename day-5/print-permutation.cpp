#include "iostream"
#include "vector"
using namespace std;

int count = 0;

// psf = path so far
void printPermutation(string ques, string psf) {
  if (ques.size() == 0) {
    cout << psf << endl;
    count++;
    return;
  }

  for (size_t i = 0; i < ques.size(); i++) {
    // base case
    // get individual char
    char ch = ques.at(i);
    // get ros ==> remaing string, without the char we choose above
    string left = ques.substr(0, i);
    string right = ques.substr(i + 1);
    string ros = left + right;
    printPermutation(ros, psf + ch);
  }
}
int main() {

  cout << "print permutation" << endl << endl;

  printPermutation("abcd", "");
  cout << "Total no. of the ways: " << count << endl;
  return 0;
}