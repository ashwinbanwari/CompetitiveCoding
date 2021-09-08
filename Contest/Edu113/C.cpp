#include <bits/stdc++.h>

using namespace std;

long long modfact(long long n, int mod) {
	long long res = 1;
    for (long long i = 2; i <= n; i++)
        res = (res * i) % mod;
    return res;
}

long long nCr(long long n, long long r, int mod) {
	long long res = 1;
	for (int i = n; i >= n-r+1; i--) {
		res = (res * i) % mod;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int mod = 998244353;
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	vector<int> v(n);
    	for (int i = 0; i < n; i++) {
    		cin >> v[i];
    	}
    	sort(v.begin(), v.end());
    	int maxi = v.back();
    	int relev = v[v.size()-2];
    	if (maxi > relev+1) {
    		cout << 0 << endl;
    		continue;
    	}
    	if (maxi == relev) {
    		cout << modfact(n, mod) << endl;
    		continue;
    	}
    	long long numNotRelev = 0;
    	for (int i = 0; i < n; i++) {
    		if (v[i] == relev) {
    			numNotRelev = i;
    			break;
    		}
    	}
    	long long numRelev = n-numNotRelev-1;
    	cout << ((nCr(n, numNotRelev, mod)) * ((numRelev * modfact(numRelev, mod))%mod) % mod) << endl;
    }

	return 0;
}