#include <bits/stdc++.h>

using namespace std;

/*
there is a valid sequence if following observations are met:
balance never == k at any point in array
- there are enough '?' such that balance += '?'s >= k
  - + if last +- was a +, - if last +- was a -
- when changing the end ?s to +-, we never go over balance


*/


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> dp(n+1, vector<int>(2*k+1)); // dp[i][j] stores bool that can reach balance (j+k) at index b (1-idxed)
    dp[0][k] = true;
    for (int i = 0; i < n; i++) {
    	switch(s[i]) {
    		case 'W':
    			for (int j = 1; j < 2 * k; j++) {
    				if (dp[i][j]) {
    					dp[i+1][j+1] = true;
    				}
    			}
    			break;
    		case 'L':
    			for (int j = 1; j < 2 * k; j++) {
    				if (dp[i][j]) {
    					dp[i+1][j-1] = true;
    				}
    			}
    			break;
    		case '?':
    			for (int j = 1; j < 2 * k; j++) {
    				if (dp[i][j]) {
    					dp[i+1][j-1] = true;
    					dp[i+1][j] = true;
    					dp[i+1][j+1] = true;
    				}
    			}
    			break;
    		default:
    			for (int j = 1; j < 2 * k; j++) {
    				if (dp[i][j]) {
    					dp[i+1][j] = true;
    				}
    			}
    			break;
    	}
    }

    stack<char> sequence;
    int currBalance;
    if (dp[n][2*k]) {
    	currBalance = 2*k;
    } else if (dp[n][0]) {
    	currBalance = 0;
    } else {
    	cout << "NO" << endl;
    	return 0;
    }
	for (int i = n-1; i >= 0; i--) {
		switch(s[i]) {
			case '?':
				for (int j = max(currBalance - 1, 1); j <= min(currBalance + 1, 2 * k - 1); j++) {
					if (dp[i][j]) {
						if (j - currBalance == -1) {
							sequence.push('W');
							currBalance--;
						} else if (j - currBalance == 0) {
							sequence.push('D');
						} else {
							sequence.push('L');
							currBalance++;
						}
						break;
					}
				}
			    break;
			default:
			    sequence.push(s[i]);
			    if (s[i] == 'W') {
					currBalance--;
				} else if (s[i] == 'L') {
					currBalance++;
				}
				break;
		}
	}
	while (!sequence.empty()) {
		cout << sequence.top();
		sequence.pop();
	}
	cout  << endl;


	return 0;
}