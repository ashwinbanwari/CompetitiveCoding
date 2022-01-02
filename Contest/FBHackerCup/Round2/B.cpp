#include <bits/stdc++.h>

using namespace std;



struct Node {
	unordered_set<int> neighbors;
	int freq;
	Node(int freq) : freq(freq) {}
	Node() {}
};

unordered_set<int> seen;
vector<Node> nodes;
set<pair<int, int>> roadsMustStay;

void dfs(int currNode, vector<int>& path) {
	cerr << currNode << endl;
	seen.insert(currNode);
	for (int i = 0; i < path.size(); i++) {
		if (nodes[i].freq == nodes[currNode].freq) {
			// add up to currNode
			while (i+1 != path.size()) {
				roadsMustStay.insert({path[i], path[i+1]});
			}
			roadsMustStay.insert({path[i], currNode});
			break;
		}
	}
	path.push_back(currNode);
	for (int i : nodes[currNode].neighbors) {
		if (!seen.count(i)) {
			dfs(i, path);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
    	int N;
    	cin >> N;
    	seen.clear();
    	nodes.resize(N);
    	for (int i = 0; i < N-1; i++) {
    		int a, b;
    		cin >> a >> b;
    		nodes[a-1].neighbors.insert(b-1);
    		nodes[b-1].neighbors.insert(a-1);
    	}
    	for (int i = 0; i < N; i++) {
    		cin >> nodes[i].freq;
    	}
    	vector<int> path;
    	dfs(0, path);
    	cout << "Case #" << i << ": " << (N-1 - roadsMustStay.size()) << endl;
    }

	return 0;
}