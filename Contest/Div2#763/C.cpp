#include <bits/stdc++.h>

using namespace std;

bool ok(int x, vector<int>& v) {
	if (x < 0) return false;
	int n = v.size();
	vector<int> addOns(n);
	for (int i = n-1; i >= 2; i--) {
		int canGive = min(v[i], max(0, v[i]+addOns[i]-x));
		int d3 = ((canGive) / 3) * 3;
		int d2 = ((canGive) / 3) * 2;
		int d1 = d2 / 2;
		addOns[i-1] += d1;
		addOns[i-2] += d2;
		addOns[i] -= d3;
	}
	

	for (int i = 0; i < n; i++) {
		// cerr << v[i] + addOns[i] << endl;
		if (v[i] + addOns[i] < x) {
			return true;
		}
	}

	return false;
}

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
    	int r = *max_element(v.begin(), v.end());
    	long long x = -1;
    	for (long long b = r; b >= 1; b /= 2) {
    		while (!ok(x+b, v)) {
    			x += b;
    		}
    	}
    	cout << x << endl;
    }

	return 0;
}