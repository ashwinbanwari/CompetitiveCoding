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
    	string res;
    	bool hadYounger = false;
    	res.push_back(s[0]);
    	int i;
    	for (i = 1; i < n; i++) {
    		if (s[i] < res[i-1]) {
    			res.push_back(s[i]);
    			hadYounger = true;
    		} else if (s[i] == res[i-1]) {
    			if (hadYounger) {
    				res.push_back(s[i]);
    			} else {
    				break;
    			}
    		} else {
    			break;
    		}
    	}
        string b(res);
        reverse(b.begin(), b.end());
        res += b;
        cout << res << endl;
    }

	return 0;
}