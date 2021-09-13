#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n,m;
    	cin >> n >> m;
    	vector<int> sight(n*m);
    	for (int i = 0; i < n*m; i++) {
    		cin >> sight[i];
    	}
    	int result = 0;
    	for (int i = 0; i < n*m; i++) {
    		for (int j = 0; j < i; j++) {
    			// cerr << sight[i] << " > " << sight[j] << endl;
    			if (sight[i] > sight[j]) {
    				result++;
    			}
    		}
    	}
    	cout << result << endl;
    }

	return 0;
}