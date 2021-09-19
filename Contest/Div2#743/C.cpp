#include <bits/stdc++.h>

using namespace std;

long long dfs(int i, vector<int>& iterationNum, vector<unordered_set<int>>& edges, vector<unordered_set<int>>& inEdges, vector<int>& edgesLeft) {
	long long res = iterationNum[i];
	for (int end : edges[i]) {
		edgesLeft[end]--;
		if (edgesLeft[end] == 0) {
			// calc iterationNum
			int maxi {0};
			for (int j : inEdges[end]) {
				assert(iterationNum[j] != -1);
				maxi = max(maxi, iterationNum[j] + (j > end));
				// cerr << end << " requires " << maxi << " from " << j << endl;
			}
			iterationNum[end] = maxi;
			res = max(res, dfs(end, iterationNum, edges, inEdges, edgesLeft));
		}
	}
	// cerr << i << " " << res << endl;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	vector<unordered_set<int>> edges(n);
    	vector<unordered_set<int>> inEdges(n);
    	for (int i = 0; i < n; i++) {
    		int k;
    		cin >> k;
    		int a;
    		for (int j = 0; j < k; j++) {
    			cin >> a;
    			if (a!=0) {
    				edges[a-1].insert(i);
    				inEdges[i].insert(a-1);
    			}
    		}
    	}
    	vector<int> iterationNum(n,-1);
    	vector<int> edgesLeft(n);
    	for (int i = 0; i < n; i++) {
    		edgesLeft[i] = inEdges[i].size();
    	}
    	long long ans = 0;
    	for (int i = 0; i < n; i++) {
    		if (inEdges[i].size() == 0) {
    			iterationNum[i] = 0;
    			ans = max(ans, dfs(i, iterationNum, edges, inEdges, edgesLeft));
    		}
    	}
    	bool bad = false;
    	for (int i = 0; i < n; i++) {
    		if (iterationNum[i] == -1) {
    			cout << -1 << endl;
    			bad = true;
    			break;
    		}
    	}
    	if (!bad) {
    		cout << ans+1 << endl;
    	}
    }

	return 0;
}