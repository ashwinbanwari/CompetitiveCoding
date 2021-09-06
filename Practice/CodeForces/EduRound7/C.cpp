#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> firstNotMe(n);
    for (int i = 0; i < n; i++) {
    	cin >> v[i];
    }

    firstNotMe[0] = -1;
    for (int i = 1; i < n; i++) {
    	if (v[i] == v[i-1]) {
    		firstNotMe[i] = firstNotMe[i-1];
    	} else {
    		firstNotMe[i] = i-1;
    	}
    	// cerr << i << ": " << firstNotMe[i] << endl;
    }

    for (int i = 0; i < m; i++) {
    	int l, r, x;
    	cin >> l >> r >> x;
    	l--;
    	r;
    	if (v[r-1] != x) {
    		cout << r << endl;
    	} else if (firstNotMe[r-1] >= l) {
    		cout << firstNotMe[r-1]+1 << endl;
    	} else {
    		cout << -1 << endl;
    	}

    }

	return 0;
}