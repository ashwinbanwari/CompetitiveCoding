#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    map<pair<int, int>, int> numRatio;
    int free = 0;
    for (int i = 0; i < n; i++) {
    	if (a[i] == 0 && b[i] == 0) {
    		free++;
    	} else if (a[i] == 0 && b[i] != 0) {
    		// do nothing
    	} else if (a[i] != 0 && b[i] == 0) {
    		numRatio[{0,0}]++;
    	} else {
    		int div = gcd(b[i], a[i]);
    		b[i] /= div;
    		a[i] /= div;
    		if (a[i] < 0) {
    			a[i] = -a[i];
    			b[i] = -b[i];
    		}
    		numRatio[{b[i], a[i]}]++;
    	}
    }
    int best = 0;
    for (auto& p : numRatio) {
    	// cerr << p.first.first << "," << p.first.second << ": " << p.second << endl;
    	best = max(best, p.second);
    }
    cout << best + free << endl;

	return 0;
}