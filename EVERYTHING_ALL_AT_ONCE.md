# 🌸 Recursion Practice

## Day 1

<details>
<summary>📄 factorial.cpp</summary>


<h3 align="center"> ⚡ factorial.cpp </h3>

```cpp
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

```
</details>

<details>
<summary>📄 linear-power.cpp</summary>


<h3 align="center"> ⚡ linear-power.cpp </h3>

```cpp
#include "iostream"

using namespace std;

int powerLinear(int x, int n) {
  if (n == 0)
    return 1;
  // return x * powerLinear(x, n - 1);
  // return powerLinear(x, n - 1) * x;

  // multiline
  int xnm1 = powerLinear(x, n - 1);
  int xn = x * xnm1;

  return xn;
}

int main() {

  cout << powerLinear(6, 2) << endl;

  cout << endl;
  return 0;
}

```
</details>

<details>
<summary>📄 logarithmic-power.cpp</summary>


<h3 align="center"> ⚡ logarithmic-power.cpp </h3>

```cpp
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

```
</details>

<details>
<summary>📄 print-decreasing.cpp</summary>


<h3 align="center"> ⚡ print-decreasing.cpp </h3>

```cpp
#include "iostream"

using namespace std;

void printDecreasing(int n) {
  if (n == 0) {
    return;
  }
  cout << n << " ";
  printDecreasing(n - 1);
}

int main() {

  printDecreasing(7);

  cout << endl;
  return 0;
}

```
</details>

<details>
<summary>📄 print-inc-dec.cpp</summary>


<h3 align="center"> ⚡ print-inc-dec.cpp </h3>

```cpp
#include "iostream"

using namespace std;

void printDecreasingIncreasing(int n) {
  if (n == 0)
    return;

  cout << n << " ";
  printDecreasingIncreasing(n - 1);
  cout << n << " ";
}

int main() {

  printDecreasingIncreasing(7);

  cout << endl;
  return 0;
}

```
</details>

<details>
<summary>📄 print-increasing.cpp</summary>


<h3 align="center"> ⚡ print-increasing.cpp </h3>

```cpp
#include "iostream"

using namespace std;

void printIncreasing(int n) {
  if (n == 0)
    return;

  printIncreasing(n - 1);
  cout << n << " ";
}

int main() {

  printIncreasing(7);

  cout << endl;
  return 0;
}

```
</details>

## Day 2

<details>
<summary>📄 first-index-occurance-array.cpp</summary>


<h3 align="center"> ⚡ first-index-occurance-array.cpp </h3>

```cpp
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
```
</details>

<details>
<summary>📄 last-index-occurance-array.cpp</summary>


<h3 align="center"> ⚡ last-index-occurance-array.cpp </h3>

```cpp
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
```
</details>

<details>
<summary>📄 max-array-element.cpp</summary>


<h3 align="center"> ⚡ max-array-element.cpp </h3>

```cpp
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
```
</details>

<details>
<summary>📄 print-array-element-reverse.cpp</summary>


<h3 align="center"> ⚡ print-array-element-reverse.cpp </h3>

```cpp
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
```
</details>

<details>
<summary>📄 print-array-element.cpp</summary>


<h3 align="center"> ⚡ print-array-element.cpp </h3>

```cpp
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
```
</details>

<details>
<summary>📄 print-zing-zag-pre-in-post.cpp</summary>


<h3 align="center"> ⚡ print-zing-zag-pre-in-post.cpp </h3>

```cpp
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
```
</details>

<details>
<summary>📄 tower-of-hanoi.cpp</summary>


<h3 align="center"> ⚡ tower-of-hanoi.cpp </h3>

```cpp
#include "iostream"

using namespace std;

// no. version of tower
void toh(int n, int t1, int t2, int t3) {
  // when we have 0 disk remaining
  if (n == 0)
    return;
  toh(n - 1, t1, t3, t2);
  cout << n << "[" << t1 << "-->" << t2 << "]" << endl;
  toh(n - 1, t3, t2, t1);
}

// string version of tower
void tohStr(int n, string src, string dest, string helper) {
  if (n == 0)
    return;

  tohStr(n - 1, src, helper, dest);
  cout << n << "[" << src << "-->" << dest << "]" << endl;
  tohStr(n - 1, helper, dest, src);
}

int main() {

  cout << "Tower of Hanoi" << endl << endl;

  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  toh(n, 10, 11, 12);

  cout << "====================" << endl;

  tohStr(n, "A", "B", "C");

  return 0;
}

// ==========================================================
// Rules for tower of Hanoi
// ==========================================================
// 3.1 print instruction to move the disks
// 3.2 from tower 1 to tower 2 using tower 3
// 3.3 followin gthe rules
//    3.3.1 move 1 disk at a time
//    3.3.2 never place a smaller disk under a larger disk
//    3.3.3 you can only move a disk at the top
// ==========================================================
```
</details>

## Day 3

<details>
<summary>📄 all-indices-array.cpp</summary>


<h3 align="center"> ⚡ all-indices-array.cpp </h3>

```cpp
#include "iostream"
#include "vector"

using namespace std;

// fsf = found so far
// fsf track how many data elem we found while going up in the stack
// and accordingly, we craete the size of an array to return the index
// containing arr
vector<int> getAllIndex(vector<int> &arr, int data, size_t idx, int fsf) {
  if (idx == arr.size()) {
    // one line
    // return vector<int>(fsf);

    // explainatory
    vector<int> temp(fsf);
    return temp;
  }
  if (arr[idx] == data) {
    // fsf will increase here, along with index
    vector<int> iarr = getAllIndex(arr, data, idx + 1, fsf + 1);
    // store the index in iarr vector while coming down from the stack, it will
    // run during coming down from stack because it lies below the call
    iarr[fsf] = idx;

    // returning the iarr (vector containing the index)
    return iarr;
  } else {
    // fsf will not increase here
    vector<int> iarr = getAllIndex(arr, data, idx + 1, fsf);
    return iarr;
  }
}

int main() {

  cout << "all indices in array" << endl << endl;

  vector<int> arr = {2, 3, 6, 9, 8, 3, 2, 6, 2, 4};

  int data;
  cout << "Enter the no. to find its index: ";
  cin >> data;

  vector<int> all_idx = getAllIndex(arr, data, 0, 0);

  cout << "Index of  " << data << " : " << endl;
  for (auto &idx : all_idx) {
    cout << idx << endl;
  }

  return 0;
}
```
</details>

<details>
<summary>📄 get-keypad-combination.cpp</summary>


<h3 align="center"> ⚡ get-keypad-combination.cpp </h3>

```cpp
#include "iostream"
#include "vector"

using namespace std;

// making it global
vector<string> codes = {".,",  "abc",  "def", "ghi", "jkl",
                        "mno", "pqrs", "tu",  "vwx", "yx"};

vector<string> getKPC(string str) {
  // base case
  if (str.size() == 0) {
    // when no char left in the str, we return the empty string vector
    // so that the rres which calling the getKPC can perform the action on
    // string in vector
    return {""};
  }

  // 678, solving using this in mind as example

  // first char
  char ch = str.at(0); // 6
  // ros = rest of string
  string ros = str.substr(1); // 78

  // rres = recursion result
  vector<string> rres = getKPC(ros); // give the 6(2x3 = 6) words of 78

  // mres = my result
  vector<string> mres;

  // now we can add the each char of 6 string from codes to the rres to get the
  // mres
  string code_for_ch = codes[ch - '0'];
  // ex. 6 --> pqrs
  // for (int i = 0; i < code_for_ch.size(); i++) {
  for (size_t i = 0; i < code_for_ch.size(); i++) {
    // getting each char <from code_for_ch> to add in each word in rres
    // ex. char_from_code = "pqrs" ==> char_from_code.at(i) --> p, q, r, s
    char char_from_code = code_for_ch.at(i);

    for (auto &s : rres) {
      mres.push_back(char_from_code + s);
      // mres.push_back(s + char_from_code);
    }
  }

  return mres;
}

vector<string> getKPC2(string str) {
  // base case
  if (str.size() == 0) {
    return {""};
  }

  char ch = str[0];
  string ros = str.substr(1);

  // faith
  vector<string> rres = getKPC2(ros);

  vector<string> result;
  string string_from_code = codes[ch - '0'];
  for (string &s : rres) {

    for (auto &ch : string_from_code) {
      result.push_back(ch + s);
    }
  }

  return result;
}
int main() {

  cout << "get keypad combination" << endl << endl;

  cout << "[ ";
  // vector<string> words = getKPC("678");
  vector<string> words = getKPC2("678");
  for (auto &s : words) {
    cout << s << ", ";
  }

  cout << "] -> " << words.size() << endl;
  return 0;
}
```
</details>

<details>
<summary>📄 get-stair-path.cpp</summary>


<h3 align="center"> ⚡ get-stair-path.cpp </h3>

```cpp
#include "iostream"
#include "vector"

using namespace std;

vector<string> getStairPaths(int n) {
  if (n == 0) {
    // if at 0, then there's no path empty path, return vector of string
    // containing the empty string
    return {""}; // blank path, don't walk
    // ex => 1 + {""} = {1}
  } else if (n < 0) {
    // we are in below the ground, so there's no way, so we return empty vector
    return {}; // below the ground, you are stuck, fraud jump
    // ex => 1 + {} = {}
    // MOST IMPORTANT INTUITION
    // If paths is {}, the loop runs zero times, so, no addition of 1, 2 or 3
    // happen so, we can say => 1 + {} = {}
  }
  vector<string> paths1 = getStairPaths(n - 1);
  vector<string> paths2 = getStairPaths(n - 2);
  vector<string> paths3 = getStairPaths(n - 3);

  vector<string> resultant_paths;

  // these all are of post order ==> eulers tree
  for (string path : paths1) {
    resultant_paths.push_back('1' + path);
  }
  for (string path : paths2) {
    resultant_paths.push_back('2' + path);
  }
  for (string path : paths3) {
    resultant_paths.push_back('3' + path);
  }

  return resultant_paths;
};

int main() {

  cout << "get stair path" << endl << endl;

  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  cout << "[ ";
  vector<string> paths = getStairPaths(n);
  for (auto &s : paths) {
    cout << s << ", ";
  }

  cout << "] -> " << paths.size() << " ways available" << endl;

  return 0;
}

// ===============================================================================
// ===============================================================================

// In case, we only need no of path (this is for climbing up)
int climbStairs2(int n) {
  // base case
  if (n == 0) {
    return 1;
  } else if (n < 0) {
    return 0;
  }

  // main
  // for climbing up, we are doing n-1, n-2
  // because these tells us about the remaining steps
  int ways1 = climbStairs2(n - 1);
  int ways2 = climbStairs2(n - 2);

  int result = 0;
  result += ways1;
  result += ways2;

  return result;
}

// ===============================================================================
// ===============================================================================

// In case, we only need no of path (this is for climbing up)
// using dp to solve the Leetcode problem
vector<int> dp;
int climbStairs3(int n) {
  // init the dp
  if (dp.empty()) {
    dp.assign(n + 1, -1);
  }

  // base case
  if (n == 0) {
    return 1;
  } else if (n < 0) {
    return 0;
  }

  // main code

  // if dp have the value use it
  if (dp[n] != -1) {
    return dp[n];
  }
  // for climbing up, we are doing n-1, n-2
  // because these tells us about the remaining steps
  int ways1 = climbStairs3(n - 1);
  int ways2 = climbStairs3(n - 2);

  int result = 0;
  result += ways1;
  result += ways2;

  // setting up the dp value
  dp[n] = result;
  return result;
}
```
</details>

<details>
<summary>📄 get-subsequence.cpp</summary>


<h3 align="center"> ⚡ get-subsequence.cpp </h3>

```cpp
#include "iostream"
#include "vector"

using namespace std;

vector<string> gss(string str) {
  if (str.size() == 0) {
    return {""};
  }
  // get sub str for smaller string
  char ch = str.at(0); // a
  // ros = res of string
  string ros = str.substr(1); // bc

  // rres = recursion result
  // we can call the gss(bc) one time and use it with both "-" and "a"
  // now need it to call it twice as we have done in gss2
  vector<string> rres = gss(ros); // [--, -c, b-, bc]

  // mres = my result
  vector<string> mres;

  // now we add the "-" and "a" to the rres to get the <abc> from <bc>
  for (string s : rres) {
    mres.push_back("-" + s);
  }

  for (string s : rres) {
    mres.push_back(ch + s);
  }

  return mres;
}

// Expectation = gss("abc") || Faith = gss("bc")
// faith ----> expectation
// gss("abc") = 'a' + gss(bc)
//                  +
//              '-' + gss(bc)
//
//
// we can call the gss(bc) one time and use it with both "-" and "a"
vector<string> gss2(string str) {
  if (str.size() == 0) {
    // when no char left in the str, we return the empty string vector
    // so "-" or "a", can be added to this vector containing the empty vector
    return {""};
  }

  char ch = str[0];
  string ros = str.substr(1);

  // first recursive call (exclude character)
  vector<string> excl = gss2(ros);
  // second recursive call (include character)
  vector<string> incl = gss2(ros);

  vector<string> result;

  // add '-' + subsequences
  for (string s : excl) {
    result.push_back("-" + s);
  }

  // add ch + subsequences
  for (string s : incl) {
    result.push_back(ch + s);
  }

  return result;
}

int main() {

  cout << "get subseuqence" << endl << endl;

  // REVISION
  // string str = "hello";
  // cout << str.substr(1, 3) << endl;
  // // from 1 index to last
  // cout << str.substr(1) << endl;
  // cout << str.at(0) << endl;

  // vector<int> arr;
  // arr.push_back(10);
  // arr.push_back(20);
  // arr.push_back(30);
  // cout << "[ ";
  // for (auto &num : arr) {
  //   cout << num << " ";
  // }
  // cout << "] -> " << arr.size() << endl;

  cout << "[ ";
  vector<string> arr = gss("abc");
  for (auto &s : arr) {
    cout << s << ", ";
  }

  cout << "] -> " << arr.size() << endl;
  return 0;
}
```
</details>

<details>
<summary>📄 stair-path-base-helper.cpp</summary>


<h3 align="center"> ⚡ stair-path-base-helper.cpp </h3>

```cpp
#include "iostream"
#include "vector"

using namespace std;

int main() {

  vector<string> arr1 = {""};
  vector<string> arr2 = {};

  cout << "Vector (arr1) Size: " << arr1.size() << endl;
  cout << "Vector (arr2) Size: " << arr2.size() << endl;

  for (auto &s : arr1) {
    cout << "from arr1" << endl;
    cout << s << endl;
  }
  for (auto &s : arr2) {
    cout << "from arr2" << endl;
    cout << s << endl;
  }
}
```
</details>

## Day 4

<details>
<summary>📄 get-maze-path-with-jump.cpp</summary>


<h3 align="center"> ⚡ get-maze-path-with-jump.cpp </h3>

```cpp
#include "iostream"
#include "vector"

using namespace std;

// sr = source row
// sc = source column
// dr = destination row
// dc = destinantion column
vector<string> getMazePathsWithJumps(int sr, int sc, int dr, int dc) {
  // base case
  if (sr == dr && sc == dc) {
    // we are at position no need to move
    return {""};
  }
  vector<string> paths;

  // HORIZONTAL PATH
  // no of horizontal moves = dc - sc
  // ms = move size
  // ms <= dc - sc, limit so that we are not out of maze
  for (int ms = 1; ms <= dc - sc; ms++) {
    // my faith, after the horizontal jump, we have our path to destination
    vector<string> hpaths = getMazePathsWithJumps(sr, sc + ms, dr, dc);
    // faith to expectation
    // sc --> sc+ms ==converted==> sc --> dc by prefixing the "h" + <ms>
    for (auto &hpath : hpaths) {
      // like h1 or h2 or h3 etc
      paths.push_back("h" + to_string(ms) + hpath);
    }
  }

  // VERTICAL PATH
  // no of vertical moves = dr - sr
  // ms = move size
  // ms <= dr - sr, limit so that we are not out of maze
  for (int ms = 1; ms <= dr - sr; ms++) {
    // my faith, after the horizontal jump, we have our path to destination
    vector<string> vpaths = getMazePathsWithJumps(sr + ms, sc, dr, dc);
    // faith to expectation
    // sr --> sr+js ==converted==> sr --> dr by prefixing the "v" + <ms>
    for (auto &vpath : vpaths) {
      // like v1 or v2 or v3 etc
      paths.push_back("v" + to_string(ms) + vpath);
    }
  }

  // DIAGONAL PATH
  // ms = move size
  // ms <= dr - sr && ms <= dc - sc  , limit so that we are not out of maze
  for (int ms = 1; ms <= dr - sr && ms <= dc - sc; ms++) {
    // my faith, after the horizontal jump, we have our path to destination
    vector<string> dpaths = getMazePathsWithJumps(sr + ms, sc + ms, dr, dc);
    // faith to expectation
    for (auto &dpath : dpaths) {
      // like d1 or d2 or d3 etc
      paths.push_back("d" + to_string(ms) + dpath);
    }
  }

  return paths;
}

int main() {

  cout << "get maze path with jump" << endl << endl;
  int m, n;
  cout << "Enter value of m & n: ";
  cin >> m >> n;

  cout << "[ ";
  vector<string> paths = getMazePathsWithJumps(1, 1, m, n);
  for (auto &s : paths) {
    cout << s << ", ";
  }
  cout << "] -> " << paths.size() << " ways available" << endl;

  return 0;
}
```
</details>

<details>
<summary>📄 get-maze-path.cpp</summary>


<h3 align="center"> ⚡ get-maze-path.cpp </h3>

```cpp
#include "iostream"
#include "vector"

using namespace std;

// sr = source row
// sc = source column
// dr = destination row
// dc = destinantion column
vector<string> getMazePaths(int sr, int sc, int dr, int dc) {
  if (sr == dr && sc == dc) {
    return {""};
  }

  vector<string> hpaths;
  vector<string> vpaths;

  // if sc < dc them we can move horizontally otherwise we are out of maze
  if (sc < dc) {
    // if we move horizontal in maze column++
    hpaths = getMazePaths(sr, sc + 1, dr, dc);
  }

  // if sr < dr them we can move vertically otherwise we are out of maze
  if (sr < dr) {
    // if we move vertical in maze row++
    vpaths = getMazePaths(sr + 1, sc, dr, dc);
  }

  // resultant path
  vector<string> paths;
  for (auto &hpath : hpaths) {
    paths.push_back("h" + hpath);
  }

  for (auto &vpath : vpaths) {
    paths.push_back("v" + vpath);
  }

  return paths;
}

int main() {

  cout << "get maze path" << endl << endl;
  int m, n;
  cout << "Enter value of m & n: ";
  cin >> m >> n;

  cout << "[ ";
  vector<string> paths = getMazePaths(1, 1, m, n);
  for (auto &s : paths) {
    cout << s << ", ";
  }
  cout << "] -> " << paths.size() << " ways available" << endl;

  return 0;
}
```
</details>

<details>
<summary>📄 print-keypad-combination.cpp</summary>


<h3 align="center"> ⚡ print-keypad-combination.cpp </h3>

```cpp
#include "iostream"
#include "vector"
using namespace std;

// making it global
vector<string> codes = {".,",  "abc",  "def", "ghi", "jkl",
                        "mno", "pqrs", "tu",  "vwx", "yx"};

int count = 0;
void printKPC(string ques, string ans) {
  if (ques.size() == 0) {
    cout << ans << endl;
    count++;
    return;
  }

  char ch = ques.at(0);

  // ros = rest of string
  string ros = ques.substr(1);

  string code_for_ch = codes[ch - '0'];
  for (size_t i = 0; i < code_for_ch.size(); i++) {
    char char_from_code = code_for_ch.at(i);
    printKPC(ros, ans + char_from_code);
    // printKPC(ros, char_from_code + ans);
  }
}

int main() {

  cout << "print keypad combination" << endl << endl;

  printKPC("678", "");
  // printKPC("67", "");
  cout << "Total no. of the subsequence: " << count << endl;
  return 0;
}
```
</details>

<details>
<summary>📄 print-maze-path.cpp</summary>


<h3 align="center"> ⚡ print-maze-path.cpp </h3>

```cpp
#include "iostream"
#include "vector"
using namespace std;

int count = 0;

// path = psf = path so far
void getMazePaths(int sr, int sc, int dr, int dc, string path) {
  // METHOD 1:
  // call smart, base case stupid
  if (sc == dc && sr == dr) {
    cout << path << endl;
    count++;
    return;
  }

  // HORIZONTAL MOVE
  if (sc < dc) {
    getMazePaths(sr, sc + 1, dr, dc, path + "h");
  }

  // VERTICAL MOVE
  if (sr < dr) {
    getMazePaths(sr + 1, sc, dr, dc, path + "v");
  }

  // METHOD 2:
  // call stupid, base case smart
  // if (sc > dc || sr > dc) {
  //   // out of bound chala gya, so return, no print
  //   return;
  // }

  // if (sc == dc && sr == dr) {
  //   cout << path << endl;
  //   count++;
  //   return;
  // }

  // // HORIZONTAL MOVE
  // getMazePaths(sr, sc + 1, dr, dc, path + "h");
  // // VERTICAL MOVE
  // getMazePaths(sr + 1, sc, dr, dc, path + "v");
}

int main() {

  cout << "print maze path" << endl << endl;

  int m, n;
  cout << "Enter value of m & n: ";
  cin >> m >> n;

  getMazePaths(1, 1, m, n, "");
  cout << "Total no. of the paths: " << count << endl;
  return 0;
}
```
</details>

<details>
<summary>📄 print-stair-path-2.cpp</summary>


<h3 align="center"> ⚡ print-stair-path-2.cpp </h3>

```cpp
#include <iostream>
using namespace std;

int count = 0;

void printStairPath(int current, int n, string path) {
    if (current == n) {
        cout << path << endl;
        count++;
        return;
    }
    if (current > n) {
        return; // crossed the destination
    }

    // jump 1 step
    printStairPath(current + 1, n, path + "1");

    // jump 2 steps
    printStairPath(current + 2, n, path + "2");

    // jump 3 steps
    printStairPath(current + 3, n, path + "3");
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    printStairPath(0, n, "");

    cout << "Total no. of paths: " << count << endl;
    return 0;
}
```
</details>

<details>
<summary>📄 print-stair-path.cpp</summary>


<h3 align="center"> ⚡ print-stair-path.cpp </h3>

```cpp
#include "iostream"
#include "vector"
using namespace std;

int count = 0;

void printStairPath(int n, string path) {
  if (n == 0) {
    cout << path << endl;
    count++;
    return;
  } else if (n < 0) {
    // we are in basement, there's no way, its fraud path
    return;
  }
  // leveled options
  // for 3 type jump, put all these option via call

  // jumps 1 stairs
  printStairPath(n - 1, path + "1");
  // jumps 2 stairs
  printStairPath(n - 2, path + "2");
  // jumps 3 stairs
  printStairPath(n - 3, path + "3");
}

int main() {

  cout << "print stair path" << endl << endl;

  int n;
  cout << "Enter the value of n: ";
  cin >> n;
  printStairPath(n, "");
  cout << "Total no. of the subsequence: " << count << endl;
  return 0;
}
```
</details>

<details>
<summary>📄 print-subsequence.cpp</summary>


<h3 align="center"> ⚡ print-subsequence.cpp </h3>

```cpp
#include "iostream"
#include "vector"

using namespace std;

// sr = source row
// sc = source column
// dr = destination row
// dc = destinantion column
int count = 0;
void printSubsequence(string ques, string ans) {
  // base case
  if (ques.size() == 0) {
    // printing here, because we print at the leaf of the euler tree
    // and que.size == 0, at the leaf, exactly at the base case
    cout << ans << endl;
    count++;
    return;
  }

  // first char
  char ch = ques.at(0);
  // ros = rest of string
  string ros = ques.substr(1);

  printSubsequence(ros, ans + ""); // if ch say NO
  printSubsequence(ros, ans + ch); // if ch say YES, include ch

  // no need to store the subsequence at we do in getSequence
}

// ================================================================================
// Example of get substring with storing the answer
// ================================================================================
vector<string> gss2(string str) {
  if (str.size() == 0) {
    // when no char left in the str, we return the empty string vector
    // so "-" or "a", can be added to this vector containing the empty vector
    return {""};
  }

  char ch = str[0];
  string ros = str.substr(1);

  // first recursive call (exclude character)
  vector<string> excl = gss2(ros);
  // second recursive call (include character)
  vector<string> incl = gss2(ros);

  vector<string> result;

  // add '-' + subsequences
  for (string s : excl) {
    result.push_back("-" + s);
  }

  // add ch + subsequences
  for (string s : incl) {
    result.push_back(ch + s);
  }

  return result;
}

// ================================================================================
// ================================================================================
int main() {

  cout << "print subsequence" << endl << endl;

  // printSubsequence("abcdefghijklmnopqrstuvwxyz", "");

  printSubsequence("abc", "");
  cout << "Total no. of the subsequence: " << count << endl;
  // we see only 7 on console, at one of them is empty string :)

  return 0;
}
```
</details>

## Day 5

<details>
<summary>📄 print-encoding.cpp</summary>


<h3 align="center"> ⚡ print-encoding.cpp </h3>

```cpp
#include "iostream"
#include "vector"
using namespace std;

int count = 0;

// =============================================================
// Approach 1
// =============================================================
// asf = answer so far
void printEncoding(string ques, string asf) {
  // SMART BASE CASE
  // DUMB CALL

  // base case
  if (ques.size() == 0) {
    cout << asf << endl;
    count++;
    return;
  } else if (ques.size() == 1) {
    char ch = ques.at(0);

    // if zero then no annswer return, else print that char
    if (ch == '0') {
      return;
    } else {
      // '3' ==> '3' - '0' = 3 ==> char to int
      // chv = char value
      int chv = ch - '0';
      // 1 -> a, 2 -> b and so on.....
      char code_from_int = (char)('a' + chv - 1);
      // here length is one, so no extra call, just print
      cout << asf + code_from_int << endl;
      count++;
      return;
    }
  }

  // DUMB CALL
  // } else if (ques.size() >= 2) {
  // for 213
  // NOTE :
  // get the first char || ex. 2
  // same as what we have done in above code for ques.size() == 1
  char ch = ques.at(0);
  string ros = ques.substr(1);

  // if this char ch is zero in this case too
  if (ch == '0') {
    return;
  } else {
    // '3' ==> '3' - '0' = 3 ==> char to int
    // chv = char value
    int chv = ch - '0';
    // 1 -> a, 2 -> b and so on.....
    char code_from_int = (char)('a' + chv - 1);
    printEncoding(ros, asf + code_from_int);
  }

  // NOTE :
  // get the second char (it is of 2 length) || ex. 21
  string ch12 = ques.substr(0, 2);
  string ros12 = ques.substr(2);

  int ch12v = stoi(ch12);

  // again there is constraint
  if (ch12v <= 26) {
    char code_from_int = (char)('a' + ch12v - 1);
    printEncoding(ros12, asf + code_from_int);
  }
  // }
}

// =============================================================
// Approach 2
// =============================================================

// asf = answer so far
void printEncoding2(string ques, string asf) {
  // DUMB BASE CASE
  // SMART CALL

  // base case
  // print ans when ques is empty
  if (ques.size() == 0) {
    cout << asf << endl;
    count++;
    return;
  }

  // edge case -
  // 1. single char = 0
  // 2. first char in 2 length = 0, ex. 03

  // one char pick
  char char1 = ques.at(0);
  string ros_1 = ques.substr(1);
  // convert above char to int
  int char1v = char1 - '0';
  char code_for_int_1 = (char)('a' + char1v - 1);
  // SMART CALL
  // avoiding for no. = 0 || edge case 1
  if (char1 != '0') {
    printEncoding2(ros_1, asf + code_for_int_1);
  }

  // two char pick
  if (ques.size() >= 2) {
    string char12 = ques.substr(0, 2);
    string ros_12 = ques.substr(2);
    // convert above str to int
    int char12v = stoi(char12);

    // SMART CALL
    // avoiding no. like 03, 00, 01 etc || edge case 2
    if (10 <= char12v && char12v <= 26) {
      char code_for_int_12 = (char)('a' + char12v - 1);
      printEncoding2(ros_12, asf + code_for_int_12);
    }
  }
}

int main() {

  cout << "print encoding" << endl << endl;

  // printEncoding("123", "");
  printEncoding2("123", "");
  cout << "Total no. of the ansers: " << count << endl;
  return 0;
}
```
</details>

<details>
<summary>📄 print-maze-path-with-jump.cpp</summary>


<h3 align="center"> ⚡ print-maze-path-with-jump.cpp </h3>

```cpp
#include "iostream"
#include "vector"
using namespace std;

int count = 0;

// psf = path so far
void printMazePathsWithJump(int sr, int sc, int dr, int dc, string psf) {
  // HEAR CALL IS SMART
  // BASE CASE IS DUMB

  // base case
  if (sr == dr && sc == dc) {
    cout << psf << endl;
    count++;
    return;
  }
  // horizonatal jump
  for (int ms = 1; ms <= dc - sc; ms++) {
    printMazePathsWithJump(sr, sc + ms, dr, dc, "h" + to_string(ms) + psf);
  }

  // vertical jump
  for (int ms = 1; ms <= dr - sr; ms++) {
    printMazePathsWithJump(sr + ms, sc, dr, dc, "v" + to_string(ms) + psf);
  }
  // diagonal jump
  for (int ms = 1; ms <= dr - sr && ms <= dc - sc; ms++) {
    printMazePathsWithJump(sr + ms, sc + ms, dr, dc, "d" + to_string(ms) + psf);
  }
}
int main() {

  cout << "print maze path with jump" << endl << endl;

  int m, n;
  cout << "Enter value of m & n: ";
  cin >> m >> n;

  printMazePathsWithJump(1, 1, m, n, "");
  cout << "Total no. of the paths: " << count << endl;
  return 0;
}
```
</details>

<details>
<summary>📄 print-permutation.cpp</summary>


<h3 align="center"> ⚡ print-permutation.cpp </h3>

```cpp
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
```
</details>

## Day 6

