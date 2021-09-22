#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int a, b, c, m;
    	cin >> a >> b >> c >> m;
    	vector<int> s{a, b, c};
    	sort(s.begin(), s.end());
    	int maxAdjacent = max(0, s[2]-1) + max(0, s[1]-1) + max(0, s[0]-1);
    	int minAdjacent = max(0, s[2]-s[1]-s[0] - 1);
		cerr << minAdjacent << " " << maxAdjacent << endl;
    	if (m <= maxAdjacent && m >= minAdjacent) {
    		cout << "YES" << endl;
    	} else {
    		cout << "NO" << endl;
    	}
    }

	return 0;
}