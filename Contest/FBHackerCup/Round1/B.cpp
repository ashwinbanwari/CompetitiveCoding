#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
    	int n, m, a, b;
    	cin >> n >> m >> a >> b;
    	vector<vector<int>> grid(n, vector<int>(m, 1));
    	int mini = min(a,b);
    	if (n+m-1 > mini) {
    		cout << "Case #" << i << ": " << "Impossible" << endl;
    		continue;
    	}
    	grid[n-1][m-1] = a - (n+m-2);
    	grid[n-1][0] = b - (n+m-2);
    	cout << "Case #" << i << ": " << "Possible" << endl;
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			cout << grid[i][j] << " ";
    		}
    		cout << endl;
    	}
    }

	return 0;
}