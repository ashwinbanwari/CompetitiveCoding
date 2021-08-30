#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v {a, b, c};
    sort(v.begin(), v.end());
    if (v == vector<int>{5, 5, 7}) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}