#include <bits/stdc++.h>

using namespace std;

long long mod = pow(10,9) + 7;

long long modpow(long long a, long long b) {
	long long res = 1;
	a = a % mod;

	while (b > 0) {
		if (b&1) {
			res *= a;
			res %= mod;
		}
		b>>=1;
		a=(a*a) % mod;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    long long A, B, n, x;
    cin >> A >> B >> n >> x;
    if (A!=1) {
    	cout << ((modpow(A,n)*x)%mod + B*(((modpow(A,n)-1)*(modpow(A-1,mod-2)))%mod)%mod)%mod << endl; // Fermat's Little Theorem for Modualr Inverse
    } else {
    	cout << (x + ((n%mod)*B)%mod)%mod << endl;
    }
    

	return 0;
}