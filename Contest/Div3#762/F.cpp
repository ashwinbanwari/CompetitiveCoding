#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n, m, k;
    	cin >> n >> m >> k;
    	int per = n/m;
    	deque<int> q;
    	for (int i = 1; i <= n; i++) {
    		q.push_back(i);
    	}
    	for (int i = 0; i < k; i++) {
    		// each game
    		int tablesLeft = m;
    		int a;
    		unordered_set<int> unused(q.begin(), q.end());
    		for (a = n; a > per*tablesLeft; a -= (per+1)) {
    			// cerr << a << ", " << per*tablesLeft << endl;
    			cout << per+1 << " ";
    			for (int j = 0; j < per+1; j++) {
    				int next = q.front();
    				q.pop_front();
    				q.push_back(next);
    				unused.erase(next);
    				cout << next << " ";
    			}
    			cout << endl;
    			tablesLeft--;
    		}
    		for (;a >= 1; a -= per) {
    			cout << per << " ";
    			for (int j = 0; j < per; j++) {
    				int next = *unused.begin();
    				unused.erase(next);
    				cout << next << " ";
    			}
    			cout << endl;
    		}

    	}
    	cout << endl;
    }

	return 0;
}