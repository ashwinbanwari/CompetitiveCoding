#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;

    int ar[26] = {0};
    for (char& c : s) {
        ar[c-'a']++;
    }
    for (int& i : ar) {
        if (i % 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}