#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, w;
    cin >> w >> n;
    multimap<int, int, greater<int>> m;
    for (int i = 0; i < w; i++) {
    	int in;
    	cin >> in;
    	m.insert(make_pair(in, i));
    }
    vector<int> ans(w);
    for (const pair<int, int>& p : m) {
    	int teaRequired = (p.first + 1) / 2;
    	ans[p.second] += teaRequired;
    	n -= teaRequired;
    }
    if (n < 0) {
    	cout << -1 << endl;
    	return 0;
    }

    for (pair<int, int> const& p : m) {
    	int teaCanAdd = min(n, p.first - ans[p.second]);
    	ans[p.second] += teaCanAdd;
    	n -= teaCanAdd;
    }
    for (int i : ans) {
    	cout << i << " ";
    }
    cout << endl;

	return 0;
}