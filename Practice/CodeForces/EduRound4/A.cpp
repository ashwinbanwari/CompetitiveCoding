#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, p, q;
	cin >> n >> p >> q;
    string s;
    cin >> s;
    vector<bool> dp(n+1);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
    	if (i-p >= 0 && dp[i-p]) {
    		dp[i] = true;
    	} else if (i-q >= 0 && dp[i-q]) {
    		dp[i] = true;
    	}
    }

    if (!dp[n]) {
    	cout << -1 << endl;
    	return 0;
    }
    vector<int> ans; // build backwards
    int curr = n;
    while (curr != 0) {
    	int maxi = max(p,q);
    	int mini = min(p,q);
    	if (curr-maxi >= 0 && dp[curr-maxi]) {
    		ans.push_back(maxi);
            curr -= maxi;
    	} else {
    		ans.push_back(mini);
            curr -= mini;
    	}
    }
    cout << ans.size() << endl;
    for (int i = ans.size()-1; i >= 0; i--) {
    	cout << s.substr(curr, ans[i]) << endl;
    	curr += ans[i];
    }

	return 0;
}