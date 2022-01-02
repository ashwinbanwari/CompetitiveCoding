#include <bits/stdc++.h>

using namespace std;

long long mod = 998244353;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	vector<int> v(n);
    	for (int i = 0; i < n; i++) {
    		cin >> v[i];
    	}
    	vector<vector<long long>> dp(n+4, vector<long long>(2));
    	dp[0][0] = 1; // [i][0] good seq, [i][1] dead seq
    	for (int i = 0; i < n; i++) {
    		int curr = v[i];
    		if (curr == 0) {
    			dp[1][0] *= 2;
    			dp[1][0]++;
    			dp[1][0] %= mod;
    			dp[3][1] *= 2;
    			dp[3][1] %= mod;
    			continue;
    		}
    		dp[curr+1][0] *= 2;
    		dp[curr+1][0] += dp[curr][0];
    		dp[curr+1][0] %= mod;

    		dp[curr+1][1] += dp[curr-1][0] + dp[curr+1][1];
    		dp[curr+1][1] %= mod;

    		dp[curr+3][1] *= 2;
    		dp[curr+3][1] %= mod;
    	}
    	long long ans = -1;
    	for (int i = 0;  i < dp.size(); i++) {
    		ans += dp[i][0] + dp[i][1];
    	}
    	cout << (ans+mod)%mod << endl;
    }

	return 0;
}