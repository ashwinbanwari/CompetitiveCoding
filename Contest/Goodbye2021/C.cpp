#include <bits/stdc++.h>

using namespace std;

void init(vector<int>& parent) {
	for (int i = 0; i < parent.size(); i++) {
		parent[i] = i;
	}
}

int find(int x, vector<int>& parent) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x], parent);
}

void uni(int x, int y, vector<int>& parent) {
	x = find(x, parent);
	y = find(y, parent);
	parent[x] = y;
}

int timeNeeded(vector<int> v, double d, vector<pair<int, int>> idx) {
	int debug = 0;
	if (d == 1) {
		debug = 1;
	}
	vector<int> parent(v.size());
	init(parent);
	for (auto& p : idx) {
		uni(p.first, p.second, parent);
	}
	vector<int> counting(v.size());
	for (int i = 0; i < v.size(); i++) {
		counting[find(i, parent)]++;
	}

	return v.size()- *max_element(counting.begin(), counting.end());
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
    	if (n==1) {
    		cout << 0 << endl;
    		continue;
    	}
    	map<double, vector<pair<int, int>>> diffs;
    	for (int i = 0; i < n; i++) {
    		for (int j = i+1; j < n; j++){
    			double dif = ((double)v[j] - v[i]) / (j-i);
    			diffs[dif].push_back({i, j});
    		}
    	}
    	int bestans = INT_MAX;
    	for (auto& p : diffs) {
    		bestans = min(bestans, timeNeeded(v, p.first, p.second));
    		// cerr << p.first << " " << bestans << endl;
    	}
    	cout << bestans << endl;
    }

	return 0;
}