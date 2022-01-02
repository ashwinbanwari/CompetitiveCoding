#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
    	string s;
    	cin >> s;
    	int Bs = 0;
    	for (char c : s) {
    		if (c == 'B') {
    			Bs++;
    		}
    	}
    	if (s.size() % 2 == 0 && Bs == s.size() / 2) {
    		cout << "YES" << endl;
    	} else {
    		cout << "NO" << endl;
    	}
    }

	return 0;
}