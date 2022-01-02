#include <bits/stdc++.h>

using namespace std;

long long mod = 4;

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
	return pow(n, mod-1) % mod;
}

long long nChooseK(long long n, long long k) {
	long long res = fact(n) * modInv(fact(k));
	res %= mod;
	cerr << fact(n) << " x " << modInv(fact(k)) << res << endl;
	res *= modInv(fact(n-k));
	res %= mod;
	return res;
}

int main() {

    unordered_set<unordered_set<char>> hi;

	return 0;
}