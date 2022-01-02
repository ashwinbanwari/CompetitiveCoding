#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    
    int T;
    cin >> T;
    while (T--) {
    	string s;
    	cin >> s;
    	if (s.size() % 2 == 1) {
    		cout << "NO" << endl;
    	    continue;
    	}
    	if (s.substr(0, s.size()/2) == s.substr(s.size()/2)) {
    		cout << "YES"<< endl;
    	} else {
    		cout << "NO" << endl;
    	}
    }

	return 0;
}