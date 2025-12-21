#include "iostream"
#include "vector"

using namespace std;

int firstIndex(vector<int> &arr, size_t idx, int data) {
  if (idx == arr.size()) {
    return -1;
  }
  // first index in samller array
  // but if compare the first occurance while coming from top to bottom in stack
  // int fiisa = firstIndex(arr, idx + 1, data);
  // if (arr[idx] == data) {
  //   return idx;
  // } else {
  //   return fiisa;
  // }

  // this one is efficient
  if (arr[idx] == data) {
    return idx;
  } else {
    int fiisa = firstIndex(arr, idx + 1, data);
    return fiisa;
  }
}
int main() {

  cout << "last index of occurance in array" << endl << endl;

  vector<int> arr = {2, 3, 6, 9, 8, 3, 2, 6, 2, 4};

  int data;
  cout << "Enter the no. to find its index: ";
  cin >> data;

  int first_idx = firstIndex(arr, 0, data);
  cout << "First index of " << data << " : " << first_idx << endl;

  return 0;
}