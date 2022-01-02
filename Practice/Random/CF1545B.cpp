#include <bits/stdc++.h>

using namespace std;

long long mod = 998244353;

long long fact(long long n) {
	if (n == 0) {
		return 1;
	}
	long long res = n * fact(n-1);
	res %= mod;
	return res;
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
	long long res = fact(n) * modInv(fact(k));
	res %= mod;
	res *= modInv(fact(n-k));
	res %= mod;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	string s;
    	cin >> s;
    	int numPairs = 0;
    	int zeros = count(s.begin(), s.end(), '0');
    	for (int i = 1; i < n; i++) {
    		if (s[i] == s[i-1] && s[i] == '1') {
    			numPairs++;
    			i++;
    		}
    	}
    	cout << nChooseK(numPairs+zeros, zeros) << endl;
    }

	return 0;
}