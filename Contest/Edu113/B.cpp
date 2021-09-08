#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	string s;
    	cin >> s;
    	vector<int> twos;
    	for (int i = 1; i <=n; i++) {
    		if (s[i-1] == '2') {
    			twos.push_back(i);
    		}
    	}
    	int numTwos = twos.size();
    	vector<string> results(n, string(n, '='));
    	for (int i = 0; i < n; i++) {
    		results[i][i] = 'X';
    	}
    	if (twos.size() == 1 || twos.size() == 2) {
    		cout << "NO" << endl;
    		continue;
    	} else {
    		cout << "YES" << endl;
    	}
    	if (!twos.empty()) {
    		int currIdx = 0;
    		for (int i = 1; i <= n; i++) {
    			int numToKill = -1;
    			if (i==twos.front()) {
    				numToKill = twos.back();
    			} else if (currIdx != twos.size() && i == twos[currIdx]) {
    				numToKill = twos[currIdx-1];
    			}
    			if (numToKill >= 0) {
    				results[i-1][numToKill-1] = '+';
    				results[numToKill-1][i-1] = '-';
    				currIdx++;
    			}
    		}
    	}
    	for (int i = 0; i < n; i++) {
    		cout << results[i] << endl;
    	}
		
    }

	return 0;
}