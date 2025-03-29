#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int good(vector<int>& v, int minScore) {
    int teams = 0;
    int len = 0;
    for (int i = 0; i < v.size(); i++) {
        len++;
        if (v[i] * len >= minScore) {
            teams++;
            len = 0;
        }
    }
    return teams;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        sort(v.rbegin(), v.rend());

        cout << good(v, x) << endl;
	}

	return 0;
}
