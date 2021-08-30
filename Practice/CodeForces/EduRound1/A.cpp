#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long res = (n * (n+1)) / 2;
        long long powers = 1;
        while (powers <= n) {
            res -= 2 * powers;
            powers *= 2;
        }
        cout << res << endl;
    }

    return 0;
}