#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
    	int n = 7;
    	vector<int> v(n);
    	for (int i = 0; i < n; i++) {
    		cin >> v[i];
    	}
    	vector<int> ans;
    	ans.push_back(v[0]);
    	ans.push_back(v[1]);
    	if (v[2] == v[0]+v[1]) {
    		ans.push_back(v[3]);
    	} else {
    		ans.push_back(v[2]);
    	}
    	for (int i : ans) {
    		cout << i << " ";
    	}
    	cout << endl;
    }

	return 0;
}