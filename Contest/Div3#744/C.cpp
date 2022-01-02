#include <bits/stdc++.h>

using namespace std;

int N, M, K;



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
    	// cerr << "REEE" << endl;
    	cin >> N >> M >> K;
    	vector<vector<char>> orig(N, vector<char>(M));
    	vector<vector<char>> built(N, vector<char>(M));
    	for (int i = 0; i < N; i++) {
    		for (int j = 0; j < M; j++) {
    			cin >> orig[i][j];
    			built[i][j] = '.';
    		}
    	}
    	// try build mark of every len at each * we see
    	for (int i = 0; i < N; i++) {
    		for (int j = 0; j < M; j++) {
    			// cerr << i << ", " << j << endl;
    			if (orig[i][j] == '*') {
    				for (int k = N; k >= K; k--) {
	    				// i will go from i-K to i
	    				// j will go from j-K to j+K
	    				if (i-k < 0 || j-k < 0 || j+k >= M) {
	    					continue;
	    				}
	    				bool ok = true;
	    				for (int x = 0; x <= k; x++) {
	    					ok = ok && (orig[i-x][j-x] == '*' && orig[i-x][j+x] == '*');
	    				}
	    				// cerr << "HI" << endl;
	    				if (ok) {
	    					for (int x = 0; x <= k; x++) {
	    						built[i-x][j-x] = built[i-x][j+x] = '*';
	    					}
	    					break;
	    				}
    				}
    			}    			
    		}
    	}
    	bool good = true;
    	for (int i = 0; i < N; i++) {
    		for (int j = 0; j < M; j++) {
    			if (built[i][j] != orig[i][j]) {
    				good = false;
    			}
    		}
    	}
    	if (good) {
    		cout << "YES" << endl;
    	} else {
    		cout << "NO" << endl;
    	}
    }


	return 0;
}