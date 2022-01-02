#include <bits/stdc++.h>

using namespace std;

void finishN(int n) {
	for (int i = 0; i < n; i++) {
		cout << "-1 ";
	}
	cout << endl;
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
    	vector<int> count(n+1);
    	set<int> hasExtras;
    	for (int i : v) {
    		count[i]++;
    	}
    	for (int i = 0; i <= n; i++) {
    		if (count[i] > 1) {
    			hasExtras.insert(i);
    		}
    	}
    	long long cost = 0;
    	cout << count[0] << " ";
    	int i;
    	int last = n;
    	vector<long long> costs;
    	costs.push_back(0);
    	for (i = 1; i <= n; i++) {
    		if (count[i-1] == 0) {
    			// fill gap
    			auto it = hasExtras.upper_bound(i-1);
    			if (it == hasExtras.begin()) {
    				// can't fill gap, over
    				last = i;
    				break;
    			}
    			it--;
    			int savior = *it;
    			count[savior]--;
    			cost += (i-1) - (savior);
    			if (count[savior] == 1) {
    				hasExtras.erase(it);
    			}
    			count[i-1] = 1;
    		}
    		costs.push_back(count[i]+cost);
    	}
    	for (int i = 1; i < costs.size(); i++) {
    		cout << costs[i] << " ";
    	}
    	finishN(n+1-i);

    	// 0: 0s to 1s (count[i])
    	// 1: keep 0s, move 1s to 2s (count[i])
    	// 2: keep 0s, fill in possibly 1 1 from 0, move 2s to 3s (count[i]+ 1?)
    	// 3: keep 0s,fill in possibly 1 1 from 0, possibly
    }

	return 0;
}