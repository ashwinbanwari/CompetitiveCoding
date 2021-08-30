#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string input, ans;
    cin >> input;
    for (char& c : input) {
        switch(c) {
            case 'B':
                if (ans.size()) {
                    ans.pop_back();
                }
                break;
            default:
                ans += c;
        }
    }
    cout << ans << endl;

    return 0;
}