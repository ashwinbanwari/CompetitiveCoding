#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < n; i++) {
    	int next;
    	cin >> next;
    	v[next-1]++;
    }
    int res = 0;
    int tot = n;
    for (int i = 0; i < m; i++) {
    	res += (tot - v[i]) * v[i];
    	tot -= v[i];
    }

    cout << res << endl;

	return 0;
}