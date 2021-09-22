#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	for (int i = 0; i < n; i++) {
    		string res;
    		for (int j = 0; j <= i; j++) {
    			res.push_back('(');
    		}
    		for (int j = i+1; j <= (i+1) * 2 - 1; j++) {
    			res.push_back(')');
    		}
    		for (int j = (i+1)*2; j < 2*n; j+=2) {
    			res.push_back('(');
    			res.push_back(')');
    		}
    		cout << res << endl;
    	}
    }

	return 0;
}