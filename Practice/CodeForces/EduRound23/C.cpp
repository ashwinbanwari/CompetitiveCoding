#include <bits/stdc++.h>

using namespace std;

bool works(long long x, long long s) {
	int checkAmount = 18;
	long long value = 0;
	for (int i = 1; i <= checkAmount; i++) {
		x /= 10;
		value += 9 * x;
	}
	return value >= s;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, s;
    cin >> n >> s;
    /*for (int i = 1; i <= n; i++) {
    	if (works(i, s)) {
    		cout << n-i+1 << endl;
    		return 0;
    	}
    }*/
    long long x = -1;
    long long r = n;
    for (long long i = 1e18; i >= 1; i /= 2) {
    	while (!works(x+i, s)) {
    		x += i;
    	}
    }
    x++;
    cout << max(0LL, n-x+1) << endl;
	return 0;
}