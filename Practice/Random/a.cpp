#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    unordered_set<string> strs;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        set<char> obj(s.begin(), s.end());
        string ob(obj.begin(), obj.end());
        strs.insert(ob);
    }
    cout << strs.size() << endl;

    return 0;
}