#include <bits/stdc++.h>

using namespace std;

long long mod = 1000000007;

vector<int> solve(string s, bool left) {
	vector<int> ans(s.size());
	for (int i = 1; i < s.size(); i++) {
		if (left && s[i] == 'O') {
			left = false;
			ans[i] = ans[i-1]+1;
		} else if (!left && s[i] == 'X') {
			left = true;
			ans[i] = ans[i-1]+1;
		} else {
			ans[i] = ans[i-1];
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
    	int n;
    	string s;
    	cin >> n >> s;
    	int firstX = s.find('X');
    	int firstO = s.find('O');
    	firstX = (firstX == -1) ? INT_MAX : firstX;
    	firstO = (firstO == -1) ? INT_MAX : firstO;
    	vector<int> dp;
	    if (firstX < firstO) {
	    	dp = solve(s, true);
	    } else {
	    	dp = solve(s, false);
	    }

	    vector<int> lastX(n);
	    vector<int> lastO(n);
	    lastX[0] = (s[0] == 'X') ? 0 : -1;
	    lastO[0] = (s[0] == 'O') ? 0 : -1;
	    for (int i = 1; i < n; i++) {
	    	lastX[i] = (s[i] == 'X') ? i : lastX[i-1];
	    	lastO[i] = (s[i] == 'O') ? i : lastO[i-1];
	    }


	    vector<long long> res(n);
	    res[0] = 0;

	    for (int i = 1; i < n; i++) {
	    	if (dp[i] == dp[i-1]) {
	    		res[i] = res[i-1];
	    	} else {
	    		if (s[i] == 'O') {
	    			res[i] = res[i-1] + lastX[i]+1;
	    		} else {
	    			res[i] = res[i-1] + lastO[i]+1;
	    		}
	    	}
	    	// cerr << i << ": " << res[i] << endl;
	    }
	    long long ans = 0;
	    for (int i = 0; i < res.size(); i++) {
	    	ans += res[i];
	    	ans %= mod;
	    }
	    cout << "Case #" << i << ": " << ans << endl;
    }

	return 0;
}