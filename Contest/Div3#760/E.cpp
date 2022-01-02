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
    	int sum = accumulate(v.begin(), v.end(), 0);
    	if (v.size() % 2) {
    		sum -= v[n/2];
    	}
    }

	return 0;
}