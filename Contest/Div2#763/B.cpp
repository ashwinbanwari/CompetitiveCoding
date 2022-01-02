#include <bits/stdc++.h>

using namespace std;

bool compar(const pair<int,int>& a, const pair<int,int>& b) {
	int ln1 = a.second - a.first;
	int ln2 = b.second - b.first;
	return ln1 > ln2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	vector<pair<int, int>> v(n);
    	for (int i = 0; i < n; i++) {
    		cin >> v[i].first >> v[i].second;
    	}
    	sort(v.begin(), v.end(), compar);
    	set<int> edges;
    	edges.insert(0);
    	edges.insert(n+1);
    	map<pair<int, int>, int> m;

    	for (int i = 0; i < v.size(); i++) {
    		int a = v[i].first, b = v[i].second;
    		if (i == 0) {
    			if (a==b) {
	    			m[{a,b}]=a;
	    		}
	    		continue;
    		}
    		auto it1 = edges.upper_bound(a);
    		it1--;
    		auto it2 = edges.lower_bound(b);
    		// cerr << *it1 << endl;
    		if (*it1 == a-1) {
    			// cerr << "CUPPING TOP" << endl;
    			// find upper bound of b
    			m[{a, *it2-1}] = min(b+1, n);
    			edges.insert(b+1);
    		} else {
    			// cerr << "CUPPING BOT" << endl;
    			m[{*it1+1, b}] = max(1, a-1);
    			edges.insert(a-1);
    		}
    		if (a==b) {
    			m[{a,b}]=a;
    		}
    		// cerr << a << " " << b << endl;
    	}
    	for (auto& p: m) {
    		cout << p.first.first << " " << p.first.second << " " << p.second << endl;
    	}
    	cout << endl;

    }

	return 0;
}