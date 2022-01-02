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

    int t;
    cin >> t;
    vector<FenwickTree> v(32, FenwickTree(2e5+1));
    for (int i = 0; i <= 2e5; i++) {
    	for (int j = 0; j < 32; j++) {
    		int bit = 1 << j;
    		if (bit & i) {
    			v[j].add(i, 1);
    		}
    	}
    }
    while (t--) {
    	int l, r;
    	cin >> l >> r;
    	int maxSum = 0;
    	for (int i = 0; i < 32; i++) {
    		int currSum = v[i].sum(l, r);
    		maxSum = max(maxSum, currSum);
    	}
    	int len = r-l+1;
    	cout << len-maxSum << endl;
    }

	return 0;
}