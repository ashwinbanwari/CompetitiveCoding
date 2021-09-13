#include <bits/stdc++.h>

using namespace std;

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
    	string s;
    	cin >> n >> s;
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
	    cout << "Case #" << i << ": " << ans << endl;
    }

	return 0;
}