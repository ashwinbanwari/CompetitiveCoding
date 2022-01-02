#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
    	int R, C, K;
    	cin >> R >> C >> K;
    	R+=2;
    	K++;
    	vector<vector<char>> mat(R, vector<char>(C));
    	for (int j = 0; j < C; j++) {
    		mat[0][j] = '.';
    		mat[R-1][j] = '.';
    	}
    	for (int i = 1; i < R-1; i++) {
    		for (int j = 0; j < C; j++) {
    			cin >> mat[i][j];
    		}
    	}
    	/*
    	for (int i = 0; i < R; i++) {
    		for (int j = 0; j < C; j++) {
    			cerr << mat[i][j] << " ";
    		}
    		cerr << endl;
    	}*/
    	
    	// push down
    	vector<unordered_set<int>> goodPushDownVals(C);
    	for (int i = 0; i < C; i++) {
    		int below1s = 0;
    		for (int j = R-1; j >= 0; j--) {
    			if (mat[j][i] == 'X') {
    				below1s++;
    			} else if (j <= (K-1) && below1s+1 < (R-(K-1))) {
    				int dist = (K-1) - j;
    				// cerr << "push down " << dist << endl;
    				goodPushDownVals[i].insert(j);
    			}
    		}
    	}
    	// push up
    	vector<unordered_set<int>> goodPushUpVals(C);
    	for (int i = 0; i < C; i++) {
    		int below1s = 0;
    		for (int j = 0; j < R; j++) {
    			if (mat[j][i] == 'X') {
    				below1s++;
    			} else if (j >= (K-1) && below1s+1 < K) {
    				int dist = j-(K-1);
    				// cerr << "push up " << j << endl;
    				goodPushUpVals[i].insert(j);
    			}
    		}
    	}

    	int ans = INT_MAX;
    	for (int i = 0; i < R; i++) {
    		int ans1 = C;
    		int ans2 = C;
    		for (int j = 0; j < C; j++) {
    			ans1 -= goodPushDownVals[j].count(i);
    			ans2 -= goodPushUpVals[j].count(i);
    		}
    		int bestHere = min(ans1, ans2) + abs(i-(K-1));
    		ans = min(ans, bestHere);
    	}
    	cout << "Case #" << i << ": " << ans << endl;
    }
	return 0;
}