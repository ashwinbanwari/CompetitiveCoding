#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
    	cin >> b[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < b.size(); i++) {
    	auto it = upper_bound(a.begin(), a.end(), b[i]);
    	int diff = (it - a.begin());
    	cout << diff << " ";
    }

	return 0;
}