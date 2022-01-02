#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
    	int k;
    	cin >> k;
    	vector<long long> v(k);
    	for (int i = 0; i < k; i++) {
    		cin >> v[i];
    	}

    	vector<long long> sorted(v);
    	sort(sorted.begin(), sorted.end());
    	vector<vector<int>> ans; // n x 3
    	for (int i = 0; i < k; i++) {
    		long long l = i;
    		long long r = k;
    		if (sorted[i] != v[i]) {
    			auto posToGet = find(v.begin()+l, v.begin()+r, sorted[i]);
    			rotate(v.begin()+l, posToGet, v.end());
    			ans.push_back(vector<int>{l+1, r, distance(v.begin()+l, posToGet)});
    		}
    	}
    	cout << ans.size() << endl;
    	for (int i = 0; i < ans.size(); i++) {
    		cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    	}
    }

	return 0;
}