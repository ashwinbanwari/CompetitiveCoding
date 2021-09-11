#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();
    vector<bool> isArbitrary(n);
    for (int i = 1; i < n; i++) {
    	if (s[i] == s[i-1] && !isArbitrary[i-1]) {
    		isArbitrary[i] = true;
    	}
    }
    for (int i = 1; i < n; i++) {
    	if (isArbitrary[i]) {
    		if (s[i-1] !='a' && (i==n || s[i+1]!='a')) {
    			s[i] = 'a';
    		} else if (s[i-1] !='b' && (i==n || s[i+1]!='b')) {
    			s[i] = 'b';
    		} else {
    			s[i] = 'c';
    		}
    	}
    }
    cout << s << endl;

	return 0;
}