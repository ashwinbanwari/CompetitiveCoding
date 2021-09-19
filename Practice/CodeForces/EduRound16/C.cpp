#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n)); // 0 is even. 1 is odd
    for (int i = 0; i < n; i++) {
    	if (i <= n/2) {
    		for (int j = n/2 - i; j <= n/2 + i; j++) {
    			matrix[i][j] = 1;
    		}
    	} else {
    		for (int j = i-n/2; j <= 3*(n/2)-i; j++) {
    			matrix[i][j] = 1;
    		}
    	}
    }

    int currEven = 2;
    int currOdd = 1;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if (matrix[i][j] == 0) {
    			cout << currEven << " ";
    			currEven += 2;
    		} else {
    			cout << currOdd << " ";
    			currOdd += 2;
    		}
    	}
    	cout << endl;
    }

	return 0;
}