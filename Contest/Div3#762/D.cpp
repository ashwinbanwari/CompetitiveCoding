#include <bits/stdc++.h>

using namespace std;



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	string _;
    	getline(cin, _);
    	int m, n;
    	cin >> m >> n;
    	vector<vector<int>> p(m, vector<int>(n));
    	for (int i = 0; i < m; i++) {
    		for (int j = 0; j < n; j++) {
    			cin >> p[i][j];
    		}
    	}
    	int highestForEach = INT_MAX;
    	for (int i = 0; i < n; i++) {
    		int best = 0;
    		for (int j = 0; j < m; j++) {
    			best = max(p[j][i], best);
    		}
    		highestForEach = min(highestForEach, best);
    	}
    	int bestTwoInRow = 0;
    	for (int i = 0; i < m; i++) {
    		vector<int> currRow;
    		for (int j = 0; j < n; j++) {
    			currRow.push_back(p[i][j]);
    		}
    		sort(currRow.begin(), currRow.end(), greater<int>());
    		bestTwoInRow = max(bestTwoInRow, currRow[1]);
    	}
    	cout << min(bestTwoInRow, highestForEach) <<endl;

    }

	return 0;
}