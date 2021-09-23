#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int  i = 0; i < n; i++) {
    	cin >> v[i];
    }

    sort(v.begin(), v.end());
    long long minDist = INT_MAX;
    int ans = 0;
    for (int i = 1; i < n; i++) {
    	if (v[i] - v[i-1] == minDist) {
    		ans++;
    	} else if (v[i] - v[i-1] < minDist) {
    		minDist = v[i] - v[i-1];
    		ans = 1;
    	}
    }
    cout << minDist << " " << ans << endl;
	return 0;
}