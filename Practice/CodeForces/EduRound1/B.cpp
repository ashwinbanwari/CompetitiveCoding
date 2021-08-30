#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    int t;
    cin >> s >> t;
    while (t--) {
        int l, r, k;
        cin >> l >> r >> k;
        l -= 1;
        k %= (r-l);
        string repValues(r-l, 'a');
        for (int i = l; i < r; i++) {
            int idxToSteal = i-k;
            if (idxToSteal < l) {
                idxToSteal += r-l;
            }
            repValues[i-l] = s[idxToSteal];
        }
        for (int i = l; i < r; i++) {
            s[i] = repValues[i-l];
        }
    }
    cout << s << endl;

    return 0;
}