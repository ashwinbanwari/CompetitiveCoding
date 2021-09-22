#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, k;
    cin >> n >> k;
    list<long long> dog;
    auto it1 = dog.begin(); // points to middle
    for (long long i = 1; i <= sqrt(n); i++) {
    	if (n % i == 0) {
    		if (i == n/i) {
    			dog.insert(it1, i);
    		} else {
    			dog.insert(it1, i);
	    		dog.insert(it1, n/i);
	    		it1--;
    		}
    	}
    }
    if (k > dog.size()) {
    	cout << -1 << endl;
    	return 0;
    }
    long long i = 0;
    for (auto it = dog.begin(); it != dog.end(); it++) {
    	// cerr << *it << endl;
    	if (i == k-1) {
    		cout << *it << endl;
    	}
    	i++;
    }
	return 0;
}