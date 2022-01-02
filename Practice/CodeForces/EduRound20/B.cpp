#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
    	cin >> v[i];
    }

    vector<int> idxes;
    for (int i = 0; i < n; i++) {
    	if (v[i] == 0) {
    		idxes.push_back(i);
    		// cerr << i << endl;
    	}
    }

    for (int i = 0; i < n; i++) {
    	auto it = lower_bound(idxes.begin(), idxes.end(), i);
    	if (it == idxes.begin()) {
    		cout << abs(*it-i) << " ";
    	} else if (it == idxes.end()) {
    		cout << abs(i - *(prev(it))) << " ";
    	} else {
    		cout << min(abs(i-*it), abs(i-*(prev(it)))) << " ";
    	}
    }

	return 0;
}