#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
    	cin >> v[i];
    }
    vector<vector<int>> numCanBeHere(200001);
    // O(nlog^2n)
    for (int i = 0; i < n; i++) {
    	int curr = v[i];
    	int dist = 0;
    	while (true) {
    		numCanBeHere[curr].push_back(dist);
    		if (curr == 0) break;
    		curr /= 2;
    		dist++;
    	}
    }

    long long bestAns = INT_MAX;
    for (auto& dists : numCanBeHere) {
    	// cerr << p.first << endl;
    	if (dists.size() < k) {
    		continue;
    	}
        sort(dists.begin(), dists.end());
    	int seen = 1;
    	auto it = dists.begin();
    	long long currAns = *it;
    	// cerr << *it << " ";
    	while (seen < k) {
    		it++;
    		// cerr << *it << " ";
    		currAns += *it;
    		seen++;
    	}
    	// cerr << endl;
    	bestAns = min(bestAns, currAns);
    }
    cout << bestAns <<  endl;

	return 0;
}