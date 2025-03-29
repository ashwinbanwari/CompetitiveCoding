#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;

bool isPrime(int x) {
    for (int i = 2; i <= x / 2; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    // calculate list of primes
    int n = 10000001;
    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    vector<int> primesBeforeHere(n, 0);
    for (int i = 1; i < n; i++) {
        primesBeforeHere[i] = primesBeforeHere[i-1] + (isPrime[i] ? 1 : 0);
    }

	int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        int count = 0;

        for (int i = 1; i <= x; i++) {
            count += primesBeforeHere[x / i];
        }

        cout << count << endl;


        
    }
    
	return 0;
}
