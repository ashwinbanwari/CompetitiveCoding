#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, L;
    cin >> N >> L;
    vector<string> v(N);
    v[100] = "5";
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    string res;
    for (string s : v) {
        res += s;
    }
    cout << res << endl;

    return 0;
}