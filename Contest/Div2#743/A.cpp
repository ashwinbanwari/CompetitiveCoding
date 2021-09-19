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
	    int sum = 0;
	    int numNotZero = 0;
	    for (int i = 0; i < s.size(); i++) {
	    	sum += (int) s[i] - '0';
	    	if (s[i] != '0') numNotZero++;
	    }

	    if (s.back() != '0') {
	    	cout << sum + numNotZero - 1 << endl;
	    } else {
	    	cout << sum + numNotZero << endl;
	    }
	}
    

	return 0;
}