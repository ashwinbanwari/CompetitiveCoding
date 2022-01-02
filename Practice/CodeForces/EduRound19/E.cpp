#include <bits/stdc++.h>

using namespace std;


int method1(int p, int k, vector<int>& v) {
    int n = v.size();
    if (p > n) {
        return 0;
    }
    p = p + k + v[p-1];
    return 1 + method1(p, k, v);
}

int method2(int p, int k, vector<vector<int>>& dp) {
    return dp[p][k];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
    	cin >> v[i];
    }
    int q;
    cin >> q;
    int upTo = (int) sqrt(n);
    vector<vector<int>> dp(n+1, vector<int>(upTo));
    for (int i = n; i >= 1; i--) {
        for (int k = 1; k < upTo; k++) {
            if (i + v[i-1] + k > n) {
                dp[i][k] = 1;
            } else {
                dp[i][k] = dp[i+v[i-1]+k][k] + 1;
            }
        }
    }

    while (q--) {
    	int p, k;
    	cin >> p >> k;
        if (k >= upTo) {
            cout << method1(p, k, v) << endl;
        } else {
            cout << method2(p, k, dp) << endl;
        }
    }

	return 0;
}