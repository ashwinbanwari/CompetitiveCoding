#include <bits/stdc++.h>

using namespace std;


class Node {
public:
	int v, l, r; // -2 is invalid (instead of -1)
	Node(int v, int l, int r) : v(v), l(l), r(r) {}
};

bool find(int currNode, int x, vector<Node>& nodes) {
	// cerr << currNode << endl;
	if (currNode == -2) {
		return false;
	}
	if (nodes[currNode].v == x) {
		return true;
	}
	if (x < nodes[currNode].v) {
		return find(nodes[currNode].l, x, nodes);
	} else {
		return find(nodes[currNode].r, x, nodes);
	}
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
    int ans = 0;
    for (int i = 0; i < nodes.size(); i++) {
    	if (!find(head, nodes[i].v, nodes)) ans++;
    }

    cout << ans << endl;

	return 0;
}