#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n, m;
    	cin >> n >> m;
    	vector<long long> v(n);
    	for (int i = 0; i < n; i++) {
    		cin >> v[i];
    	}
    	vector<long long> peaks;
    	vector<int> peakIdx;
    	long long sum = accumulate(v.begin(), v.end(), 0LL);
    	long long curr = 0;
    	long long largest = INT_MIN;
    	for (int i = 0; i < n; i++) {
    		curr += v[i];
    		if (curr > largest) {
    			peaks.push_back(curr);
    			peakIdx.push_back(i);
    			largest = curr;
    		}
    	}
    	for (int i = 0; i < m; i++) {
    		int query;
    		cin >> query;
    		long long a;
			long long pickHighest = query - peaks.back();
			if (pickHighest <= 0 || sum <= 0) {
				a = 0;
			} else {
				a = (pickHighest+sum-1) / sum;
			}
			long long left = query - a * sum;
			if (left == 0) {
				cout << a * peaks.size() - 1 << endl;
				continue;
			}
			auto it = lower_bound(peaks.begin(), peaks.end(), left);
			if (it == peaks.end()) {
				cout << -1 << endl;
			} else {
				long long increasedDist = peakIdx[distance(peaks.begin(), it)];
				cout << a*v.size() + increasedDist << endl;
			}
    	}
    }

	return 0;
}