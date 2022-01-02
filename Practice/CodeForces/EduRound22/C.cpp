#include <bits/stdc++.h>

using namespace std;

void BFS(vector<vector<int>>& g, int startNode, vector<int>& dist) {
	dist[startNode] = 0;
	queue<int> q;
	q.push(startNode);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int neighbor : g[curr]) {
			if (dist[neighbor] == -1) {
				q.push(neighbor);
				dist[neighbor] = dist[curr]+1;
				// cerr << neighbor << " " << dist[neighbor] << endl;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, x;
	cin >> n >> x;
    vector<vector<int>> g(n);
    vector<int> distFromRoot(n,-1);
    vector<int> distFromX(n,-1);
    for (int i = 0; i < n-1; i++) {
    	int a, b;
    	cin >> a >> b;
    	a--; b--;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }

    BFS(g, 0, distFromRoot);
    BFS(g, x-1, distFromX);

    int bestDist = 0;
    for (int i = 0; i < n; i++) {
    	if (distFromRoot[i] > distFromX[i]) {
    		bestDist = max(bestDist, distFromRoot[i]);
    	}
    }
    cout << 2 * bestDist << endl;


	return 0;
}