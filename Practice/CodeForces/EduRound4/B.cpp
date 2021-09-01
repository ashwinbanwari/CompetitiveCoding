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

    vector<int> idx(n+1);
    for (int i = 0; i < n; i++) {
    	idx[v[i]] = i;
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
    	ans += abs(idx[i+1] - idx[i]);
    }
    cout << ans << endl;

	return 0;
}