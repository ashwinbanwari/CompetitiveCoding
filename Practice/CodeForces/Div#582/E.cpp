#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    set<string> possibles = {"abc", "acb", "bac", "bca", "cab", "cba"};
    string res = "nope";
    for (string s : possibles) {
    	string x = s.substr(0,2);
    	string y = s.substr(1,2);
    	string z = string(1, s[2]) + string(1, s[0]);
    	if (x != a && x != b && y != a && y != b && z != a && z != b) {
    		res = s;
    		break;
    	}
    }
    cout << "YES" << endl;
    if (res == "nope") {
    	set<int> freeLetters = {'a', 'b', 'c'};
    	// Case 1: same letters used in both
    	if (a[0] == b[1]) {
    		freeLetters.erase(a[0]);
    		freeLetters.erase(a[1]);
    		cout << string(n, a[0]) << string(n, *freeLetters.begin()) <<string(n, a[1]) << endl;
    	}

    	// Case 2: first letters same
    	else if (a[0] == b[0]) {
    		freeLetters.erase(a[0]);
    		cout << string(n, *freeLetters.begin()) << string(n, *next(freeLetters.begin())) << string(n, a[0]) << endl;
    	}

    	// Case 3: last letters same
    	else {
    		freeLetters.erase(a[1]);
    		cout << string(n, a[1]) << string(n, *freeLetters.begin()) << string(n, *next(freeLetters.begin())) << endl;
    	}
    } else {
    	for (int i = 0; i < n; i++) {
    		cout << res;
    	}
    	cout << endl;
    }
	return 0;
}