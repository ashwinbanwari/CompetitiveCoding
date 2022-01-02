#include <bits/stdc++.h>

using namespace std;

bool leading0(string s) {
	return s.size() > 1 && s.front() == '0';
}

void replaceX(string& s, char x) {
	for (char& c : s) {
		if (c == 'X') {
			c = x;
		}
	}
}

int waysFirstTwo(string& s) {
	int n = s.size();
	if (s[n-1] == '0') {
		// last is 0
		if (s[n-2] == '0' || s[n-2] == '5') {
			return 1;
		} else if (s[n-2] == '_') {
			// 50 or 00
			return (s.size() == 2) ? 1 : 2;
		} else if (s[n-2] == 'X') {
			// 50 or 00
			replaceX(s, 5);
			return (s[0] == 5) ? 1 : 2;
		} else {
			return 0;
		}
	} else if (s[n-1] == '5') {
		// last is 5
		if (s[n-2] == '2' || s[n-2] == '7') {
			return 1;
		} else if (s[n-2] == '_') {
			// 25 r 75
			return 2;
		} else if (s[n-2] == 'X') {
			// 50 or 00
			replaceX(s, '2');
			return 2;
		} else {
			return 0;
		}
	} else if (s[n-1] == '_') {
		if (s[n-2] == '7' || s[n-2] == '2' || s[n-2] == '5') {
			return 1;
		} else if (s[n-2] == '0' && s.size() != 2) {
			return 1;
		} else if (s[n-2] == '_') {
			return (s.size() == 2) ? 3 : 4;
		} else if (s[n-2] == 'X') {
			replaceX(s, 5);
			return (s[0] == 5) ? 3 : 4;
		} else {
			return 0;
		}
	} else if (s[n-1] == 'X') {
		if (s[n-2] == '7' || s[n-2] == '2') {
			replaceX(s, 5);
			return 1;
		} else if ((s[n-2] == '0' || s[n-2] == '5') && s[0] != 'X') {
			replaceX(s, 5);
			return 1;
		} else if (s[n-2] == '_') {
			if (s[0] == 'X') {
				replaceX(s, 5);
				return 2;
			} else if (s.size() == 2) {
				replaceX(s, 5);
				return 3;
			}
			replaceX(s, 5);
			return 4;
		} else if (s[n-2] == 'X') {
			replaceX(s, 5);
			return (s[0] == 5) ? 0 : 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;

    if (s.size() == 1) {
    	cout <<  ((s[0] == '0' || s[0] == '_' || s[0] == 'X') ? 1 : 0) << endl;
    	return 0;
    }
    if (s[0] == '0') {
    	cout <<  0 << endl;
    	return 0;
    }
    int xMultiplier = (s[0] == 'X') ? 9 : 10;
    int ways = waysFirstTwo(s);
    for (int i = s.size() - 3; i >= 1; i--) {
    	if (s[i] == '_') {
    		ways *= 10;
    	} else if (s[i] == 'X') {
    		cerr << "hmm" << endl;
    		ways *= xMultiplier;
    		replaceX(s, '2');
    	}
    }
    if ((s[0] == '_' || s[0] == 'X') && s.size() != 2) {
    	ways *= 9;
    }
    cout << ways << endl;


	return 0;
}