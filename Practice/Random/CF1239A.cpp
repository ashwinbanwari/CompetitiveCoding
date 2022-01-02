#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<long long> fib(max(n,m)+1);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < fib.size(); i++) {
    	fib[i] = fib[i-1] + fib[i-2];
    	fib[i] %= mod;
    }

    cout << (2 * ((fib[n]+fib[m]-1) % mod)) % mod << endl;

	return 0;
}