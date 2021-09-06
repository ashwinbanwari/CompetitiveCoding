#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
    	cin >> v[i];
    }

    unordered_map<int, int> valToIdx;
    for (int i = 0; i < n; i++) {
    	valToIdx[v[i]] = i;
    }

    vector<int> bigLeft(n, -1);
    for (int i = 0; i < m; i++) {
    	int a, b;
    	cin >> a >> b;
    	a = valToIdx[a];
    	b = valToIdx[b];
    	int hi = max(a,b);
    	int lo = min(a,b);
    	if (bigLeft[hi] < lo) {
    		bigLeft[hi] = lo;
    	}
    }

    vector<int> dp(n);
    dp[0] = -1;
    for (int i = 1; i < n; i++) {
    	dp[i] = max(bigLeft[i], dp[i-1]);
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
    	long long n = i-dp[i];
    	res += n;
    	// cerr << n << endl;
    }
    cout << res << endl;



	return 0;
}