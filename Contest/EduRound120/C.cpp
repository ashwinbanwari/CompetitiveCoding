#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	long long n, k;
    	cin >> n >> k;
    	vector<long long> v(n);
    	for (int i = 0; i < n; i++) {
    		cin >> v[i];
    	} 
    	long long sum = accumulate(v.begin(), v.end(), 0LL);
    	if (sum <= k) {
    		cout << 0 << endl;
    		continue;
    	}
    	sort(v.begin(), v.end());
    	long long smally = v[0];
        long long decrements = 0;
        long long diff = smally*n - k;
        if (diff > 0) {
        	decrements = ((diff + n - 1) / n);
        }
        long long bestAnswer = decrements + n-1;
        long long sumSmallEnufs = 0;
        // increase decrements, decrease n
        long long lastAnswer = LLONG_MAX;
        for (int i = 1; i < n; i++) {
        	sumSmallEnufs += v[i];
        	diff = smally*(n-i) + sumSmallEnufs - k;
        	// cerr << "diff: " << diff << endl;
        	decrements = (diff + n - i - 1) / (n-i);
        	decrements = max(0LL, decrements);
        	// cerr << decrements +n-1-i << endl;
        	bestAnswer = min(max(0LL, bestAnswer), decrements+n-1-i);
        	if (decrements+n-1-i > lastAnswer) {
        		break;
        	}
        	lastAnswer = decrements+n-1-i;
        }
        cout << bestAnswer << endl;
    }

	return 0;
}