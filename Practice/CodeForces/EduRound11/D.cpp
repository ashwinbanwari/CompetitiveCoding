#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    map<pair<int, int>, int> m; 
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++) {
    	cin >> pairs[i].first >> pairs[i].second;
    }

    for (int i = 0; i < n; i++) {
    	for (int j = i+1; j < n; j++) {
    		m[{pairs[i].first+pairs[j].first, pairs[i].second+pairs[j].second}]++;
    	}
    }

    long long res = 0;
    for (auto bigP : m) {
    	res += ((long long)bigP.second * (bigP.second-1)) / 2;
    }
    cout << res << endl;

	return 0;
}