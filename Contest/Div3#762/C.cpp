#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
    	string a, s;
    	cin >> a >> s;
    	string b;
    	int ptr = s.size()-1;
    	bool sol = true;
    	for (int i = a.size()-1; i >= 0; i--) {
    		if (ptr == -1) {
    			sol = false;
    			break;
    		}
    		string comp = string(1, s[ptr--]);
    		if (a[i] > comp[0]) {
    			if (ptr==-1) {
    				sol = false;
    				break;
    			}
    			comp.insert(0, 1, s[ptr--]);
    		}
    		int res = stoi(comp) - (a[i]-'0');
    		if (res > 9 || res < 0) {
    			sol = false;
    		}
    		b = to_string(res) + b;
    		// cerr << b << endl;
    	}
    	if (sol) {
    		while (ptr != -1) {
    			b.insert(0, 1, s[ptr--]);
    		}
    		cout << stoll(b) << endl;
    	} else {
    		cout << -1 << endl;
    	}
    }

	return 0;
}