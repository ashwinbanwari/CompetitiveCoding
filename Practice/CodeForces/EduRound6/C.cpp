#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> goodSegments;
    unordered_set<int> seen;
    int startingValue = 0;
    for (int i = 0; i < n; i++) {
    	int currPearl;
    	cin >> currPearl;
    	if (seen.count(currPearl)) {
    		// goodSeegmentReached
    		goodSegments.push_back(make_pair(startingValue, i+1));
    		startingValue = i+1;
    		seen.clear();
    	} else {
    		seen.insert(currPearl);
    	}
    }
    // last segment never reached goodness, merge with last 
    if (goodSegments.size() == 0) {
    	// no good segmnet
    	cout << -1 << endl;
    	return 0;
    }
    goodSegments.back().second = n;
    cout << goodSegments.size() << endl;
    for (int i = 0; i < goodSegments.size(); i++) {
    	cout << goodSegments[i].first+1 << " " << goodSegments[i].second << endl;
    }


	return 0;
}