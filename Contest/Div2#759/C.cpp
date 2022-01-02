#include <bits/stdc++.h>

using namespace std;


long long solve(vector<long long> v, int k) {
	long long cost = 0;
    int bagsLeft = v.size() % k;
    int location = 0;
	for (int i = 0; i < v.size(); i++) {
		if (bagsLeft == 0) {
			cost += abs(location);
			bagsLeft = k;
			location = 0;
		}
		cost += abs(v[i] - location);
		location = v[i];
		bagsLeft--;
	}
	return cost;
}

long long solveGoBack(vector<long long> v, int k) {
	long long cost = 0;
    int bagsLeft = v.size() % k;
    int location = 0;
	for (int i = 0; i < v.size(); i++) {
		if (bagsLeft == 0) {
			cost += abs(location);
			bagsLeft = k;
			location = 0;
		}
		cost += abs(v[i] - location);
		location = v[i];
		bagsLeft--;
	}
	return cost+location;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
    	int n, k;
    	cin >> n >> k;
    	vector<long long> v;
    	vector<long long> w;
    	for (int i = 0; i < n; i++) {
    		int x;
    		cin >> x;
    		if (x <= 0) {
    			v.push_back(abs(x));
    		} else {
    			w.push_back(x);
    		}
    	}
    	sort(v.begin(), v.end());
    	sort(w.begin(), w.end());
    	cout << min(solve(v, k)+solveGoBack(w, k), solveGoBack(v,k) + solve(w,k)) << endl;
    }

	return 0;
}