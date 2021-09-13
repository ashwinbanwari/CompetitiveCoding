#include <bits/stdc++.h>

using namespace std;

long long mod = 1000000007;

vector<bool> solve(string s, bool left) {
	vector<bool> ans(s.size());
	ans[0] = left;
	for (int i = 1; i < s.size(); i++) {
		if (left && s[i] == 'O') {
			left = false;
			ans[i] = false;
		} else if (!left && s[i] == 'X') {
			left = true;
			ans[i] = true;
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
    	vector<bool> facingLeft;
	    if (firstX < firstO) {
	    	facingLeft = solve(s, true);
	    } else {
	    	facingLeft = solve(s, false);
	    }

	    vector<long long> realI(n);
	    realI[0] = 0;
	    for (int i = 1; i < n; i++) {
	    	if (s[i] == '.') realI[i] = realI[i-1]*2 + 1;
	    	else realI[i] = realI[i-1]+1;
	    }

	    vector<long long> lastX(n);
	    vector<long long> lastO(n);
	    lastX[0] = (s[0] == 'X') ? 0 : -1;
	    lastO[0] = (s[0] == 'O') ? 0 : -1;
	    for (int i = 1; i < n; i++) {
	    	if (s[i] == '.') {
	    		if (lastX[i] != -1) {
	    			lastX[i] = lastX[i-1] * 2 + 1;
	    			lastX[i] %= mod;
	    		}
	    		if (lastO[i] != -1) {
	    			lastO[i] = lastO[i-1] * 2 + 1;
	    			lastO[i] %= mod;
	    		}
	    		
	    	} else {
	    		lastX[i] = (s[i] == 'X') ? realI[i] : lastX[i-1];
	    		lastO[i] = (s[i] == 'O') ? realI[i] : lastO[i-1];
	    	}
	    }


	    vector<long long> res(n);
	    res[0] = 0;
	    long long answer = 0;
	    for (int i = 1; i < n; i++) {
	    	if (s[i] == '.') {
	    		long long multiplier = 0;
	    		if (facingLeft[i] != facingLeft[0]) {
	    			if (facingLeft[i] == 'O') {
	    				multiplier = lastX[i-1]+1;
	    			} else {
	    				multiplier = lastO[i-1]+1;
	    			}
	    		}
	    		answer = answer+((realI[i]+1)*(res[i-1] + multiplier))%mod;
	    		answer %= mod;
	    		res[i] = 
	    		continue;
	    	}
	    	else if (facingLeft[i] == facingLeft[i-1]) {
	    		res[i] = res[i-1];
	    	} else {
	    		if (s[i] == 'O') {
	    			res[i] = (res[i-1] + lastX[i]+1)%mod;
	    		} else {
	    			res[i] = (res[i-1] + lastO[i]+1)%mod;
	    		}
	    	}
	    	answer += res[i];
	    	answer %= mod;
	    	// cerr << i << ": " << res[i] << endl;
	    }
	    cout << "Case #" << i << ": " << answer << endl;
    }

	return 0;
}