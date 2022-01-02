#include <bits/stdc++.h>

using namespace std;


class Node {
public:
	int v, l, r; // -2 is invalid (instead of -1)
	Node(int v, int l, int r) : v(v), l(l), r(r) {}
};

void dfs(int currNode, int minVal, int maxVal, vector<Node>& nodes, set<int>& workingVals) {
	// cerr << currNode << endl;
	if (currNode == -2) {
		return;
	}
	if (minVal <= nodes[currNode].v && maxVal >= nodes[currNode].v) {
		workingVals.insert(nodes[currNode].v);
	}
	
	dfs(nodes[currNode].l, minVal, min(maxVal, nodes[currNode].v), nodes, workingVals);
	dfs(nodes[currNode].r, max(minVal, nodes[currNode].v), maxVal, nodes, workingVals);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
    vector<Node> nodes;
    vector<bool> seen(n);
    for (int i = 0; i < n; i++) {
    	int v, l, r;
    	cin >> v >> l >> r;
    	nodes.push_back(Node(v, l-1, r-1));
    	if (l-1 != -2) 
    	seen[l-1] = true;
    	if (r-1 != -2)
    	seen[r-1] = true;
    }
    int head = min_element(seen.begin(), seen.end()) - seen.begin();
    set<int> workingVals;
    long long ans = 0;
    dfs(head, 0, pow(10,9) + 1, nodes, workingVals);
    for (int i = 0; i < nodes.size(); i++) {
    	if (!workingVals.count(nodes[i].v)) {
    		ans++;
    	}
    }
    cout << ans << endl;

	return 0;
}