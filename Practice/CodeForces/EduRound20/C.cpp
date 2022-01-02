#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long n, k;
	cin >> n >> k;


	list<long long> divisors;
	auto it = divisors.begin();
	for (long long i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (i * i == n) {
				divisors.insert(it, i);
				break;
			}
			it = divisors.insert(it, i);
			it++;
			it = divisors.insert(it, n / i);
		}
	}
	reverse(divisors.begin(), divisors.end());
	if (k > pow(10,6)) {
		cout << -1 << endl;
		return 0;
	}
	
    for (long long i : divisors) {
    	if ((k * i <= pow(10,10)) && (k * (2*i + (k-1)*i)) / 2 <= n) {
    		for (int j = 0; j < k-1; j++) {
    			cout << (j+1)*i << " ";
    			n -= (j+1)*i;
    		}
    		cout << n << endl;
    		return 0;
    	}
    }

    cout << -1 << endl;

	return 0;
}