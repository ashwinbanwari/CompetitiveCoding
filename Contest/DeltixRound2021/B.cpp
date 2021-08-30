#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& v, vector<int>& arr1, vector<int>& arr2) {
    int cost = 0;
    for (int i = 0; i < v.size(); i++) {
        if (i % 2) {
            cost += max(0, arr2[i/2] - i);
        } else {
            cost += max(0, arr1[i/2] - i);
        }
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> evens;
        vector<int> odds;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] % 2) {
                odds.push_back(i);
            } else {
                evens.push_back(i);
            }
        }
        int diff = evens.size()-odds.size();
        if (abs(diff) > 1) {
            cout << -1 << endl;
        } else if (diff == 0) {
            int ans1 = solve(v, evens, odds);
            int ans2 = solve(v, odds, evens);
            cout << min(ans1, ans2) << endl;
        } else {
            if (diff == 1) {
                cout << solve(v, evens, odds) << endl;
            } else {
                cout << solve(v, odds, evens) << endl;
            }
        }
    }

    return 0;
}