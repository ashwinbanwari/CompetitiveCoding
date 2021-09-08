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

    set<int> zeros;
    for (int i = 0; i < v.size(); i++) {
    	if (v[i] == 0) {
    		zeros.insert(i);
    	}
    }
    if (k >= zeros.size()) {
    	cout << n << endl;
    	for (int i = 1; i <= n; i++) {
    		cout << 1 << " ";
    	}
    	cout << endl;
    	return 0;
    }
    auto i = zeros.begin();
    auto j = i;
    advance(j, k);
    int res = *j;
    j++;
    auto resI = zeros.end();
    while (j != zeros.end()) {
    	int curr = *j - *i - 1;
    	if (curr > res) {
    		resI = i;
    		res = curr;
    	}
    	i++;
    	j++;
    }
    int curr = n - *i - 1;
    if (curr > res) {
		res = curr;
		resI = i;
	}

	cout << res << endl;
	if (resI == zeros.end()) {
		// special case, remove first x zeros
		resI = zeros.begin();
		advance(resI, k);
		int lastJ = *resI;
		for (int i = 0; i < lastJ; i++) {
			cout << 1 << " ";
		}
		for (int i = lastJ; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		return 0;
	}
	int finalI = distance(zeros.begin(), resI);

	int finalJ;
	if (finalI+k+1 == zeros.size()) {
		finalJ = n;
	} else {
		auto resJ = resI;
		advance(resJ, k+1);
		finalJ = *resJ;
	}

    // cerr << finalI << ", " << finalJ << endl;

    for (int i = 0; i < n; i++) {
    	if (i == *resI+1) {
    		for (; i < finalJ; i++) {
    			cout << 1 << " ";
    		}
    		i--;
    	} else {
    		cout << v[i] << " ";
    	}
    }
    cout << endl;

	return 0;
}