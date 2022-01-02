#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >>  n;
    	vector<int> v(n);
    	for (int i = 0; i < n; i++) {
    		cin >> v[i];
    	}
    	unordered_map<int, vector<int>> indices;
    	for (int i = 0; i < n; i++) {
    		indices[v[i]].push_back(i);
    	}
    	map<int, int> bestK;
    	for (auto& p : indices) {
    		int maxDiff = 0;
    		int last = -1;
    		for (int i : p.second) {
    			int diff = i - last;
    			maxDiff = max(maxDiff, diff);
    			last = i; 
    		}
    		maxDiff = max(maxDiff, n-last);
    		bestK[p.first] = maxDiff;
    	}
    	vector<int> answers(n, -1);
    	int finishedIdx = n;
    	for (auto& p : bestK) {
    		int goodk = p.second-1;
    		for (int i = goodk; i < finishedIdx; i++) {
    			answers[i] = p.first;
    		}
    		finishedIdx = min(finishedIdx, goodk);
    	}
    	for (int i : answers) {
    		cout << i << " ";
    	}
    	cout << endl;
    }

	return 0;
}