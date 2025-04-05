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

    int n, m;
	cin >> n >> m;
	vector<int> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}

	unordered_set<int> available;
	for (int i = 1; i <= n; i++) {
		available.insert(i);
	}

	vector<int> answer(n, -1);

	bool good = true;

	for (int i = 1; i < m; i++) {
		int child = v[i-1] - 1;
		int expectedDiff = (n + v[i] - v[i-1]) % n;
		if (expectedDiff == 0) expectedDiff = n;
		if (answer[child] == -1 && available.count(expectedDiff)) {
			answer[child] = expectedDiff;
			available.erase(expectedDiff);
		} else if (answer[child] == expectedDiff) {
			continue;
		} else {
			good = false;
			break;
		}
	}

	if (!good) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (answer[i] == -1) {
			answer[i] = *available.begin();
			available.erase(available.begin());
		}
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}
	cout << endl;
    
	return 0;
}
