#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> strength(n);
    for (int i = 0; i < n; i++) {
    	cin >> strength[i];
    }
    string assignments;
    cin >> assignments;
    long long maxBalance = 0;
    long long currBalance = 0;
    for (int i = 0; i < n; i++) {
    	if (assignments[i] == 'A') {
    		currBalance += strength[i];
    		maxBalance = max(maxBalance, currBalance);
    	} else {
    		currBalance -= strength[i];
    	}
    }
    currBalance = 0;
    for (int i = n-1; i >= 0; i--) {
    	if (assignments[i] == 'A') {
    		currBalance += strength[i];
    		maxBalance = max(maxBalance, currBalance);
    	} else {
    		currBalance -= strength[i];
    	}
    }

    long long startStrength = 0;
    for (int i = 0; i < n; i++) {
    	if (assignments[i] == 'B') {
    		startStrength += strength[i];
    	}
    }
    // cerr << startStrength << " " << maxBalance << endl;
    cout << startStrength + maxBalance << endl;

	return 0;
}