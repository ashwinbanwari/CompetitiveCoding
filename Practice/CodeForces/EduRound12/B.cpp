#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> row(k);
    for (int i = 0; i < k; i++) {
    	cin >> row[i];
    }
    int timeTaken = 0;
    for (int i = 0; i < n*m; i++) {
    	int curr;
    	cin >> curr;
    	auto it = find(row.begin(), row.end(), curr);
    	timeTaken += distance(row.begin(), it) + 1;
    	row.erase(it);
    	row.insert(row.begin(),curr);
    }

    cout << timeTaken;

	return 0;
}