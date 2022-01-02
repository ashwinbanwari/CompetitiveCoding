#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
    	int n, k;
    	cin >> n >> k;
    	vector<int> v(n);
    	for (int i = 0; i < n; i++) {
    		cin >> v[i];
    	}
    	sort(v.begin(), v.end());
    	int score = accumulate(v.begin(), v.end(), 0);
    	for (int i = n-1; i >= n-k; i--) {
    		score -= (v[i]+v[i-k]);
    		score += (v[i-k]/v[i]);
    	}
    	cout << score << endl;
    }

	return 0;
}