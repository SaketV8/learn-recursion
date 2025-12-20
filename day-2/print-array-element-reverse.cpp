#include "iostream"
#include "vector"

using namespace std;

void printArrayReverse(vector<int> &arr, int idx) {
  if (idx == arr.size())
    return;

  printArrayReverse(arr, idx + 1);
  cout << arr[idx] << endl ;
}

int main() {

  cout << "Print an array element in reverse" << endl << endl;

  int n;
  cout << "Enter the size of an array: ";
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  printArrayReverse(arr, 0);

  return 0;
}