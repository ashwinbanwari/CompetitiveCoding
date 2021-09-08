#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	string s;
    	cin >> n >> s;
    	int balance = 0;
    	for (int i = 0; i < n; i++) {
    		balance = 0;
    		for (int j = i; j < n; j++) {
    			// cerr << balance << endl;
    			if (s[j] == 'a') balance++;
    			else balance--;
    			if (balance == 0) {
    				cout << i+1 << " " << j+1 << endl;
    				goto finis;
    			}
    		}
    	}
    	cout << -1 << " " << -1 << endl;
    	finis: {}
    }

	return 0;
}