#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;
    stack<int> stk;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
    	switch(s[i]) {
    		case '[':
    		case '(':
    		case '<':
    		case '{':
    			stk.push(s[i]);
    			break;
    		default:
    			if (stk.empty()) {
    				cout << "Impossible" << endl;
    				return 0;
    			}
    			char opening = stk.top();
    			stk.pop();
    			if (abs(opening - s[i]) > 2) {
    				ans++;
    			}
    			break;
    	}
    }
    if (!stk.empty()) {
    	cout << "Impossible" << endl;
    	return 0;
    }
    cout << ans << endl;


	return 0;
}