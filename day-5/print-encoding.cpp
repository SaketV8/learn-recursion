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