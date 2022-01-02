#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	vector<int> v(n);
    	for (int i = 0; i < v.size(); i++) {
    		cin >> v[i];
    	}
    	string s;
    	cin >> s;
    	vector<int> ans(n);
    	vector<int> locations(n+1);
    	for (int i = 0; i < n; i++) {
    		locations[v[i]] = i;
    	}
    	vector<int> ones;
    	vector<int> zeros;
    	for (int i = 0; i < n; i++) {
    		if(s[i] == '1') {
    			ones.push_back(v[i]);
    		} else {
    			zeros.push_back(v[i]);
    		}
    	}
    	
    	sort(ones.begin(), ones.end());
    	sort(zeros.begin(), zeros.end());
    	int zerosIdx = 0;
    	for (int i = 0; i < n; i++) {
    		if (s[i] == '0') {
    			int idx = locations[zeros[zerosIdx]];
    			ans[idx] = zerosIdx + 1;
    			zerosIdx++;
    		}
    	}
    	int onesIdx = 0;
    	for (int i = 0; i < n; i++) {
    		if (s[i] == '1') {
    			int idx = locations[ones[onesIdx]];
    			ans[idx] = zerosIdx+1;
    			zerosIdx++;
    			onesIdx++;
    		}
    	}
    	for (int i : ans) {
    		cout << i << " ";
    	}
    	cout << endl;
    }

	return 0;
}