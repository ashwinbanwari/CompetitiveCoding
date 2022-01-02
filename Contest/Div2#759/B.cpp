#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
    	int n;
    	cin >> n;
    	vector<int> v(n);
    	for (int i = 0; i < n; i++) {
    		cin >> v[i];
    	}
    	vector<int> sd(v.begin(), v.end());
    	sort(sd.begin(), sd.end());
    	sd.resize(distance(sd.begin(), unique(sd.begin(), sd.end())));
    	unordered_map<int, int> numLarger;
    	for (int i = 0; i < sd.size(); i++) {
    		numLarger[sd[i]] = sd.size()-i-1;
    	}
    	int best = INT_MAX;;
    	int fromEnd = 0;
    	int largestPast = INT_MIN;
    	for (int i = n-1; i>= 0; i--) {
    		// cerr << fromEnd+numLarger[v[i]] << endl;
    		best = min(best, fromEnd+numLarger[v[i]]);
    		if (v[i] > largestPast) {
    			fromEnd++;
    			largestPast = v[i];
    		}
    	}
    	cout << best << endl;
    }

	return 0;
}