#include <bits/stdc++.h>

using namespace std;

//direction 1 right, 0 down
long long DFS(int i, int j, int direction, vector<vector<char>>& grid, int currK, int maxK) {
	int N = grid.size();

	if (i < 0 || i > N-1 || j < 0 || j > N-1 || grid[i][j] == 'H' || currK > maxK) {
		return 0;
	}

	if (i == N-1 && j == N-1) {
		return 1;
	}
	long long ans = 0;
	if (i+1-direction < N && j+direction < N) {
		ans += DFS(i+1-direction, j+direction, direction, grid, currK, maxK);
	}
	if (direction+i < N && j+1-direction < N && currK != maxK && !(currK==maxK-1 && !(direction+i==N-1 || j+1-direction == N-1))) {
		ans += DFS(direction+i, j+1-direction, 1-direction, grid, currK+1, maxK);
	}
	return ans;
	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
    	int N, K;
    	cin >> N >> K;
    	vector<vector<char>> grid(N, vector<char>(N));
    	for (int i = 0; i < N; i++) {
    		for (int j = 0; j < N; j++) {
    			cin >> grid[i][j];
    		}
    	}
    	cout << DFS(0, 1, 1, grid, 0, K) + DFS(1, 0, 0, grid, 0, K) << endl;
    }

	return 0;
}