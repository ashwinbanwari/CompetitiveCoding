// Copyright @2020 Ashwin Banwari
// Ashwin Kishin Banwari
// ash1152@cs.washington.edu

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        if (n <= 2) {
            cout << 1 << endl;
            continue;
        }
        cout << (n - 2 + x - 1) / x + 1 << endl;
    }
    return 0;
}
