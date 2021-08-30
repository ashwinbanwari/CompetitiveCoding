#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a==b) {
            if (a==0) {
                cout << 0 << endl;
            } else if (a > 0 || b > 0) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
            
        } else if (abs(a-b) % 2) {
            cout << -1 << endl;
        } else {
            cout << 2 << endl;
        }
    }

    return 0;
}