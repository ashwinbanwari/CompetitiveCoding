#include <bits/stdc++.h>

using namespace std;

long long getGCD(vector<long long> v, int strt) {
	long long ret = v[strt];
	for (int i = strt; i < v.size(); i+=2) {
		ret = gcd(ret, v[i]);
	}
	return ret;
}

bool checkGCD(vector<long long> v, int strt, long long gcd) {
	for (int i = strt; i < v.size(); i+=2) {
		if (v[i] % gcd == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
    	int n;
    	cin >> n;
    	vector<long long> v(n);
    	for (int i = 0; i < n; i++) {
    		cin >> v[i];
    	}
    	long long evenGCD = getGCD(v, 0);
    	// cerr << "even" << evenGCD << endl;
	    if (evenGCD != 0 && checkGCD(v, 1, evenGCD)) {
	    	cout << evenGCD << endl;
	    	continue;
	    }

	    long long oddGCD = getGCD(v, 1);
	    // cerr << "odd" << oddGCD << endl;
	    if (oddGCD != 0 && checkGCD(v, 0, oddGCD)) {
	    	cout << oddGCD << endl;
	    	continue;
	    }
	    cout << 0 << endl;
    }



	return 0;
}