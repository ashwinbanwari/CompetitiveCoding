#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <climits>

using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
	cin >> n >> k;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] > k * 2) {
			count++;
			i--;
			k *= 2;
		} else {
			k = max(k, v[i]);
		}
	}

	cout << count << endl;
    
	return 0;
}
