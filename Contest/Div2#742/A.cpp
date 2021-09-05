#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, t;
    cin >> t;
    while (t--) {
    	cin >> n;
    	string s;
    	cin >> s;
    	bool leftLast = false;
    	string res(s.size(), 'a');
    	for (int i = 0; i < s.size(); i++) {
    		if (s[i] == 'U') {
    			res[i] = 'D';
    		} else if (s[i] == 'D') {
    			res[i] = 'U'; 
    		}
    		else if (leftLast) {
    			res[i] = 'R';
    			leftLast = false;
    		} else {
    			res[i] = 'L';
    			leftLast = true;
    		}
    	}
    	cout << res << endl;
    }

	return 0;
}