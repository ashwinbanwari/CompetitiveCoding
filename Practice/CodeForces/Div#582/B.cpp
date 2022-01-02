#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	vector<int> v(n);
    	for (int i = 0; i < n; i++) {
    		cin >> v[i];
    	}
    	int minSoFar = INT_MAX;
    	int count = 0;
    	for (int i = n-1; i >= 0; i--) {
    		if (v[i] <= minSoFar) {
    			minSoFar = v[i];
    		} else {
    			count++;
    		}
    	}
    	cout << count << endl;
    }

	return 0;
}