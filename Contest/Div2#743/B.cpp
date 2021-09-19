#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	vector<int> evens(n);
    	vector<int> odds(n);
    	for (int i = 0; i < n; i++) {
    		cin >> odds[i];
    	}
    	for(int i = 0; i < n; i++) {
    		cin >> evens[i];
    	}
    	int bestResult = INT_MAX;
    	vector<int> largestSoFar(n);
    	largestSoFar[0] = evens[0];
    	for (int i = 1; i < n; i++) {
    		largestSoFar[i] = max(largestSoFar[i-1], evens[i]);
    	}
    	for (int i = 0; i < n; i++) {
    		int dist = distance(largestSoFar.begin(), upper_bound(largestSoFar.begin(), largestSoFar.end(), odds[i]));
    		int res = dist + i;
    		bestResult = min(bestResult, res);
    	}
    	cout << bestResult << endl;

    }

	return 0;
}