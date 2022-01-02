#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    // inclusive
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
    	// cerr << "IT"<< endl;
    	int n;
    	cin >> n;
    	vector<int> v(n);
    	unordered_set<int> seen;
    	bool dup = false;
    	for (int i = 0; i < n; i++) {
    		cin >> v[i];
    		if (seen.find(v[i]) != seen.end()) {
    			dup = true;
    		}
    		seen.insert(v[i]);
    	}
    	if (dup) {
    		cout << "YES" << endl;
    		continue;;
    	}
    	
    	if (v.size() < 3) {
    		vector<int> sorted(v.begin(), v.end());
    		sort(sorted.begin(), sorted.end());
    		if (v == sorted) {
    			cout << "YES" << endl;
    		} else {
    			cout << "NO" << endl;
    		}
    		continue;
    	}
    	int inversions = 0;
    	int maxval = *max_element(v.begin(), v.end());
    	FenwickTree ft(maxval+1);
    	for (int i = 0; i < n; i++) {
    		ft.add(v[i], 1);
    		inversions += ft.sum(v[i]+1, maxval);
    	}
    	if (inversions % 2 == 0) {
    		cout << "YES" << endl;
    	} else {
    		cout << "NO" << endl;
    	}
    }

	return 0;
}