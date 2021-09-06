#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
    	cin >> v[i].first >> v[i].second;
    }

    set<pair<int, int>> s; // NEED FENWICK TREE, COME BACK LATER

	return 0;
}