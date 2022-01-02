#include <bits/stdc++.h>

using namespace std;


void DFS(int curr, vector<pair<int, int>>& edges, vector<pair<int, int>>& parents, unordered_set<int>& seen) {
	seen.insert(curr);
	for (auto& neighbor : edges) {
		if (seen.find(neighbor.first) == seen.end()) {
			parents[curr] = {neighbor.first, neighbor.second};
			DFS(neighbor.first, edges, parents, seen);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(n+1);
    for (int i = 0; i < n-1; i++) {
    	int a, b, edge;
    	edges[a] = {b, edge};
    	edges[b] = {a, edge};
    }

    vector<pair<int, int>> parents(n+1);
    unordered_set<int> seen;
    seen.insert(1);
    DFS(1, edges, parents, seen);
    for (int i = 1; i <= n; i++) {
    	if (parents[i].first == 0) {
    		// leaf
    	}
    }

	return 0;
}