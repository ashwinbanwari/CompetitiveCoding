#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
		// cerr << "NEW " << endl;
    	int n,m;
    	cin >> n >> m;
    	vector<pair<int, int>> sight(n*m);
    	for (int i = 0; i < n*m; i++) {
    		cin >> sight[i].first;
    		sight[i].second =  i;
    	}
    	sort(sight.begin(), sight.end());
    	/*for (int i = 0; i < n*m; i++) {
    		cerr << "IDX: " << sight[i].second;
    		cerr << " SIGHT:" << sight[i].first << endl;
    	}*/
 
    	int result = 0;
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			int currIdx = i*m + j;
    			int row = i;
    			for (int k = row*m; k < (i+1)*m; k++) {
    				// cerr << "POSITION " <<  k << endl;
    				auto& p = sight[k];
    				if (sight[currIdx].second > p.second && sight[currIdx].first > p.first) {
    					// cerr << sight[currIdx].second << " index > " << p.second << ", " << sight[currIdx].first << " sight > " << p.first << endl;
    					result++;
    				}
    			}
    		}
    	}
    	cout << result << endl;
    }
 
	return 0;
}