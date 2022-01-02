#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> mat(n, vector<int>(n));
    if (k > n * n) {
    	cout << -1 << endl;
    	return 0;
    } else if (k <= n * n) {
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			if (k == 0) {
    				goto end;
    			}
    			if (mat[i][j]) {
    				continue;
    			}
    			if (i==j) {
    				k--;
    				mat[i][j] = 1;
    			} else {
    				if (k >= 2) {
    					k -= 2;
    					mat[i][j] = 1;
    					mat[j][i] = 1;
    				}
    			}
    		}
    	}
    }
    end:
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		cout << mat[i][j] << " ";
    	}
    	cout << endl;
    }

	return 0;
}