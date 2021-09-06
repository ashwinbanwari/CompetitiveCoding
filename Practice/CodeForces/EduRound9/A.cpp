#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, p;
    cin >> n >> p;
    vector<bool> v(n);
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	if (s=="halfplus") {
    		v[i] = true;
    	}
    }
    long long apples = 0;
    long long ans = 0;
    for (int i = n-1; i >= 0; i--) {
    	apples *= 2;
    	ans += (p/2) * apples;
    	if (v[i]) {
    		apples+=1;
    		ans += p/2;
    	}
    	// cerr << ans << endl;
    }
    cout << ans << endl;

	return 0;
}