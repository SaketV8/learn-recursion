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