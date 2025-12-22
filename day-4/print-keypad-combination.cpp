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