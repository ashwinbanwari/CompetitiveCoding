#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    int ar[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        for (int j = i+2; j <= s.size(); j++) {
            for (int k = i; k < j; k++) {
                ar[s[k] - 'a']++; 
            }
            if (*max_element(ar, ar+26) > (j-i) / 2) {
                cout << i+1 << " " << j << endl;
                return 0;
            }
            if (ar[s[i]-'a'] < ((j-i) + 1)/ 2) {
                fill(ar, ar+26, 0);
                break;
            }
            fill(ar, ar+26, 0);
        }
    }
    cout << "-1 -1" << endl;
    return 0;
}