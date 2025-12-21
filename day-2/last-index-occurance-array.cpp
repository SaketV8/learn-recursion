#include "iostream"
#include "vector"

using namespace std;

int lastIndex(vector<int> &arr, size_t idx, int data) {
  // last me a gaye nahi mila
  if (idx == arr.size()) {
    return -1;
  }
  // liisa ==> last index in small array
  int liisa = lastIndex(arr, idx + 1, data);

  if (liisa == -1) {
    if (arr[idx] == data) {
      return idx;
    } else {
      return -1;
    }
  } else {
    // liisa will bring the index; just return that.
    // liisa will either return -1 or i (where i ranges from 0 to arr.size()).
    return liisa;
  }
}

int main() {

  cout << "last index of occurance in array" << endl << endl;

  vector<int> arr = {2, 3, 6, 9, 8, 3, 2, 6, 2, 4};

  int data;
  cout << "Enter the no. to find its index: ";
  cin >> data;

  int last_idx = lastIndex(arr, 0, data);
  cout << "Last index of " << data << " : " << last_idx << endl;

  return 0;
}