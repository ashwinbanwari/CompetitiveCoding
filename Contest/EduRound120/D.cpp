#include <bits/stdc++.h>

using namespace std;

long long mod = 998244353;


long long fact(long long n) {
	if (n == 1 || n == 0) {
		return 1;
	}
	long long ans = n * fact(n-1);
	ans %= mod;
	return ans;
}

long long pow(long long n, long long k) {
	long long res = 1;
	while (k > 0) {
		if (k & 1) {
			res *= n;
			res %= mod;
		}
		n *= n;
		n %= mod;
		k /= 2;
	}
	return res;
}

long long modInv(long long n) {
	return pow(n, mod-2) % mod;
}

long long nChooseK(long long n, long long k) {
	long long res = fact(n);
	res *= modInv(fact(k));
	res %= mod;
	res *= modInv(fact(n-k));
	res %= mod;
	return res;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> idx;
    for (int i = 0; i < n; i++)  {
    	if (s[i] == '1') {
    		idx.push_back(i);
    	}
    }
    long long ans = 1;

    int a = 0;
    int b = k-1;
    for (; b < idx.size(); b++) {
    	int l = 0;
    	if (a > 0) {
    		l = idx[a-1]+1;
    	}
    	int r = n-1;
    	if (b != idx.size()-1) {
    		r = idx[b+1]-1;
    	}
    	//cerr << l << " " << r << endl;
    	// cerr << r-l+1 << " choose " << k << endl;
    	ans += nChooseK(r-l+1, k);
    	int num = k-1;
    	if (b != idx.size()-1) {
    		num = r-idx[a];
    	}
    	// cerr << num << endl;
    	// cerr << "minus " << num << " choose " << k-1 << endl;
    	ans -= nChooseK(num, k-1);
    	ans %= mod;
    	a++;
    	
    }
    cout << ans << endl;

	return 0;
}