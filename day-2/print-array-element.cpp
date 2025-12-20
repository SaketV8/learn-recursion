#include "iostream"
#include "vector"

using namespace std;

void printArray(vector<int> &arr, int idx) {
  if (idx == arr.size())
    return;

  cout << arr[idx] << endl;
  printArray(arr, idx + 1);
}

int main() {

  cout << "Print an array element" << endl << endl;

  int n;
  cout << "Enter the size of an array: ";
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  printArray(arr, 0);

  return 0;
}