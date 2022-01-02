#include <bits/stdc++.h>

using namespace std;

int diffs(vector<char>& a, vector<char>& b) {
	int count = 0;
	for (int i = 0; i < a.size(); i++) {
		count += a[i] != b[i];
	}
	return count;
}

int num1s(vector<char>& x) {
	return count(x.begin(), x.end(), '1');
}

int num1sOff(vector<char>& a, vector<char>& b) {
	int ct = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '1' && b[i] != '1') {
			ct++;
		}
	}
	return ct;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	vector<char> curr(n), end(n);
    	for (int i = 0; i < n; i++) {
    		cin >> curr[i];
    	}
    	for (int i = 0; i < n; i++) {
    		cin >> end[i];
    	}
    	int diff = diffs(curr, end);
    	int a1s = num1s(curr);
    	int b1s = num1s(end);
    	// cerr << a1s << " " << b1s << endl;
    	if (a1s != b1s && a1s != n+1-b1s) {
    		cout << -1 << endl;
    		continue;
    	}
    	int ans = INT_MAX;
    	if (a1s != b1s || a1s == n+1-a1s) {
    		vector<char> newCurr = curr;
    		for (int i = 0; i < n; i++) {
    			newCurr[i] = (curr[i] == '1') ? '0' : '1';
    		}
    		for (int i = 0; i < n; i++) {
    			if (end[i] == '1' && newCurr[i] == '0') {
    				newCurr[i] = '1';
    				break;
    			}
    		}
    		ans = 1 + 2 * num1sOff(newCurr, end);
    	}
    	if (a1s == b1s) {
    		ans = min(ans, 2 * num1sOff(curr, end));
    	}
    	cout << ans << endl;
    }

	return 0;
}