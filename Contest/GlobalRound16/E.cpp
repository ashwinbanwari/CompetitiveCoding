#include <bits/stdc++.h>

using namespace std;

void cleanTree(int vertex, unordered_map<int, unordered_set<int>>& edges, int prevVertex = 0) {
	unordered_set<int>& curr = edges[vertex];
	curr.erase(prevVertex);
	for (int v : curr) {
		cleanTree(v, edges, vertex);
	}
}

int attachToRoot(int vertex, unordered_map<int, unordered_set<int>>& edges, int prevVertex = 0) {
	unordered_set<int> curr = edges[vertex];
	int k = 0;
	for (int i : curr) {
		k += attachToRoot(i, edges, vertex);
	}
	if (vertex != 1 && prevVertex != 1 && !edges[vertex].empty()) {
		edges[prevVertex].erase(vertex);
		k++;
	}
	return k;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	unordered_map<int, unordered_set<int>> edges;
    	for (int i = 0; i < n-1; i++) {
    		int currA;
    		int currB;
    		cin >> currA >> currB;
    		// cerr << currA << ", " << currB << endl;
    		edges[currA].insert(currB);
    		edges[currB].insert(currA);
    	}
    	cleanTree(1, edges);
    	int k = attachToRoot(1, edges);
    	bool rootHasLeaf = false;
    	for (int i : edges[1]) {
    		if (edges[i].empty()) rootHasLeaf = true;
    		else k++;
    	}
    	// cerr << k << endl;
    	// cerr << "hasLeaf = " << rootHasLeaf << endl;
    	cout << n-2*k-(static_cast<int>(rootHasLeaf)) << endl;
    }

	return 0;
}