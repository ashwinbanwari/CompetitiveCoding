#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, t;
	cin >> n >> t;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int best = 0;
	int count = 0;

	int minnow = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (v[i] - minnow == best) {
			count++; 
		} else if (v[i] - minnow > best) {
			count = 1;
			best = v[i] - minnow;
		}
		minnow = min(minnow, v[i]);
	}

	cout << count << endl;
    
	return 0;
}
