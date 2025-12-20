#include "iostream"
#include "vector"

using namespace std;

// int --> size_t fix the g++ compiler warning
int arrMaxRecursion(vector<int> &arr, size_t idx) {
  // at last elem of array
  if (idx == arr.size() - 1)
    // as it is last then it will be returned
    return arr[idx];

  // max in smaller array
  int misa = arrMaxRecursion(arr, idx + 1);
  if (arr[idx] > misa) {
    return arr[idx];
  } else {
    return misa;
  }
}

int main() {

  cout << "max of an array" << endl << endl;

  int n;
  cout << "Enter the size of an array: ";
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int max = arrMaxRecursion(arr, 0);
  if (max != -1) {
    cout << "max value: " << max << endl;
  }
  return 0;
}