#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	set<int> s;
    	int n;
    	cin >> n;
    	for (int i = 0; i < n; i++) {
    		int x;
    		cin >> x;
    		if (s.find(x) == s.end()) {
    			s.insert(x);
    		} else {
    			s.insert(-x);
    		}
    	}
    	cout << s.size() << endl;
    }

	return 0;
}