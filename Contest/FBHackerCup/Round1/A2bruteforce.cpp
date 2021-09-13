#include <bits/stdc++.h>

using namespace std;

long long mod = 1000000007;

int solve(string s, bool left) {
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (left && s[i] == 'O') {
			left = false;
			ans++;
		} else if (!left && s[i] == 'X') {
			left = true;
			ans++;
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
    	string str;
    	cin >> n >> str;
    	long long res = 0;
    	for (int i = 0; i < n; i++) {
    		for (int j = i+1; j <= n; j++) {
    			string s = str.substr(i, j-i);
	    		int firstX = s.find('X');
		    	int firstO = s.find('O');
		    	firstX = (firstX == -1) ? INT_MAX : firstX;
		    	firstO = (firstO == -1) ? INT_MAX : firstO;
		    	// cerr << "firstX: " << firstX << " firstO: " << firstO << endl;
		    	int ans;
			    if (firstX < firstO) {
			    	ans = solve(s, true);
			    } else {
			    	ans = solve(s, false);
			    }
			    // cerr << "(" << i << "," << j << "): "  << ans << endl;
			    res += ans;
			    res %= mod;
			}
    	}
	    	
	    cout << "Case #" << i << ": " << res << endl;
    }

	return 0;
}