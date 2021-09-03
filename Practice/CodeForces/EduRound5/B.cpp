#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    int highestMin = INT_MIN;;
    for (int i = 0; i < n; i++) {
    	int mini = INT_MAX;
    	for (int j = 0; j < m; j++) {
    		int curr;
    		cin >> curr;
    		mini = min(curr, mini);
    	}
    	highestMin = max(highestMin, mini);
    }
    cout << highestMin << endl;

	return 0;
}